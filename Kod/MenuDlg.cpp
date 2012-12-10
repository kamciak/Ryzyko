///-----------------------------------------------------------------
///
/// @file      MenuDlg.cpp
/// @author    Kamciak
/// Created:   2012-12-04 01:56:54
/// @section   DESCRIPTION
///            MenuDlg class implementation
///
///------------------------------------------------------------------

#include "MenuDlg.h"
#include "RiskFrm.h"
#include "Controller.h"
#include <wx/dcbuffer.h>
//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// MenuDlg
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(MenuDlg,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(MenuDlg::OnClose)
	EVT_BUTTON(ID_WXBITMAPBUTTON8,MenuDlg::WxBitmapButton8Click)
	EVT_BUTTON(ID_WXBITMAPBUTTON7,MenuDlg::WxBitmapButton7Click)
	EVT_BUTTON(ID_WXBITMAPBUTTON6,MenuDlg::WxBitmapButton6Click)
	EVT_BUTTON(ID_WXBITMAPBUTTON5,MenuDlg::WxBitmapButton5Click)
	EVT_BUTTON(ID_WXBITMAPBUTTON2,MenuDlg::WxBitmapButton2Click)
	EVT_COMBOBOX(ID_WXBITMAPCOMBOBOX6,MenuDlg::WxBitmapComboBox1Selected)
	EVT_COMBOBOX(ID_WXBITMAPCOMBOBOX5,MenuDlg::WxBitmapComboBox1Selected)
	EVT_COMBOBOX(ID_WXBITMAPCOMBOBOX4,MenuDlg::WxBitmapComboBox1Selected)
	EVT_COMBOBOX(ID_WXBITMAPCOMBOBOX3,MenuDlg::WxBitmapComboBox1Selected)
	EVT_COMBOBOX(ID_WXBITMAPCOMBOBOX2,MenuDlg::WxBitmapComboBox1Selected)
	EVT_COMBOBOX(ID_WXBITMAPCOMBOBOX1,MenuDlg::WxBitmapComboBox1Selected)
	
	EVT_TEXT(ID_WXEDIT4,MenuDlg::WxEdit4Updated)
	EVT_BUTTON(ID_WXBITMAPBUTTON1,MenuDlg::WxBitmapButton1Click)
	
	EVT_UPDATE_UI(ID_WXPANEL1,MenuDlg::WxPanel1UpdateUI)
END_EVENT_TABLE()
////Event Table End

MenuDlg::MenuDlg(wxWindow *parent, Controller & control, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style), _controller(control)
{
    _parent=(RiskFrm*)parent;
	CreateGUIControls();
    
}

MenuDlg::~MenuDlg()
{
} 

void MenuDlg::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	wxInitAllImageHandlers();   //Initialize graphic format handlers

	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(0, 0), wxSize(800, 400));

	wxBitmap WxBitmapButton1_BITMAP (_("zamknij.jpg"), wxBITMAP_TYPE_JPEG);
	WxBitmapButton1 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON1, WxBitmapButton1_BITMAP, wxPoint(578, 34), wxSize(94, 20), wxBU_AUTODRAW, wxDefaultValidator, _("WxBitmapButton1"));

	WxEdit1 = new wxTextCtrl(WxPanel1, ID_WXEDIT1, _("Gracz 1"), wxPoint(210, 108), wxSize(120, 18), wxNO_BORDER, wxDefaultValidator, _("WxEdit1"));
	WxEdit1->SetForegroundColour(wxColour(64,0,0));
	WxEdit1->SetBackgroundColour(wxColour(228,216,190));
	WxEdit1->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, _("Comic Sans MS")));

	WxEdit2 = new wxTextCtrl(WxPanel1, ID_WXEDIT2, _("Gracz 2"), wxPoint(210, 138), wxSize(120, 18), wxNO_BORDER, wxDefaultValidator, _("WxEdit2"));
	WxEdit2->SetForegroundColour(wxColour(64,0,0));
	WxEdit2->SetBackgroundColour(wxColour(228,216,190));
	WxEdit2->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, _("Comic Sans MS")));

	WxEdit3 = new wxTextCtrl(WxPanel1, ID_WXEDIT3, _("Gracz 3"), wxPoint(210, 168), wxSize(120, 18), wxNO_BORDER, wxDefaultValidator, _("WxEdit3"));
	WxEdit3->Enable(false);
	WxEdit3->SetForegroundColour(wxColour(64,0,0));
	WxEdit3->SetBackgroundColour(wxColour(228,216,190));
	WxEdit3->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, _("Comic Sans MS")));

	WxEdit4 = new wxTextCtrl(WxPanel1, ID_WXEDIT4, _("Gracz 4"), wxPoint(210, 198), wxSize(120, 18), wxNO_BORDER, wxDefaultValidator, _("WxEdit4"));
	WxEdit4->Enable(false);
	WxEdit4->SetForegroundColour(wxColour(64,0,0));
	WxEdit4->SetBackgroundColour(wxColour(228,216,190));
	WxEdit4->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, _("Comic Sans MS")));

	WxEdit5 = new wxTextCtrl(WxPanel1, ID_WXEDIT5, _("Gracz 5"), wxPoint(210, 228), wxSize(120, 18), wxNO_BORDER, wxDefaultValidator, _("WxEdit5"));
	WxEdit5->Enable(false);
	WxEdit5->SetForegroundColour(wxColour(64,0,0));
	WxEdit5->SetBackgroundColour(wxColour(228,216,190));
	WxEdit5->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, _("Comic Sans MS")));

	WxEdit6 = new wxTextCtrl(WxPanel1, ID_WXEDIT6, _("Gracz 6"), wxPoint(210, 258), wxSize(120, 18), wxNO_BORDER, wxDefaultValidator, _("WxEdit6"));
	WxEdit6->Enable(false);
	WxEdit6->SetForegroundColour(wxColour(64,0,0));
	WxEdit6->SetBackgroundColour(wxColour(228,216,190));
	WxEdit6->SetFont(wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, _("Comic Sans MS")));

	wxArrayString arrayStringFor_WxBitmapComboBox1;
	WxBitmapComboBox1 = new wxBitmapComboBox(WxPanel1, ID_WXBITMAPCOMBOBOX1, _("Kolor"), wxPoint(340, 105), wxSize(90, 24), arrayStringFor_WxBitmapComboBox1, 0, wxDefaultValidator, _("WxBitmapComboBox1"));

	wxArrayString arrayStringFor_WxBitmapComboBox2;
	WxBitmapComboBox2 = new wxBitmapComboBox(WxPanel1, ID_WXBITMAPCOMBOBOX2, _("Kolor"), wxPoint(340, 135), wxSize(90, 24), arrayStringFor_WxBitmapComboBox2, 0, wxDefaultValidator, _("WxBitmapComboBox2"));

	wxArrayString arrayStringFor_WxBitmapComboBox3;
	WxBitmapComboBox3 = new wxBitmapComboBox(WxPanel1, ID_WXBITMAPCOMBOBOX3, _("Kolor"), wxPoint(340, 165), wxSize(90, 24), arrayStringFor_WxBitmapComboBox3, 0, wxDefaultValidator, _("WxBitmapComboBox3"));
	WxBitmapComboBox3->Show(false);

	wxArrayString arrayStringFor_WxBitmapComboBox4;
	WxBitmapComboBox4 = new wxBitmapComboBox(WxPanel1, ID_WXBITMAPCOMBOBOX4, _("Kolor"), wxPoint(340, 195), wxSize(90, 24), arrayStringFor_WxBitmapComboBox4, 0, wxDefaultValidator, _("WxBitmapComboBox4"));
	WxBitmapComboBox4->Show(false);

	wxArrayString arrayStringFor_WxBitmapComboBox5;
	WxBitmapComboBox5 = new wxBitmapComboBox(WxPanel1, ID_WXBITMAPCOMBOBOX5, _("Kolor"), wxPoint(340, 225), wxSize(90, 24), arrayStringFor_WxBitmapComboBox5, 0, wxDefaultValidator, _("WxBitmapComboBox5"));
	WxBitmapComboBox5->Show(false);

	wxArrayString arrayStringFor_WxBitmapComboBox6;
	WxBitmapComboBox6 = new wxBitmapComboBox(WxPanel1, ID_WXBITMAPCOMBOBOX6, _("Kolor"), wxPoint(340, 255), wxSize(90, 24), arrayStringFor_WxBitmapComboBox6, 0, wxDefaultValidator, _("WxBitmapComboBox6"));
	WxBitmapComboBox6->Show(false);

	wxBitmap WxBitmapButton2_BITMAP (_("do_boju.jpg"), wxBITMAP_TYPE_JPEG);
	WxBitmapButton2 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON2, WxBitmapButton2_BITMAP, wxPoint(354, 292), wxSize(101, 57), wxBU_AUTODRAW, wxDefaultValidator, _("WxBitmapButton2"));

	wxBitmap WxBitmapButton3_BITMAP (_("checkbox_true.jpg"), wxBITMAP_TYPE_JPEG);
	WxBitmapButton3 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON3, WxBitmapButton3_BITMAP, wxPoint(181, 105), wxSize(22, 22), wxBU_AUTODRAW, wxDefaultValidator, _("WxBitmapButton3"));

	wxBitmap WxBitmapButton4_BITMAP (_("checkbox_true.jpg"), wxBITMAP_TYPE_JPEG);
	WxBitmapButton4 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON4, WxBitmapButton4_BITMAP, wxPoint(181, 135), wxSize(22, 22), wxBU_AUTODRAW, wxDefaultValidator, _("WxBitmapButton4"));

	wxBitmap WxBitmapButton5_BITMAP (_("checkbox_false.jpg"), wxBITMAP_TYPE_JPEG);
	WxBitmapButton5 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON5, WxBitmapButton5_BITMAP, wxPoint(181, 165), wxSize(22, 22), wxBU_AUTODRAW, wxDefaultValidator, _("WxBitmapButton5"));

	wxBitmap WxBitmapButton6_BITMAP (_("checkbox_false.jpg"), wxBITMAP_TYPE_JPEG);
	WxBitmapButton6 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON6, WxBitmapButton6_BITMAP, wxPoint(181, 196), wxSize(22, 22), wxBU_AUTODRAW, wxDefaultValidator, _("WxBitmapButton6"));

	wxBitmap WxBitmapButton7_BITMAP (_("checkbox_false.jpg"), wxBITMAP_TYPE_JPEG);
	WxBitmapButton7 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON7, WxBitmapButton7_BITMAP, wxPoint(181, 225), wxSize(22, 22), wxBU_AUTODRAW, wxDefaultValidator, _("WxBitmapButton7"));

	wxBitmap WxBitmapButton8_BITMAP (_("checkbox_false.jpg"), wxBITMAP_TYPE_JPEG);
	WxBitmapButton8 = new wxBitmapButton(WxPanel1, ID_WXBITMAPBUTTON8, WxBitmapButton8_BITMAP, wxPoint(181, 255), wxSize(22, 22), wxBU_AUTODRAW, wxDefaultValidator, _("WxBitmapButton8"));

	wxArrayString arrayStringFor_WxComboBox1;
	WxComboBox1 = new wxComboBox(WxPanel1, ID_WXCOMBOBOX1, _("Rozdzielczoœæ"), wxPoint(530, 135), wxSize(145, 24), arrayStringFor_WxComboBox1, 0, wxDefaultValidator, _("WxComboBox1"));

	SetTitle(_("MenuDlg"));
	SetIcon(wxNullIcon);
	SetSize(8,8,800,400);
	Center();
	
	////GUI Items Creation End

	wxImage imageRed("colors/czerwony.jpg");
	wxBitmap red(imageRed);
	
	wxImage imageBlue("colors/niebieski.jpg");
	wxBitmap blue(imageBlue);
	
	wxImage imageGreen("colors/zielony.jpg");
	wxBitmap green(imageGreen);
	
	wxImage imageYellow("colors/zolty.jpg");
	wxBitmap yellow(imageYellow);
	
	wxImage imagePurple("colors/fioletowy.jpg");
	wxBitmap purple(imagePurple);
	
	wxImage imageGray("colors/szary.jpg");
	wxBitmap gray(imageGray);
	
	wxImage imageCyan("colors/morski.jpg");
	wxBitmap cyan(imageCyan);
	
	wxImage imageMagenta("colors/rozowy.jpg");
	wxBitmap magenta(imageMagenta);
	
	wxImage imageOrange("colors/pomaranczowy.jpg");
	wxBitmap orange(imageOrange);
	
	wxImage imageDarkblue("colors/granatowy.jpg");
	wxBitmap darkblue(imageDarkblue);
	

