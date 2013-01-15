///-----------------------------------------------------------------
///
/// @file      CardDialog.cpp
/// @author    Kamciak
/// Created:   2013-01-15 23:32:00
/// @section   DESCRIPTION
///            CardDialog class implementation
///
///------------------------------------------------------------------

#include "CardDialog.h"
#include <wx/dcbuffer.h>
//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// CardDialog
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(CardDialog,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(CardDialog::OnClose)
	EVT_BUTTON(ID_WXBITMAPBUTTON1,CardDialog::WxBitmapButton1Click)
	
	EVT_UPDATE_UI(ID_WXPANEL1,CardDialog::WxPanel1UpdateUI)
END_EVENT_TABLE()
////Event Table End

CardDialog::CardDialog(Controller & ctrl, wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style), ctrl(ctrl)
{
	CreateGUIControls();
}

CardDialog::~CardDialog()
{
    
} 

void CardDialog::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	wxInitAllImageHandlers();   //Initialize graphic format handlers

	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(0, 0), wxSize(800, 400));

	wxBitmap WxBitmapButton1_BITMAP (_("Images/zakoncz.jpg"), wxBITMAP_TYPE_JPEG);
	WxBitmapButton1 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON1, WxBitmapButton1_BITMAP, wxPoint(341, 350), wxSize(122, 31), wxBU_AUTODRAW, wxDefaultValidator, _("WxBitmapButton1"));

	SetTitle(_("CardDialog"));
	SetIcon(wxNullIcon);
	SetSize(8,8,800,400);
	Center();
	
	////GUI Items Creation End
	
	
    wxImage zamknijHover("Images/zakoncz_hover.jpg");
	wxBitmap zamknij_hover(zamknijHover);
	WxBitmapButton1->SetBitmapHover(zamknij_hover);
    WxBitmapButton1->Reparent(WxPanel1);	
    WxBitmapButton1->SetDoubleBuffered(true);
	
}

void CardDialog::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}

/*
 * WxPanel1UpdateUI
 */
void CardDialog::WxPanel1UpdateUI(wxUpdateUIEvent& event)
{
	wxImage image("Images/card_dialog.jpg");
	wxBitmap tlo(image);
	wxClientDC dc(WxPanel1);
	wxBufferedDC bdc(&dc);
	bdc.DrawBitmap(tlo,0,0,true);
}

/*
 * WxBitmapButton1Click
 */
void CardDialog::WxBitmapButton1Click(wxCommandEvent& event)
{
	this->EndModal(0);
}
