///-----------------------------------------------------------------
///
/// @file      RiskFrm.h
/// @author    Piotrek
/// Created:   2012-10-19 20:31:21
/// @section   DESCRIPTION
///            RiskFrm class declaration
///
///------------------------------------------------------------------

#ifndef __RISKFRM_H__
#define __RISKFRM_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/sizer.h>
////Header Include End

////Dialog Style Start
#undef RiskFrm_STYLE
#define RiskFrm_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End
#include <map>
#include <sstream>
#include "MenuDlg.h"
#include "Controller.h"
#include "PlayersData.h"
#include "Board.h"
#include "ClickablePanel.h"


#define NO_REGION_SELECTED 99

class RiskFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		RiskFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Risk"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = RiskFrm_STYLE);
		virtual ~RiskFrm();
		void WxPanel1UpdateUI(wxUpdateUIEvent& event);
        
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxBoxSizer *WxBoxSizer1;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
		ClickablePanel *MapPanel;
        Controller control;
        std::map<unsigned int, wxColour> _colours;
        std::map<PlayerColor, wxColour> _player_colours;
        wxImage *_fortify_phase_image;
        wxImage *_attack_phase_image;
        wxImage *_reinforce_phase_image;
        wxImage *_setup_phase_image;
        double _scale;
        
    public:
        MenuDlg *menu;
        wxImage *map;
        wxImage *mask;
        wxImage *map_with_mask;
        wxImage *regions_highlight;
        wxImage *army_number_plate;
        
        void mouseLeftClick(wxMouseEvent & event);
        void setResolution();
        void paintSelectedRegion(unsigned int id);
        void info(wxString txt);
        void setScale();
        double getScale();
        unsigned int getRegionID(unsigned int x, unsigned int y);
        void endPhaseButtonVisible(bool flag);
};

#endif