WxBitmapComboBox1->Append("Czerwony",red);
WxBitmapComboBox1->Append("Niebieski",blue);
WxBitmapComboBox1->Append("Zielony",green);
WxBitmapComboBox1->Append("Zolty",yellow);
WxBitmapComboBox1->Append("Fioletowy",purple);
WxBitmapComboBox1->Append("Szary",gray);
WxBitmapComboBox1->Append("Morski",cyan);
WxBitmapComboBox1->Append("Rozowy",magenta);
WxBitmapComboBox1->Append("Pomarancz",orange);
WxBitmapComboBox1->Append("Granatowy",darkblue);

WxBitmapComboBox2->Append("Czerwony",red);
WxBitmapComboBox2->Append("Niebieski",blue);
WxBitmapComboBox2->Append("Zielony",green);
WxBitmapComboBox2->Append("Zolty",yellow);
WxBitmapComboBox2->Append("Fioletowy",purple);
WxBitmapComboBox2->Append("Szary",gray);
WxBitmapComboBox2->Append("Morski",cyan);
WxBitmapComboBox2->Append("Rozowy",magenta);
WxBitmapComboBox2->Append("Pomarancz",orange);
WxBitmapComboBox2->Append("Granatowy",darkblue);

WxBitmapComboBox3->Append("Czerwony",red);
WxBitmapComboBox3->Append("Niebieski",blue);
WxBitmapComboBox3->Append("Zielony",green);
WxBitmapComboBox3->Append("Zolty",yellow);
WxBitmapComboBox3->Append("Fioletowy",purple);
WxBitmapComboBox3->Append("Szary",gray);
WxBitmapComboBox3->Append("Morski",cyan);
WxBitmapComboBox3->Append("Rozowy",magenta);
WxBitmapComboBox3->Append("Pomarancz",orange);
WxBitmapComboBox3->Append("Granatowy",darkblue);

