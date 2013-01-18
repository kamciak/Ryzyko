#ifndef COMBATDATA_H
#define COMBATDATA_H

#include <vector>
#include <string>

class CombatData{
private:
    std::vector<unsigned int> _atk_rolls;
    std::vector<unsigned int> _def_rolls;
    std::string _atk_name;
    std::string _def_name;
    std::string _atk_region;
    std::string _atk_region;
    unsigned int _atk_armycount;
    unsigned int _def_armycount;
    
public:
    CombatData(){}
    CombatData(std::vector<unsigned int> aroll, srd::vector<unsigned int> droll, std::string aname, std::string dname, unsigned int acount, unsigned int dcount, std::string areg, std::string dreg);
    std::vector<unsigned int> getAtkRolls();
    std::vector<unsigned int> getDefRolls();
    std::string getAtkName();
    std::string getDefName();
    std::string getAtkRegionName();
    std::string getDefRegionName();
    unsigned int getAtkArmyCount();
    unsigned int getDefArmyCount();
    
};

#endif
