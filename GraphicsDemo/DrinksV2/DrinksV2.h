#ifndef _DrinksV2_DrinksV2_h
#define _DrinksV2_DrinksV2_h

#include <CtrlLib/CtrlLib.h>

using namespace Upp;

#define LAYOUTFILE <DrinksV2/DrinksV2.lay>
#include <CtrlCore/lay.h>
#include <AutoScroller/AutoScroller.h>
#include "drink.h"

class DrinksV2 : public WithMainAppWindow<TopWindow> {
public:
	DrinksV2();
private:
	AutoScroller scroller;
	WithDrinksV2Layout<ParentCtrl> scroller_view;
	Option flavor[NUM_FLAV];
};

#endif