WxBitmapComboBox4->Append("Czerwony",red);
WxBitmapComboBox4->Append("Niebieski",blue);
WxBitmapComboBox4->Append("Zielony",green);
WxBitmapComboBox4->Append("Zolty",yellow);
WxBitmapComboBox4->Append("Fioletowy",purple);
WxBitmapComboBox4->Append("Szary",gray);
WxBitmapComboBox4->Append("Morski",cyan);
WxBitmapComboBox4->Append("Rozowy",magenta);
WxBitmapComboBox4->Append("Pomarancz",orange);
WxBitmapComboBox4->Append("Granatowy",darkblue);

WxBitmapComboBox5->Append("Czerwony",red);
WxBitmapComboBox5->Append("Niebieski",blue);
WxBitmapComboBox5->Append("Zielony",green);
WxBitmapComboBox5->Append("Zolty",yellow);
WxBitmapComboBox5->Append("Fioletowy",purple);
WxBitmapComboBox5->Append("Szary",gray);
WxBitmapComboBox5->Append("Morski",cyan);
WxBitmapComboBox5->Append("Rozowy",magenta);
WxBitmapComboBox5->Append("Pomarancz",orange);
WxBitmapComboBox5->Append("Granatowy",darkblue);

WxBitmapComboBox6->Append("Czerwony",red);
WxBitmapComboBox6->Append("Niebieski",blue);
WxBitmapComboBox6->Append("Zielony",green);
WxBitmapComboBox6->Append("Zolty",yellow);
WxBitmapComboBox6->Append("Fioletowy",purple);
WxBitmapComboBox6->Append("Szary",gray);
WxBitmapComboBox6->Append("Morski",cyan);
WxBitmapComboBox6->Append("Rozowy",magenta);
WxBitmapComboBox6->Append("Pomarancz",orange);
WxBitmapComboBox6->Append("Granatowy",darkblue);
	

