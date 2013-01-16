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
#include <sstream>

#include "Util.h"

#define END_PHASE_X 790
#define END_PHASE_Y 600
#define PHASE_BAR_X 520
#define PHASE_BAR_WIDTH 400
#define DEFAULT_SIZE_X 1366
#define DEFAULT_SIZE_Y 768
#define PLAYERS_SCROLL_X 60
#define PLAYERS_SCROLL_Y 45
#define PLAYERS_SCROLL_WIDTH 240
#define PLAYERS_SCROLL_HEIGHT 120
#define BIG_IMAGE_THRESHHOLD 1500
#define MAP_BORDER_THICKNESS 22

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

        _player_colours.insert(make_pair(RED,wxColour(255,0,0)));
        _player_colours.insert(make_pair(BLUE,wxColour(0,0,255)));
        _player_colours.insert(make_pair(GREEN,wxColour(0,255,0)));
        _player_colours.insert(make_pair(CYAN,wxColour(0,255,255)));
        _player_colours.insert(make_pair(DARKBLUE,wxColour(0,0,175)));
        _player_colours.insert(make_pair(GRAY,wxColour(128,128,128)));
        _player_colours.insert(make_pair(MAGENTA,wxColour(255,0,255)));
        _player_colours.insert(make_pair(YELLOW,wxColour(255,255,0)));
        _player_colours.insert(make_pair(ORANGE,wxColour(255,127,0)));
        _player_colours.insert(make_pair(PURPLE,wxColour(175,0,175)));

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
    _draw_flag = true;
    _perma_draw = false;
    Centre();
}

void RiskFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

void RiskFrm::setResolution(){
    setScale();
    double scale = getScale();
    wxSize size = this->GetSize();
    unsigned int width = DEFAULT_SIZE_X * scale;
    unsigned int height = DEFAULT_SIZE_Y * scale; 
    unsigned int panel_y = 0.5 * (size.GetHeight()-height);

    MapPanel = new ClickablePanel(this, control, 2500, wxPoint(0,panel_y), wxSize(width,height));
    wxPoint endphasebtn_pos(PHASE_BAR_X + PHASE_BAR_WIDTH, MapPanel->GetSize().GetHeight() - MapPanel->end_phase_btn->GetBitmapLabel().GetSize().GetHeight() - MAP_BORDER_THICKNESS * scale);
    MapPanel -> end_phase_btn -> Move(endphasebtn_pos);  
    MapPanel -> end_phase_btn -> Show();
    MapPanel -> end_phase_btn -> Disable();     
    MapPanel -> end_phase_btn -> SetDoubleBuffered(true);

    wxImage::AddHandler( new wxJPEGHandler );
    wxImage::AddHandler( new wxPNGHandler );

    _fortify_phase_image = new wxImage("Images/fortifyphase.png");
    _attack_phase_image = new wxImage("Images/attackphase.png");
    _reinforce_phase_image = new wxImage("Images/reinforcephase.png");
    _setup_phase_image = new wxImage("Images/setupphase.png");
    _card_phase_image = new wxImage("Images/cardphase.png");
    _forced_card_phase_image = new wxImage("Images/cardphaseforce.png");

    _current_player_image = new wxImage("Images/flag.png");
    _current_player_bitmap = new wxBitmap(*_current_player_image);

    map = new wxImage("Images/map_regions.jpg");
    map->Rescale(width,height);
    mask = new wxImage("Images/maska.png");
    mask->Rescale(width,height);
    regions_highlight = new wxImage("Images/highlight.png");
    regions_highlight->Rescale(width,height);
    
    map_with_mask = new wxImage(*map);
    bool big_image = this->GetSize().GetWidth() > BIG_IMAGE_THRESHHOLD ? true : false;
    if(big_image)
        army_number_plate = new wxImage("Images/numberplateb.png");
    else
        army_number_plate = new wxImage("Images/numberplates.png");

    //info("Aktualny gracz: "+PlayersData::instance().player(control.currentPlayer()).name());
}


void RiskFrm::paintSelectedRegion(unsigned int id){
    //DebugText -> SetLabel(DebugText -> GetLabel()+"paint:"+(char)id);
    
    wxDELETE(map_with_mask);
    map_with_mask = new wxImage(*map);

    if(id != NO_REGION_SELECTED){             
        unsigned int w = map_with_mask->GetWidth();
        unsigned int h = map_with_mask->GetHeight();
        wxColour region_col = _colours[id];
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                if(mask->GetRed(j,i) == region_col.Red() 
                && mask->GetBlue(j,i) == region_col.Blue() 
                && mask->GetGreen(j,i) ==region_col.Green()){
                    unsigned char red = regions_highlight->GetRed(j,i);
                    unsigned char green = regions_highlight->GetGreen(j,i);
                    unsigned char blue = regions_highlight->GetBlue(j,i);
                    map_with_mask->SetRGB(j,i,red,green,blue);
                }
            }
        }
    }
    
    
}   

/*
 * WxPanel1UpdateUI
 */
