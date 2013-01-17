///-----------------------------------------------------------------
///
/// @file      StatusDialog.cpp
/// @author    Kamciak
/// Created:   2013-01-17 20:42:44
/// @section   DESCRIPTION
///            StatusDialog class implementation
///
///------------------------------------------------------------------

#include "StatusDialog.h"
#include <wx/dcbuffer.h>

#define VICTORY true
#define DEFEAT false
//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// StatusDialog
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(StatusDialog,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(StatusDialog::OnClose)
	EVT_BUTTON(ID_WXBITMAPBUTTON1,StatusDialog::WxBitmapButton1Click)
	
	EVT_UPDATE_UI(ID_WXPANEL1,StatusDialog::WxPanel1UpdateUI)
END_EVENT_TABLE()
////Event Table End

StatusDialog::StatusDialog(bool status, wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style), _status(status)
{
	CreateGUIControls();
}

StatusDialog::~StatusDialog()
{
} 

void StatusDialog::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	wxInitAllImageHandlers();   //Initialize graphic format handlers

	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(0, 0), wxSize(400, 320));

	wxBitmap WxBitmapButton1_BITMAP (_("Images/zamknij_gracz.png"), wxBITMAP_TYPE_PNG);
	WxBitmapButton1 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON1, WxBitmapButton1_BITMAP, wxPoint(167, 235), wxSize(69, 24), wxBU_AUTODRAW, wxDefaultValidator, _("WxBitmapButton1"));

	SetTitle(_("StatusDialog"));
	SetIcon(wxNullIcon);
	SetSize(8,8,400,320);
	Center();
	
	////GUI Items Creation End
	
	wxImage zamknijHover("Images/zamknij_gracz_hover.png");
	wxBitmap zamknij_hover(zamknijHover);
	WxBitmapButton1->SetBitmapHover(zamknij_hover);
    WxBitmapButton1->Reparent(WxPanel1);	
    WxBitmapButton1->SetDoubleBuffered(true);
}

void StatusDialog::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}

/*
 * WxPanel1UpdateUI
 */
void StatusDialog::WxPanel1UpdateUI(wxUpdateUIEvent& event)
{
    if(_status==VICTORY){
	   wxImage image("Images/victory_background.png");
	   wxBitmap tlo(image);
	   wxClientDC dc(WxPanel1);
	   wxBufferedDC bdc(&dc);
	   bdc.DrawBitmap(tlo,0,0,true);
    }
    else{    
    	wxImage image("Images/defeated_background.png");
    	wxBitmap tlo(image);
    	wxClientDC dc(WxPanel1);
    	wxBufferedDC bdc(&dc);
    	bdc.DrawBitmap(tlo,0,0,true);
    }
}

/*
 * WxBitmapButton1Click
 */
void StatusDialog::WxBitmapButton1Click(wxCommandEvent& event)
{
	this->EndModal(0);
}
