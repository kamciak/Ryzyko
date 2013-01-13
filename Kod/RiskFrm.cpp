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
	////Manual Code End
	EVT_UPDATE_UI(2500,RiskFrm::WxPanel1UpdateUI)
	EVT_CLOSE(RiskFrm::OnClose)
END_EVENT_TABLE()
////Event Table End


    

RiskFrm::RiskFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style), control(*this)
{
	CreateGUIControls();
	
	menu=new MenuDlg(this,control);
    menu->ShowModal();
    using namespace std;
   _colours.insert(make_pair(0,wxColour(0,170,190)));
        _colours.insert(make_pair(1,wxColour(1,200,160)));
        _colours.insert(make_pair(2,wxColour(2,150,210)));
        _colours.insert(make_pair(3,wxColour(3,220,140)));
        _colours.insert(make_pair(4,wxColour(4,130,230)));
        _colours.insert(make_pair(5,wxColour(5,240,120)));
        _colours.insert(make_pair(6,wxColour(6,250,110)));
        _colours.insert(make_pair(7,wxColour(7,230,130)));
        _colours.insert(make_pair(8,wxColour(8,110,250)));
        _colours.insert(make_pair(9,wxColour(9,120,100)));
        _colours.insert(make_pair(10,wxColour(10,100,120)));

        _colours.insert(make_pair(11,wxColour(11,130,90)));
        _colours.insert(make_pair(12,wxColour(12,90,130)));
        _colours.insert(make_pair(13,wxColour(13,80,140)));
        _colours.insert(make_pair(14,wxColour(14,140,80)));
        _colours.insert(make_pair(15,wxColour(15,70,150)));
        _colours.insert(make_pair(16,wxColour(16,150,70)));
        _colours.insert(make_pair(17,wxColour(17,60,160)));
        _colours.insert(make_pair(18,wxColour(18,160,60)));
        _colours.insert(make_pair(19,wxColour(19,170,50)));
        _colours.insert(make_pair(20,wxColour(20,40,180)));

        _colours.insert(make_pair(21,wxColour(21,180,40)));
        _colours.insert(make_pair(22,wxColour(22,10,220)));
        _colours.insert(make_pair(23,wxColour(23,50,190)));
        _colours.insert(make_pair(24,wxColour(24,210,30)));
        _colours.insert(make_pair(25,wxColour(25,200,40)));
        _colours.insert(make_pair(26,wxColour(26,30,210)));
        _colours.insert(make_pair(27,wxColour(27,40,200)));
        _colours.insert(make_pair(28,wxColour(28,190,50)));
        _colours.insert(make_pair(29,wxColour(29,220,10)));
        _colours.insert(make_pair(30,wxColour(30,100,200)));

        
        _colours.insert(make_pair(31,wxColour(31,250,100)));
        _colours.insert(make_pair(32,wxColour(32,10,200)));
        _colours.insert(make_pair(33,wxColour(33,200,10)));
        _colours.insert(make_pair(34,wxColour(34,200,240)));
        _colours.insert(make_pair(35,wxColour(35,190,80)));
        _colours.insert(make_pair(36,wxColour(36,50,150)));
        _colours.insert(make_pair(37,wxColour(37,170,30)));
        _colours.insert(make_pair(38,wxColour(38,10,240)));
        _colours.insert(make_pair(39,wxColour(39,240,10)));
        _colours.insert(make_pair(40,wxColour(40,20,230)));
        _colours.insert(make_pair(41,wxColour(41,230,20)));
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

	SetTitle(_("Risk"));
	SetIcon(wxNullIcon);
	
	Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
	////GUI Items Creation End
    //WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(0, 0), wxSize(1366, 768));
    
    this->SetBackgroundColour(wxColour(0,0,0));
    Centre();
}

void RiskFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

