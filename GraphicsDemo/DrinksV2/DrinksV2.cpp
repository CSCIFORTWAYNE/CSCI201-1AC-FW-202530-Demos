#include "DrinksV2.h"

//todo option button events
//todo new widgets
//todo button events
//todo destructor


DrinksV2::DrinksV2()
{
	theDrink = nullptr;
	numFlav = 0;
	CtrlLayout(*this, "Drink Order Form");
	Sizeable().Zoomable();
	scroller.EnableScroll();
	Add(scroller.SizePos());
	CtrlLayout(scroller_view);
	scroller.AddPane(scroller_view);
	
	scroller_view.base = -1;
	scroller_view.temp = -1;
	scroller_view.size = -1;
	
	for(int i = 0; i < NUM_DAIRY; i++)
	{
		scroller_view.dairy.Add(dairyStr[i]);
	}
	scroller_view.dairy.GoBegin();
	
	int optionSize = 100;
	int rowDist = 20;
	int rowCount = 0;
	int i = 0;
	for(std::map<flavType, std::string>::iterator it = drink::flavToStr.begin(); it != drink::flavToStr.end(); ++it)
	{
		flavor[i].SetLabel(it->second.c_str());
		scroller_view.flavorOptions.Add(flavor[i].LeftPosZ(optionSize*(i%2),
		optionSize).TopPosZ(rowDist*rowCount));
		if(i%2 == 1)
		{
			rowCount++;
		}
		flavor[i] << [&, this, i]
		{
			handleFlavor(i);
		};
		i++;
	}
	
	scroller_view.base << [&, this]
	{
		b = drink::intToBase[(int)scroller_view.base];
		if(theDrink != nullptr)
		{
			theDrink->setBase(b);
		}
		checkPrice();
	};
	
	scroller_view.temp << [&, this]
	{
		t = drink::intToTemp[(int)scroller_view.temp];
		if(theDrink != nullptr)
		{
			theDrink->setTemperature(t);
		}
		checkPrice();
	};
	
	scroller_view.size << [&, this]
	{
		s = drink::intToSize[scroller_view.size.GetData()];
		if(theDrink != nullptr)
		{
			theDrink->setSize(s);
		}
		checkPrice();
	};
	
	scroller_view.dairy << [&, this]
	{
		dairy = scroller_view.dairy.GetData().ToStd();
		if(theDrink != nullptr)
		{
			theDrink->setDairy(dairy);
		}
		checkPrice();
	};
}

void DrinksV2::checkPrice()
{
	if((int)scroller_view.base != -1 && (int)scroller_view.temp != -1 && (int)scroller_view.size != -1)
	{
		if(theDrink == nullptr)
		{
			dairy = scroller_view.dairy.GetData().ToStd();
			theDrink = new drink(b, t, s, dairy);
		}
		if(numFlav != theDrink->getNumFlavor())
		{
			theDrink->removeAllFlavor();
			for(int i = 0; i < NUM_FLAV && theDrink->getNumFlavor() != numFlav; i++)
			{
				if(flavor[i].Get())
				{
					std::string flavStr = flavor[i].GetLabel().ToStd();
					std::transform(flavStr.begin(), flavStr.end(), flavStr.begin(), ::tolower);
					theDrink->addFlavor(drink::strToFlav[flavStr]);
				}
				
			}
		}
		std::ostringstream priceStr;
		priceStr << std::setprecision(2) << std::fixed << std::showpoint;
		priceStr << "$" << theDrink->getPrice();
		scroller_view.price.SetData(priceStr.str());
	}
}

void DrinksV2::handleFlavor(int i)
{

	if(theDrink != nullptr)
	{
		std::string flavStr = flavor[i].GetLabel().ToStd();
		std::transform(flavStr.begin(), flavStr.end(), flavStr.begin(), ::tolower);
		if(flavor[i].Get())
		{
			theDrink->addFlavor(drink::strToFlav[flavStr]);
			numFlav++;
		}
		else
		{
			theDrink->removeFlavor(drink::strToFlav[flavStr]);
			numFlav--;
		}
	}
	else
	{
		if(flavor[i].Get())
		{
			numFlav++;
		}
		else
		{
			numFlav--;
		}
	}
	checkPrice();
}

DrinksV2::~DrinksV2()
{
}