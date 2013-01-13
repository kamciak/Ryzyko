#ifndef CLICKABLEPANEL_H
#define CLICKABLEPANEL_H
#include <wx/panel.h>
#include "Controller.h"

class RiskFrm;

class ClickablePanel : public wxPanel{
private:    
    Controller & _controller;
    RiskFrm & _parent;
    
public:      
    wxTextCtrl *info_box;   
    ClickablePanel(RiskFrm* parent, Controller & control, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL, const wxString& name = "panel");
    
    void mouseLeftClick(wxMouseEvent & event);

    DECLARE_EVENT_TABLE()
};
#endif
