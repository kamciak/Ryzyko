#include "CombatData.h"

CombatData::CombatData(){}

CombatData::CombatData(std::vector<unsigned int> aroll, srd::vector<unsigned int> droll, std::string aname, std::string dname, unsigned int acount, unsigned int dcount, std::string areg, std::string dreg){
    _atk_rolls = arroll;
    _def_rolls = droll;
    _atk_name = aname;
    _def_name = dname;
    _atk_armycount = acount;
    _def_armycount = dcount;
    _atk_region = areg;
    _def_regin = dreg;
}

std::vector<unsigned int> CombatData::getAtkRolls(){
    return _atk_rolls;
}

std::vector<unsigned int> CombatData::getDefRolls(){
    return _def_rolls;
}

std::string CombatData::getAtkName(){
    return _atk_name;
}
    
std::string CombatData::getDefName(){
    return _def_name;
}

std::string CombatData::getAtkRegionName(){
    return _atk_region;
}

std::string CombatData::getDefRegionName(){
    return _def_region;
}

unsigned int CombatData::getAtkArmyCount(){
    return _atk_armycount;
}

unsigned int CombatData::getDefArmyCount(){
    return _def_armycount;
}
