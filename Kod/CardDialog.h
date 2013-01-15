///-----------------------------------------------------------------
///
/// @file      CardDialog.h
/// @author    Kamciak
/// Created:   2013-01-15 23:32:00
/// @section   DESCRIPTION
///            CardDialog class declaration
///
///------------------------------------------------------------------

#ifndef __CARDDIALOG_H__
#define __CARDDIALOG_H__

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
#include <wx/panel.h>
////Header Include End

////Dialog Style Start
#undef CardDialog_STYLE
#define CardDialog_STYLE wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End
#include "Controller.h"
class CardDialog : public wxDialog
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		CardDialog(Controller & ctrl, wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("CardDialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = CardDialog_STYLE);
		virtual ~CardDialog();
		void WxPanel1UpdateUI(wxUpdateUIEvent& event);
		void WxBitmapButton1Click(wxCommandEvent& event);
	
	private:
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxBitmapButton *WxBitmapButton1;
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
			ID_WXBITMAPBUTTON1 = 1002,
			ID_WXPANEL1 = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:
        Controller & ctrl;
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
