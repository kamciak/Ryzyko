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
	
	EVT_CLOSE(RiskFrm::OnClose)
	
	EVT_UPDATE_UI(ID_WXPANEL1,RiskFrm::WxPanel1UpdateUI)
END_EVENT_TABLE()
////Event Table End

RiskFrm::RiskFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
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

	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(5, 5), wxSize(1360, 768));
	WxBoxSizer1->Add(WxPanel1, 0, wxALIGN_CENTER | wxALL, 5);

	SetTitle(_("Risk"));
	SetIcon(wxNullIcon);
	
	Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();
	
	////GUI Items Creation End

}

void RiskFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * WxPanel1UpdateUI
 */
void RiskFrm::WxPanel1UpdateUI(wxUpdateUIEvent& event)
{
	// insert your code here
	wxImage::AddHandler( new wxJPEGHandler );
	wxImage map("map.jpg");
	wxBitmap Map(map);
	wxClientDC dc(WxPanel1);
	wxBufferedDC bdc(&dc);
	bdc.DrawBitmap(Map,0,0,true);
}
