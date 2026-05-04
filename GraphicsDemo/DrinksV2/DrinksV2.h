#ifndef _DrinksV2_DrinksV2_h
#define _DrinksV2_DrinksV2_h

#include <CtrlLib/CtrlLib.h>

using namespace Upp;

#define LAYOUTFILE <DrinksV2/DrinksV2.lay>
#include <CtrlCore/lay.h>
#include <AutoScroller/AutoScroller.h>
#include <vector>
#include <sstream>
#include <iomanip>
#include "drink.h"

class DrinksV2 : public WithMainAppWindow<TopWindow> {
public:
	DrinksV2();
	void checkPrice();
	void handleFlavor(int i);
	void saveOrder();
	~DrinksV2();
private:
	AutoScroller scroller;
	WithDrinksV2Layout<ParentCtrl> scroller_view;
	Option flavor[NUM_FLAV];
	drink * theDrink;
	std::vector<drink *> order;
	baseType b;
	tempType t;
	sizeType s;
	std::string dairy;
	int numFlav;
};

#endif