void RiskFrm::WxPanel1UpdateUI(wxUpdateUIEvent& event)
{
    if(_draw_flag || _perma_draw){
    	double scale = getScale();
    
    	wxClientDC dc(MapPanel);
    	wxBufferedDC bdc(&dc);
        if(map_with_mask){
           
            wxBitmap map_with_mask_bp(*map_with_mask);
            wxBitmap *phase_bar_bmp;
            PhaseName phase = control.getPhaseName();
            switch(phase){
                case SETUP:
                    phase_bar_bmp = new wxBitmap(*_setup_phase_image);
                    break;
                case REINFORCE:
                    phase_bar_bmp = new wxBitmap(*_reinforce_phase_image);
                    break;
                case ATTACK:
                    phase_bar_bmp = new wxBitmap(*_attack_phase_image);
                    break;
                case FORTIFY:
                    phase_bar_bmp = new wxBitmap(*_fortify_phase_image);
                    break;
                case CARD:
                    phase_bar_bmp = new wxBitmap(*_card_phase_image);
                    break;
            }
            bdc.DrawBitmap(map_with_mask_bp,0,0,true);
            wxPoint phasebar_pos(PHASE_BAR_X * scale, MapPanel->GetSize().GetHeight() - phase_bar_bmp->GetSize().GetHeight() - MAP_BORDER_THICKNESS * scale); 
            bdc.DrawBitmap(*phase_bar_bmp,phasebar_pos,true);
            wxDELETE(phase_bar_bmp);
            drawPlayersData(bdc,control.getPlayerDrawInfo());
            
            bool big_image = this -> GetSize().GetWidth() > BIG_IMAGE_THRESHHOLD ? true : false;
            std::vector<RegionDrawInformation> draw_info = control.getRegionDrawInfo(big_image);
            for(int i = 0; i < draw_info.size(); ++i){
                if(draw_info[i].image){
                    wxBitmap soldier_bp(*draw_info[i].image);
                    wxBitmap numberplate(*army_number_plate);
    
                    int bmp_width = soldier_bp.GetSize().GetWidth();
                    int soldier_height = soldier_bp.GetSize().GetHeight();
    
                    bdc.DrawBitmap(soldier_bp,draw_info[i].point.x-(bmp_width/2),draw_info[i].point.y-soldier_height,true);
                    bdc.DrawBitmap(numberplate,draw_info[i].point.x-(bmp_width/2),draw_info[i].point.y,true);
                    std::string armies_s = intToString(draw_info[i].armies);
                    int text_dx = armies_s.length() > 1 ? -5 : -2;
                    bdc.DrawText(armies_s,draw_info[i].point.x+text_dx,draw_info[i].point.y);
                }
            }
        }
        _draw_flag = false;
    }
}

void RiskFrm::drawPlayersData(wxBufferedDC & dc, std::vector<PlayerDrawInfo> col){
    double scale = getScale();
    int players_display_x = PLAYERS_SCROLL_X * scale;
    int players_display_width = PLAYERS_SCROLL_WIDTH * scale;

    int players_display_height = PLAYERS_SCROLL_HEIGHT * scale;
    int players_display_y[MAX_PLAYERS];
    players_display_y[0] = PLAYERS_SCROLL_Y * scale;
    for(int i = 1; i < MAX_PLAYERS; ++i){
        players_display_y[i] = players_display_y[i-1] + players_display_height / MAX_PLAYERS;
    }
    for(int i = 0; i < col.size(); ++i){
        dc.SetPen(wxPen(_player_colours[col[i].color]));
        dc.SetBrush(wxBrush(_player_colours[col[i].color]));
        dc.DrawRectangle(players_display_x, players_display_y[i], players_display_height/MAX_PLAYERS, players_display_height/MAX_PLAYERS);
        dc.DrawText(col[i].name, players_display_x + players_display_height/MAX_PLAYERS + 1,players_display_y[i]);
        dc.DrawText(intToString(col[i].territories), players_display_x + players_display_width - 10, players_display_y[i]);
        
        if(col[i].current){
            if(_current_player_bitmap)
                dc.DrawBitmap(*_current_player_bitmap, players_display_x + players_display_width - 35,players_display_y[i], true);       
        }
    }
}



unsigned int RiskFrm::getRegionID(unsigned int x, unsigned int y){
    if(x >= 0 && x < mask->GetSize().GetWidth() && y >= 0 && y < mask->GetSize().GetHeight()){
        unsigned char red = mask->GetRed(x,y);
        if(red != 0)
            return red;
        else if(mask->GetGreen(x,y) == _colours[0].Green() &&
        mask->GetBlue(x,y) == _colours[0].Blue()){
            return red;
        }
        else
            return NO_REGION_SELECTED;
    }
}

/*void RiskFrm::info(wxString txt){    
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
}*/

void RiskFrm::endPhaseButtonEnabled(bool flag){
    if(flag)
        MapPanel -> end_phase_btn -> Enable();
    else
        MapPanel -> end_phase_btn -> Disable();
}

void RiskFrm::setScale(){
    wxSize size = this->GetSize();    
    unsigned int width = size.GetWidth();
    _scale = width/1366.0;
}

double RiskFrm::getScale(){
    return _scale;
}   


void RiskFrm::setDrawFlag(){
    _draw_flag = true;
}

void RiskFrm::setPermaDraw(){
    _perma_draw = true;
}

void RiskFrm::unsetPermaDraw(){
    _perma_draw = false;
}

