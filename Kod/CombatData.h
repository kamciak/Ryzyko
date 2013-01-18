#ifndef COMBATDATA_H
#define COMBATDATA_H

#include <vector>
#include <string>
#include <wx/wx.h>

class CombatData{
private:
    std::vector<unsigned int> _atk_rolls;
    std::vector<unsigned int> _def_rolls;
    wxString _atk_name;
    wxString _def_name;
    wxString _atk_region;
    wxString _def_region;
    unsigned int _atk_armycount;
    unsigned int _def_armycount;
    
public:
    CombatData();
    CombatData(std::vector<unsigned int> aroll, std::vector<unsigned int> droll, wxString aname, wxString dname, unsigned int acount, unsigned int dcount, wxString areg, wxString dreg);
    std::vector<unsigned int> getAtkRolls();
    std::vector<unsigned int> getDefRolls();
    wxString getAtkName();
    wxString getDefName();
    wxString getAtkRegionName();
    wxString getDefRegionName();
    unsigned int getAtkArmyCount();
    unsigned int getDefArmyCount();
    
};

#endif
