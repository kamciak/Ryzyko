///-----------------------------------------------------------------
///
/// @file      MenuDlg.h
/// @author    Kamciak
/// Created:   2012-12-04 01:56:54
/// @section   DESCRIPTION
///            MenuDlg class declaration
///
///------------------------------------------------------------------

#ifndef __MENUDLG_H__
#define __MENUDLG_H__

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
#include <wx/bmpcbox.h>
#include <wx/textctrl.h>
#include <wx/bmpbuttn.h>
#include <wx/panel.h>
////Header Include End

////Dialog Style Start
#undef MenuDlg_STYLE
#define MenuDlg_STYLE wxSYSTEM_MENU | wxDIALOG_NO_PARENT | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End
class RiskFrm;
class Controller;

class MenuDlg : public wxDialog
{
    friend class Controller;
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		MenuDlg(wxWindow *parent, Controller & control, wxWindowID id = 1, const wxString &title = wxT("MenuDlg"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = MenuDlg_STYLE);
		void WxBitmapButton1Click(wxCommandEvent& event);
		virtual ~MenuDlg();
		void WxPanel1UpdateUI(wxUpdateUIEvent& event);
		void WxButton1Click(wxCommandEvent& event);
		void WxBitmapComboBox1Selected(wxCommandEvent& event );
		void WxEdit4Updated(wxCommandEvent& event);
	
		void WxBitmapButton2Click(wxCommandEvent& event);
		void WxBitmapButton6Click(wxCommandEvent& event);
		void WxBitmapButton7Click(wxCommandEvent& event);
		void WxBitmapButton8Click(wxCommandEvent& event);
		void WxEdit1Updated(wxCommandEvent& event);
		void WxBitmapButton3Click(wxCommandEvent& event);
	private:
		void WxBitmapButton5Click(wxCommandEvent& event);
		//Do not add custom control declarations between 
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxBitmapButton *WxBitmapButton8;
		wxBitmapButton *WxBitmapButton7;
		wxBitmapButton *WxBitmapButton6;
		wxBitmapButton *WxBitmapButton5;
		wxBitmapButton *WxBitmapButton4;
		wxBitmapButton *WxBitmapButton3;
		wxBitmapButton *WxBitmapButton2;
		wxBitmapComboBox *WxBitmapComboBox6;
		wxBitmapComboBox *WxBitmapComboBox5;
		wxBitmapComboBox *WxBitmapComboBox4;
		wxBitmapComboBox *WxBitmapComboBox3;
		wxBitmapComboBox *WxBitmapComboBox2;
		wxBitmapComboBox *WxBitmapComboBox1;
		wxTextCtrl *WxEdit6;
		wxTextCtrl *WxEdit5;
		wxTextCtrl *WxEdit4;
		wxTextCtrl *WxEdit3;
		wxTextCtrl *WxEdit2;
		wxTextCtrl *WxEdit1;
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
			ID_WXBITMAPBUTTON8 = 1036,
			ID_WXBITMAPBUTTON7 = 1035,
			ID_WXBITMAPBUTTON6 = 1034,
			ID_WXBITMAPBUTTON5 = 1033,
			ID_WXBITMAPBUTTON4 = 1032,
			ID_WXBITMAPBUTTON3 = 1031,
			ID_WXBITMAPBUTTON2 = 1030,
			ID_WXBITMAPCOMBOBOX6 = 1029,
			ID_WXBITMAPCOMBOBOX5 = 1028,
			ID_WXBITMAPCOMBOBOX4 = 1027,
			ID_WXBITMAPCOMBOBOX3 = 1026,
			ID_WXBITMAPCOMBOBOX2 = 1025,
			ID_WXBITMAPCOMBOBOX1 = 1024,
			ID_WXEDIT6 = 1023,
			ID_WXEDIT5 = 1022,
			ID_WXEDIT4 = 1021,
			ID_WXEDIT3 = 1020,
			ID_WXEDIT2 = 1019,
			ID_WXEDIT1 = 1018,
			ID_WXBITMAPBUTTON1 = 1003,
			ID_WXPANEL1 = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
	
	private:        
        bool isPlayer3;
        bool isPlayer4;
        bool isPlayer5;
        bool isPlayer6;
        wxImage * imgCheckBoxTrue;
	    wxBitmap * bitmapCheckBoxTrue;
	    wxImage * imgCheckBoxFalse;
	    wxBitmap * bitmapCheckBoxFalse;
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
        RiskFrm *_parent;
        Controller & _controller;
};

    


#endif