/**
*    Checkboxy obrazki
*/
    imgCheckBoxTrue=new wxImage("checkbox_true.jpg");
	bitmapCheckBoxTrue=new wxBitmap(*imgCheckBoxTrue);
	
    imgCheckBoxFalse=new wxImage("checkbox_false.jpg");
	bitmapCheckBoxFalse=new wxBitmap(*imgCheckBoxFalse);

/**
*   kod wyjscia dla wylaczania okna modalnego
*/
    this->SetReturnCode(1);
  
/**
*   lista rozdzielczosci 
*/
    WxComboBox1->Append("800x600 (4:3)");
    WxComboBox1->Append("1024x768 (4:3)");
    WxComboBox1->Append("1280x720 (16:9)");
    WxComboBox1->Append("1366×768 (16:9)");
    
    
/**
*	WxBitmapButton1  <- zamykanie okna dialogowego
*/
	wxImage imageHover("zamknij_hover.jpg");
	wxBitmap zamknij_hover(imageHover);
	WxBitmapButton1->SetBitmapHover(zamknij_hover);

/**
*	WxBitmapButton2  <- przejscie do okna gry
*/	
	wxImage imageDo_boju_hover("do_boju_hover.jpg");
	wxBitmap do_boju_hover(imageDo_boju_hover);
	WxBitmapButton2->SetBitmapHover(do_boju_hover);
	WxBitmapButton2->SetDoubleBuffered(true);
	
