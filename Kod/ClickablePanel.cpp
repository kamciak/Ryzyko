#include "ClickablePanel.h"

BEGIN_EVENT_TABLE(ClickablePanel,wxPanel)
	////Manual Code Start
    EVT_LEFT_DOWN(ClickablePanel::mouseLeftClick)
	////Manual Code End
		
END_EVENT_TABLE()
