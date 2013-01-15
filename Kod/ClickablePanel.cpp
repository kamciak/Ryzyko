#include "ClickablePanel.h"
#include "RiskFrm.h"
#include "NumberChoiceDialog.h"

BEGIN_EVENT_TABLE(ClickablePanel,wxPanel)
	////Manual Code Start
    EVT_LEFT_DOWN(ClickablePanel::mouseLeftClick)
    EVT_BUTTON(2498, ClickablePanel::end_phase_bmpButtonClicked)
	////Manual Code End
		
END_EVENT_TABLE()


ClickablePanel::ClickablePanel(RiskFrm* parent, Controller & control, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) 
        : wxPanel(parent,id,pos,size,style,name), _controller(control), _parent(*parent){
    double scale = parent->getScale();
    //info_box = new wxTextCtrl(this,2499,"",wxPoint(0*scale,0*scale),wxSize(495*scale,105*scale),wxTE_READONLY | wxTE_MULTILINE);

    wxImage *end_phase_img = new wxImage("Images/koniec_tury.jpg");
    wxBitmap *end_phase_bmp = new wxBitmap(*end_phase_img);
    
    end_phase_btn = new wxBitmapButton(this,2498,*end_phase_bmp,wxPoint(0,0),end_phase_bmp->GetSize(),wxNO_BORDER);

    wxImage *end_phase_img_hover = new wxImage("Images/koniec_tury_hover.jpg");
    wxBitmap *end_phase_bmp_hover = new wxBitmap(*end_phase_img_hover);
    end_phase_btn -> SetBitmapHover(*end_phase_bmp_hover);
    
    wxImage *end_phase_img_disabled = new wxImage("Images/koniec_tury_disabled.jpg");
    wxBitmap *end_phase_bmp_disabled = new wxBitmap(*end_phase_img_disabled);
    end_phase_btn -> SetBitmapDisabled(*end_phase_bmp_disabled);

    end_phase_btn -> Hide();
    
}

void ClickablePanel::mouseLeftClick(wxMouseEvent & event){
    wxPoint pt = event.GetPosition();    
    unsigned int region_id = _parent.getRegionID(pt.x,pt.y);
    if(region_id != NO_REGION_SELECTED)
        _controller.regionClicked(_parent.getRegionID(pt.x,pt.y));
}

void ClickablePanel::end_phase_bmpButtonClicked(wxCommandEvent & event){
    _controller.nextPhase();
}