/**
*	WxBitmapButton3  <- gracz pierwszy, zawsze true
*/	
	WxBitmapButton3->SetDoubleBuffered(true);

/**
*	WxBitmapButton4  <- gracz drugi, zawsze true
*/	
	WxBitmapButton4->SetDoubleBuffered(true);
	
/**
*	WxBitmapButton5  <- gracz trzeci
*/	
	WxBitmapButton5->SetDoubleBuffered(true);
	isPlayer3=false;
	
/**
*	WxBitmapButton6  <- gracz czwarty
*/	
	WxBitmapButton6->SetDoubleBuffered(true);
	isPlayer4=false;
	
/**
*	WxBitmapButton7  <- gracz piaty
*/	
	WxBitmapButton7->SetDoubleBuffered(true);
	isPlayer5=false;
	
/**
*   WxBitmapButton8  <- gracz szosty
*/	
	WxBitmapButton8->SetDoubleBuffered(true);
	isPlayer6=false;
}

void MenuDlg::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}

/*
 * WxPanel1UpdateUI
 */
void MenuDlg::WxPanel1UpdateUI(wxUpdateUIEvent& event)
{
    

	wxImage::AddHandler( new wxJPEGHandler );
	wxImage image("background.jpg");
	wxBitmap tlo(image);
	wxClientDC dc(WxPanel1);
	wxBufferedDC bdc(&dc);
	bdc.DrawBitmap(tlo,0,0,true);
	

}

