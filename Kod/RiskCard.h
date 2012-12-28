#ifndef RISKCARD_H
#define RISKCARD_H
#include <string>
class RiskDeck;

class RiskCard{
    friend class RiskDeck;
    public:
        RiskCard(char z, std::string r="") : army(z), region(r){} 
        char getArmy();
        std::string getRegion();
    private:    
        char army;
        std::string region;
};       

#endif
