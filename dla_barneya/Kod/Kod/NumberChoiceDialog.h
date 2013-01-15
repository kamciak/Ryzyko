///-----------------------------------------------------------------
///
/// @file      NumberChoiceDialog.h
/// @author    Kamciak
/// Created:   2013-01-14 23:55:43
/// @section   DESCRIPTION
///            NumberChoiceDialog class declaration
///
///------------------------------------------------------------------

#ifndef __NUMBERCHOICEDIALOG_H__
#define __NUMBERCHOICEDIALOG_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/dialog.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/bmpbuttn.h>
#include <wx/spinctrl.h>
#include <wx/panel.h>
////Header Include End

////Dialog Style Start
#undef NumberChoiceDialog_STYLE
#define NumberChoiceDialog_STYLE wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End
#include "Controller.h"
class NumberChoiceDialog : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		NumberChoiceDialog(Controller & ctrl, unsigned min, unsigned max, unsigned start_region, unsigned end_region, wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("NumberChoiceDialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = NumberChoiceDialog_STYLE);
		virtual ~NumberChoiceDialog();
		void WxPanel1UpdateUI(wxUpdateUIEvent& event);
		void WxBitmapButton2Click(wxCommandEvent& event);
		void WxSpinCtrl1Updated(wxSpinEvent& event );
	
	private:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxBitmapButton *WxBitmapButton2;
		wxBitmapButton *WxBitmapButton1;
		wxSpinCtrl *WxSpinCtrl1;
		wxPanel *WxPanel1;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXBITMAPBUTTON2 = 1004,
			ID_WXBITMAPBUTTON1 = 1003,
			ID_WXSPINCTRL1 = 1002,
			ID_WXPANEL1 = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
        Controller & ctrl;
        unsigned min, max, start_region, end_region;
        
        
    private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
