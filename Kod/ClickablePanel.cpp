#include "ClickablePanel.h"
#include "RiskFrm.h"

BEGIN_EVENT_TABLE(ClickablePanel,wxPanel)
	////Manual Code Start
    EVT_LEFT_DOWN(ClickablePanel::mouseLeftClick)
    EVT_BUTTON(2498, ClickablePanel::end_phase_bmpButtonClicked)
	////Manual Code End
		
END_EVENT_TABLE()


ClickablePanel::ClickablePanel(RiskFrm* parent, Controller & control, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) 
        : wxPanel(parent,id,pos,size,style,name), _controller(control), _parent(*parent){
    double scale = parent->getScale();
    info_box = new wxTextCtrl(this,2499,"",wxPoint(0*scale,0*scale),wxSize(495*scale,105*scale),wxTE_READONLY | wxTE_MULTILINE);
    wxImage::AddHandler( new wxPNGHandler );
    wxImage *end_phase_img = new wxImage("Images/end_turn.png");
    wxBitmap *end_phase_bmp = new wxBitmap(*end_phase_img);
    end_phase_btn = new wxBitmapButton(this,2498,*end_phase_bmp,wxPoint(0,0),wxSize(80,30));
    end_phase_btn -> Hide();
    end_phase_btn -> SetDoubleBuffered(true);
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
