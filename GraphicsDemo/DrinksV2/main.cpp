#include "DrinksV2.h"

DrinksV2::DrinksV2()
{
	CtrlLayout(*this, "Window title");
}

GUI_APP_MAIN
{
	DrinksV2().Run();
}
