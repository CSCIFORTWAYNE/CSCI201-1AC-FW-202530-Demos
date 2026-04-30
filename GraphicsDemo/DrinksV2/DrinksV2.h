#ifndef _DrinksV2_DrinksV2_h
#define _DrinksV2_DrinksV2_h

#include <CtrlLib/CtrlLib.h>

using namespace Upp;

#define LAYOUTFILE <DrinksV2/DrinksV2.lay>
#include <CtrlCore/lay.h>

class DrinksV2 : public WithDrinksV2Layout<TopWindow> {
public:
	DrinksV2();
};

#endif
