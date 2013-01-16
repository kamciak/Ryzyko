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
#include "Util.h"

unsigned int CardDialog::set_values[] = {4,6,8,10,12,15,20,25,30,35,40,45,50,55,60,65,70};

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
	EVT_BUTTON(ID_WXBITMAPBUTTON3,CardDialog::WxBitmapButton3Click)
	EVT_BUTTON(ID_WXBITMAPBUTTON2,CardDialog::WxBitmapButton2Click)
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
	WxBitmapButton1 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON1, WxBitmapButton1_BITMAP, wxPoint(320, 328), wxSize(114, 29), wxBU_AUTODRAW, wxDefaultValidator, _("WxBitmapButton1"));

	wxBitmap WxBitmapButton2_BITMAP (wxNullBitmap);
	WxBitmapButton2 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON2, WxBitmapButton2_BITMAP, wxPoint(98, 280), wxSize(258, 27), wxBU_AUTODRAW, wxDefaultValidator, _("WxBitmapButton2"));

	wxBitmap WxBitmapButton3_BITMAP (wxNullBitmap);
	WxBitmapButton3 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON3, WxBitmapButton3_BITMAP, wxPoint(394, 280), wxSize(258, 27), wxBU_AUTODRAW, wxDefaultValidator, _("WxBitmapButton3"));

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
    
    WxBitmapButton2->SetBitmapLabel(wxImage("Images/wymien_jedn.jpg"));
    WxBitmapButton2->SetBitmapHover(wxImage("Images/wymien_jedn_hover.jpg"));
    WxBitmapButton2->Reparent(WxPanel1);	
    WxBitmapButton2->SetDoubleBuffered(true);

    WxBitmapButton3->SetBitmapLabel(wxImage("Images/wymien_rozn.jpg"));
    WxBitmapButton3->SetBitmapHover(wxImage("Images/wymien_rozn_hover.jpg"));
    WxBitmapButton3->Reparent(WxPanel1);	
    WxBitmapButton3->SetDoubleBuffered(true);
    
    if(ctrl.mustExchange())
        WxBitmapButton1->Disable();
    if(!ctrl.hasThreeOfAKind())
        WxBitmapButton2->Disable();
    if(!ctrl.hasThreeDifferent())
        WxBitmapButton3->Disable();
	
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
    std::vector<CardDrawInfo> draw_info = ctrl.getCardDrawInfo();
    
	wxImage image("Images/card_dialog.jpg");
	wxBitmap tlo(image);
	wxClientDC dc(WxPanel1);
	wxBufferedDC bdc(&dc);

    
    
	bdc.DrawBitmap(tlo,0,0,true);

    for(int i = 0; i < draw_info.size(); ++i){
        wxPoint pos(10+i*155,10);
        bdc.DrawBitmap(*draw_info[i].image,pos,true);        
        bdc.DrawText(draw_info[i].region_name,pos.x+50,pos.y+225);
        bdc.DrawText("Wartosc kolejnego zestawu kart ryzyka: "+intToString(set_values[ctrl.exchangedSets()]), 270, 260);
    }   
}

/*
 * WxBitmapButton1Click
 */
void CardDialog::WxBitmapButton1Click(wxCommandEvent& event)
{    
	EndModal(0);
}



/*
 * WxBitmapButton2Click
 */
void CardDialog::WxBitmapButton2Click(wxCommandEvent& event)
{
	ctrl.exchangeSame();
    EndModal(0);
}


/*
 * WxBitmapButton3Click
 */
void CardDialog::WxBitmapButton3Click(wxCommandEvent& event)
{
	ctrl.exchangeDifferent();
    EndModal(0);
}
