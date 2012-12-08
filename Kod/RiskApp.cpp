//---------------------------------------------------------------------------
//
// Name:        RiskApp.cpp
// Author:      Piotrek
// Created:     2012-10-19 20:31:21
// Description: 
//
//---------------------------------------------------------------------------

#include "RiskApp.h"
#include "RiskFrm.h"

IMPLEMENT_APP(RiskFrmApp)

bool RiskFrmApp::OnInit()
{
    RiskFrm* frame = new RiskFrm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int RiskFrmApp::OnExit()
{
	return 0;
}
