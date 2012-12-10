#ifndef CLICKABLEPANEL_H
#define CLICKABLEPANEL_H
#include <wx/panel.h>
#include "Controller.h"


class ClickablePanel : public wxPanel{
private:    
    Controller & _controller;
public:         
    ClickablePanel(wxWindow* parent, Controller & control, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL, const wxString& name = "panel") 
        : wxPanel(parent,id,pos,size,style,name), _controller(control){}
    
    void mouseLeftClick(wxMouseEvent & event){
        wxPoint pt = event.GetPosition();
        _controller.selectRegion(pt.x,pt.y);
    }

    DECLARE_EVENT_TABLE()
};
#endif