/*
 * WxBitmapButton1Click
 */
void MenuDlg::WxBitmapButton1Click(wxCommandEvent& event)
{
	wxExit();
}

/*
 * WxButton1Click
 */
void MenuDlg::WxButton1Click(wxCommandEvent& event)
{
	EndModal(1);
}

/*
 * WxEdit4Updated
 */
void MenuDlg::WxEdit4Updated(wxCommandEvent& event)
{
	wxString txt = WxEdit4->GetValue();
    if(txt == ""){
        WxEdit4->SetValue("Gracz 4");
        txt = "Gracz 4";
    }
    _controller.players_data.setPlayerName(4,std::string(txt.c_str()));
}

/*
 * WxBitmapComboBox1Selected
 */
void MenuDlg::WxBitmapComboBox1Selected(wxCommandEvent& event )
{
	_controller.players_data.setPlayerColor(1,PlayerColor(WxBitmapComboBox1->GetCurrentSelection()));
}

/*
 * WxBitmapButton2Click
 */
void MenuDlg::WxBitmapButton2Click(wxCommandEvent& event)
{
	// insert your code here
    _parent->ShowFullScreen(true,wxFULLSCREEN_ALL);
    _parent->setResolution(1);  //TODO -zmiana rozdzielczosci
	EndModal(1);
}

/*
 * WxBitmapButton5Click
 */
void MenuDlg::WxBitmapButton5Click(wxCommandEvent& event)
{
    if(!isPlayer3){
            isPlayer3=true;
            WxEdit3->Enable(true);
            WxBitmapComboBox3->Show(true);
            
            WxBitmapButton5->SetBitmapLabel(*bitmapCheckBoxTrue);
        }
    else{
            isPlayer3=false;
            WxEdit3->Enable(false);
            WxBitmapComboBox3->Show(false);
            
            WxBitmapButton5->SetBitmapLabel(*bitmapCheckBoxFalse);   
        
        
        }
}

/*
 * WxBitmapButton6Click
 */
void MenuDlg::WxBitmapButton6Click(wxCommandEvent& event)
{
    if(!isPlayer4){
            isPlayer4=true;
            WxEdit4->Enable(true);
            WxBitmapComboBox4->Show(true);
            
            WxBitmapButton6->SetBitmapLabel(*bitmapCheckBoxTrue);
        }
    else{
            isPlayer4=false;
            WxEdit4->Enable(false);
            WxBitmapComboBox4->Show(false);
            
            WxBitmapButton6->SetBitmapLabel(*bitmapCheckBoxFalse);   
        
        
        }
}

/*
 * WxBitmapButton7Click
 */
void MenuDlg::WxBitmapButton7Click(wxCommandEvent& event)
{
    if(!isPlayer5){
            isPlayer5=true;
            WxEdit5->Enable(true);
            WxBitmapComboBox5->Show(true);
            
            WxBitmapButton7->SetBitmapLabel(*bitmapCheckBoxTrue);
        }
    else{
            isPlayer5=false;
            WxEdit5->Enable(false);
            WxBitmapComboBox5->Show(false);
            
            WxBitmapButton7->SetBitmapLabel(*bitmapCheckBoxFalse);   
        
        
        }
}

/*
 * WxBitmapButton8Click
 */
void MenuDlg::WxBitmapButton8Click(wxCommandEvent& event)
{
    if(!isPlayer6){
            isPlayer6=true;
            WxEdit6->Enable(true);
            WxBitmapComboBox6->Show(true);
            
            WxBitmapButton8->SetBitmapLabel(*bitmapCheckBoxTrue);
        }
    else{
            isPlayer6=false;
            WxEdit6->Enable(false);
            WxBitmapComboBox6->Show(false);
            
            WxBitmapButton8->SetBitmapLabel(*bitmapCheckBoxFalse);   
        
        
        }
}
