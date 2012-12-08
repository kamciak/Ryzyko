//---------------------------------------------------------------------------
//
// Name:        RiskApp.h
// Author:      Piotrek
// Created:     2012-10-19 20:31:21
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __RISKFRMApp_h__
#define __RISKFRMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class RiskFrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
