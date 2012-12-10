///-----------------------------------------------------------------
///
/// @file      RiskFrm.h
/// @author    Piotrek
/// Created:   2012-10-19 20:31:21
/// @section   DESCRIPTION
///            RiskFrm class declaration
///
///------------------------------------------------------------------

#ifndef __RISKFRM_H__
#define __RISKFRM_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/stattext.h>
#include <wx/panel.h>
#include <wx/sizer.h>
////Header Include End

////Dialog Style Start
#undef RiskFrm_STYLE
#define RiskFrm_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End
#include "MenuDlg.h"
#include "Controller.h"
#include "PlayersData.h"
#include "Board.h"
class RiskFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		RiskFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Risk"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = RiskFrm_STYLE);
		virtual ~RiskFrm();
		void WxPanel1UpdateUI(wxUpdateUIEvent& event);
        
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxStaticText *DebugText;
		wxPanel *WxPanel1;
		wxBoxSizer *WxBoxSizer1;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_DEBUGTEXT = 1003,
			ID_WXPANEL1 = 1002,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
		MenuDlg *menu;
        wxImage *map;
        wxImage *mask;
        wxImage *map_with_mask;
        wxClientDC *_dc;
        void mouseLeftClicl();
        Controller control;
    public:
        void mouseLeftClick(wxMouseEvent & event);
        void setResolution(unsigned int id);
        void paintSelectedRegion(unsigned int id);
};

#endif