void RiskFrm::setResolution(){
    wxSize size = this->GetSize();
    
    unsigned int width = size.GetWidth();
    double scale = width/1366.0;
    unsigned int height = 768.0 * scale; 
    unsigned int panel_y = 0.5 * (size.GetHeight()-height);

    MapPanel = new ClickablePanel(this, control, 2500, wxPoint(0,panel_y), wxSize(width,height));
            
    wxImage::AddHandler( new wxJPEGHandler );
    wxImage::AddHandler( new wxJPEGHandler );
    wxImage::AddHandler( new wxPNGHandler );
    wxImage::AddHandler( new wxPNGHandler );
    map = new wxImage("map_regions.jpg");
    map->Rescale(width,height);
    mask = new wxImage("maska.png");
    mask->Rescale(width,height);
    map_with_mask = new wxImage(*map);
    army_number_plate = new wxImage("Images/numberplate.png");
    info("Aktualny gracz: "+PlayersData::instance().player(control.currentPlayer()).name());
}


void RiskFrm::paintSelectedRegion(unsigned int id){
    //DebugText -> SetLabel(DebugText -> GetLabel()+"paint:"+(char)id);
    
    delete map_with_mask;
    map_with_mask = new wxImage(*map);

    if(id != NO_REGION_SELECTED){             
        unsigned int w = map_with_mask->GetWidth();
        unsigned int h = map_with_mask->GetHeight();
        wxColour region_col(0,0,0);
        for(std::map<unsigned int,wxColour>::iterator i = _colours.begin(); i!=_colours.end(); ++i){
            if(i->second.Red() == id)
            region_col = i->second;
        }    
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                if(mask->GetRed(j,i) == region_col.Red() && mask->GetBlue(j,i) == region_col.Blue() && mask->GetGreen(j,i) ==region_col.Green())
                    map_with_mask->SetRGB(j,i,255,0,0);
            }
        }
    }
    
    
}   

/*
 * WxPanel1UpdateUI
 */
void RiskFrm::WxPanel1UpdateUI(wxUpdateUIEvent& event)
{
	
	wxClientDC dc(MapPanel);
	wxBufferedDC bdc(&dc);
    if(map_with_mask){
        
        wxBitmap map_with_mask_bp(*map_with_mask);
        bdc.DrawBitmap(map_with_mask_bp,0,0,true);

        std::vector<RegionDrawInformation> draw_info = control.getRegionDrawInfo();
        for(int i = 0; i < draw_info.size(); ++i){
            if(draw_info[i].image){
                wxBitmap soldier_bp(*draw_info[i].image);
                wxBitmap numberplate(*army_number_plate);
                bdc.DrawBitmap(soldier_bp,draw_info[i].point.x-12,draw_info[i].point.y-35,true);
                bdc.DrawBitmap(numberplate,draw_info[i].point.x-12,draw_info[i].point.y,true);
                std::stringstream ss;
                ss << draw_info[i].armies;
                std::string armies_s;
                ss >> armies_s;
                bdc.DrawText(armies_s,draw_info[i].point.x-5,draw_info[i].point.y);
            }
        }
    }
    /*if(_info_box)
        _info_box -> Raise();*/
}

unsigned int RiskFrm::getRegionID(unsigned int x, unsigned int y){
    if(x >= 0 && x < mask->GetSize().GetWidth() && y >= 0 && y < mask->GetSize().GetHeight()){
        unsigned char red = mask->GetRed(x,y);
        return red;
    }
    else return NO_REGION_SELECTED;
}

void RiskFrm::info(wxString txt){    
    static wxString buff="";
    //Jesli panel lub okno tekstowe nie zostaly jescze utworzone, zapamietaj komunikat i odtworz go przy nastepnym wywolaniu
    if(MapPanel && MapPanel -> info_box){
        MapPanel -> info_box -> AppendText("\n");
        MapPanel -> info_box -> AppendText(buff);
        buff.Clear();
        MapPanel -> info_box -> AppendText(txt);
    }   
    else{        
        buff.Append(txt);
    }
}
