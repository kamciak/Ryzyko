#ifndef RISKDECK_H
#define RISKDECK_H
#include <vector>
#include "RiskCard.h"

class RiskDeck{
    public:
        RiskDeck(RiskCard tab[], int n);
        RiskCard* drawCard();
    private:
        std::vector<RiskCard*> cards;   
};

#endif
