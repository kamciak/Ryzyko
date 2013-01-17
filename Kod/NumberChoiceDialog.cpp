///-----------------------------------------------------------------
///
/// @file      NumberChoiceDialog.cpp
/// @author    Kamciak
/// Created:   2013-01-14 23:55:43
/// @section   DESCRIPTION
///            NumberChoiceDialog class implementation
///
///------------------------------------------------------------------

#include "NumberChoiceDialog.h"
#include "SoundController.h"
#include <wx/dcbuffer.h>
//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// NumberChoiceDialog
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(NumberChoiceDialog,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(NumberChoiceDialog::OnClose)
	EVT_BUTTON(ID_WXBITMAPBUTTON2,NumberChoiceDialog::WxBitmapButton2Click)
	EVT_BUTTON(ID_WXBITMAPBUTTON1,NumberChoiceDialog::WxBitmapButton1Click)
	EVT_SPINCTRL(ID_WXSPINCTRL1,NumberChoiceDialog::WxSpinCtrl1Updated)
	
	EVT_UPDATE_UI(ID_WXPANEL1,NumberChoiceDialog::WxPanel1UpdateUI)
END_EVENT_TABLE()
////Event Table End

NumberChoiceDialog::NumberChoiceDialog(Controller & ctrl, unsigned min, unsigned max, unsigned start_region, unsigned end_region, bool optional, wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style), ctrl(ctrl)
{
    _optional = optional;
    this->min=min;
    this->max=max;
    this->start_region=start_region;
    this->end_region=end_region;
	CreateGUIControls();
    if(!_optional){
        WxBitmapButton2->Disable();
    }
}

NumberChoiceDialog::~NumberChoiceDialog()
{
} 

void NumberChoiceDialog::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	wxInitAllImageHandlers();   //Initialize graphic format handlers

	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(0, 0), wxSize(200, 315));

	WxSpinCtrl1 = new wxSpinCtrl(WxPanel1, ID_WXSPINCTRL1, _("0"), wxPoint(53, 126), wxSize(72, 26), wxSP_ARROW_KEYS, 0, 100, 0);

	wxBitmap WxBitmapButton1_BITMAP (_("Images/ok.jpg"), wxBITMAP_TYPE_JPEG);
	WxBitmapButton1 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON1, WxBitmapButton1_BITMAP, wxPoint(38, 230), wxSize(30, 25), wxBU_AUTODRAW, wxDefaultValidator, _("WxBitmapButton1"));

	wxBitmap WxBitmapButton2_BITMAP (_("Images/anuluj.jpg"), wxBITMAP_TYPE_JPEG);
	WxBitmapButton2 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON2, WxBitmapButton2_BITMAP, wxPoint(99, 230), wxSize(63, 25), wxBU_AUTODRAW, wxDefaultValidator, _("WxBitmapButton2"));

	SetTitle(_("NumberChoiceDialog"));
	SetIcon(wxNullIcon);
	SetSize(8,8,200,315);
	Center();
	
	////GUI Items Creation End

    WxSpinCtrl1->Reparent(WxPanel1);
    WxSpinCtrl1->SetRange(min,max);
    
    
    wxImage okHover("Images/ok_hover.jpg");
	wxBitmap ok_hover(okHover);
	WxBitmapButton1->SetBitmapHover(ok_hover);
    WxBitmapButton1->Reparent(WxPanel1);	
    WxBitmapButton1->SetDoubleBuffered(true);
    
    wxImage anulujHover("Images/anuluj_hover.jpg");
	wxBitmap anuluj_hover(anulujHover);
	
	wxImage anulujDisable("Images/anuluj_disable.jpg");
	wxBitmap anuluj_disable(anulujDisable);
	
	WxBitmapButton2->SetBitmapDisabled(anuluj_disable);
	WxBitmapButton2->SetBitmapHover(anuluj_hover);
    WxBitmapButton2->Reparent(WxPanel1);	
    WxBitmapButton2->SetDoubleBuffered(true);

    WxSpinCtrl1->SetValue(max);
      
}

void NumberChoiceDialog::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}

/*
 * WxPanel1UpdateUI
 */
void NumberChoiceDialog::WxPanel1UpdateUI(wxUpdateUIEvent& event)
{
	wxImage image("Images/scroll.jpg");
	wxBitmap tlo(image);
	wxClientDC dc(WxPanel1);
	wxBufferedDC bdc(&dc);
	bdc.DrawBitmap(tlo,0,0,true);
}

/*
 * WxSpinCtrl1Updated
 */
void NumberChoiceDialog::WxSpinCtrl1Updated(wxSpinEvent& event )
{
	// insert your code here
}

/*
 * WxBitmapButton2Click
 */
void NumberChoiceDialog::WxBitmapButton2Click(wxCommandEvent& event)
{
	this->EndModal(0);
}

/*
 * WxBitmapButton1Click
 */
void NumberChoiceDialog::WxBitmapButton1Click(wxCommandEvent& event)
{
    SoundController::playSound(ARMY_MARCH);
	ctrl.moveArmies(start_region,end_region,WxSpinCtrl1->GetValue());    
    this->EndModal(0);
}
