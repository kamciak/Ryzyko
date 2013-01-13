#include "ClickablePanel.h"
#include "RiskFrm.h"

BEGIN_EVENT_TABLE(ClickablePanel,wxPanel)
	////Manual Code Start
    EVT_LEFT_DOWN(ClickablePanel::mouseLeftClick)
	////Manual Code End
		
END_EVENT_TABLE()


ClickablePanel::ClickablePanel(RiskFrm* parent, Controller & control, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name) 
        : wxPanel(parent,id,pos,size,style,name), _controller(control), _parent(*parent){
    wxSize s = this->GetSize();    
    unsigned int width = s.GetWidth();
    double scale = width/1366.0;
    info_box = new wxTextCtrl(this,2499,"",wxPoint(520*scale,642*scale),wxSize(495*scale,105*scale),wxTE_READONLY | wxTE_MULTILINE);
    
}

void ClickablePanel::mouseLeftClick(wxMouseEvent & event){
    wxPoint pt = event.GetPosition();    
    unsigned int region_id = _parent.getRegionID(pt.x,pt.y);
    if(region_id != NO_REGION_SELECTED)
        _controller.regionClicked(_parent.getRegionID(pt.x,pt.y));
}

