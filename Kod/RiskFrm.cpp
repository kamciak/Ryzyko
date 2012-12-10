///-----------------------------------------------------------------
///
/// @file      RiskFrm.cpp
/// @author    Piotrek
/// Created:   2012-10-19 20:31:21
/// @section   DESCRIPTION
///            RiskFrm class implementation
///
///------------------------------------------------------------------

#include "RiskFrm.h"
#include <wx/dcbuffer.h>
#include <sstream>
//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// RiskFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(RiskFrm,wxFrame)
	////Manual Code Start
	EVT_LEFT_DOWN(RiskFrm::mouseLeftClick)
	////Manual Code End
	
	EVT_CLOSE(RiskFrm::OnClose)
	
	EVT_UPDATE_UI(ID_WXPANEL1,RiskFrm::WxPanel1UpdateUI)
END_EVENT_TABLE()
////Event Table End

    

RiskFrm::RiskFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style), control(Board::instance(),PlayersData::instance(),*this)
{
	CreateGUIControls();
	
	   menu=new MenuDlg(this);
		menu->ShowModal();

}

RiskFrm::~RiskFrm()
{
}

void RiskFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxBoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	this->SetSizer(WxBoxSizer1);
	this->SetAutoLayout(true);

	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(0, 0), wxSize(1366, 768));
	WxBoxSizer1->Add(WxPanel1, 0, wxALIGN_CENTER | wxALL, 5);

	DebugText = new wxStaticText(WxPanel1, ID_DEBUGTEXT, _("DebugText"), wxPoint(416, 280), wxDefaultSize, 0, _("DebugText"));

	SetTitle(_("Risk"));
	SetIcon(wxNullIcon);
	
	Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
	////GUI Items Creation End
    _dc = new wxClientDC(WxPanel1);
}

void RiskFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

void RiskFrm::setResolution(unsigned int id){
    //TODO: sprawdzenie id i wybranie odpowiedniej mapy
    wxImage::AddHandler( new wxJPEGHandler );
    wxImage::AddHandler( new wxJPEGHandler );
    wxImage::AddHandler( new wxJPEGHandler );
    map = new wxImage("map_regions.jpg");
    mask = new wxImage("maska.jpg");
    map_with_mask = new wxImage(*map);
}

void RiskFrm::mouseLeftClick(wxMouseEvent & event){
    std::stringstream ss;
    std::string s="";
    wxPoint mpos = event.GetLogicalPosition(*_dc);
    long int x;
    long int y;
    event.GetPosition(&x,&y);
    ss << "X=" << x << " Y=" << y;
    unsigned char red = mask->GetRed(mpos.x,mpos.y);
    ss << " red=" << red;        
    ss >> s;
    wxString wxs(s);
    DebugText -> SetLabel(DebugText -> GetLabel()+wxs);
    unsigned char blue = mask->GetBlue(mpos.x,mpos.y);
    control.setSelectedRegion(red);
    event.Skip();
    
    
}

void RiskFrm::paintSelectedRegion(unsigned int id){
    DebugText -> SetLabel(DebugText -> GetLabel()+"paint:"+(char)id);
    delete map_with_mask;
    map_with_mask = new wxImage(*map);
    unsigned int w = map_with_mask->GetWidth();
    unsigned int h = map_with_mask->GetHeight();
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            if(mask->GetRed(j,i) == id)
                map_with_mask->SetRGB(j,i,255,0,0);
        }
    }
}   

/*
 * WxPanel1UpdateUI
 */
void RiskFrm::WxPanel1UpdateUI(wxUpdateUIEvent& event)
{
	// insert your code here
	
	
	wxClientDC dc(WxPanel1);
	wxBufferedDC bdc(&dc);
    if(map_with_mask){
        wxBitmap map_with_mask_bp(*map_with_mask);	 
        bdc.DrawBitmap(map_with_mask_bp,0,0,true);
    }
}
