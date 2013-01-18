#include "CombatData.h"

CombatData::CombatData(){}

CombatData::CombatData(std::vector<unsigned int> aroll, std::vector<unsigned int> droll, wxString aname, wxString dname, unsigned int acount, unsigned int dcount, wxString areg, wxString dreg){
    _atk_rolls = aroll;
    _def_rolls = droll;
    _atk_name = aname;
    _def_name = dname;
    _atk_armycount = acount;
    _def_armycount = dcount;
    _atk_region = areg;
    _def_region = dreg;
}

std::vector<unsigned int> CombatData::getAtkRolls(){
    return _atk_rolls;
}

std::vector<unsigned int> CombatData::getDefRolls(){
    return _def_rolls;
}

wxString CombatData::getAtkName(){
    return _atk_name;
}
    
wxString CombatData::getDefName(){
    return _def_name;
}

wxString CombatData::getAtkRegionName(){
    return _atk_region;
}

wxString CombatData::getDefRegionName(){
    return _def_region;
}

unsigned int CombatData::getAtkArmyCount(){
    return _atk_armycount;
}

unsigned int CombatData::getDefArmyCount(){
    return _def_armycount;
}
