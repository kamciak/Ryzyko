#include "RiskDeck.h"
#include <algorithm>

RiskDeck::RiskDeck(RiskCard *tab, int n){
    for(int i=0;i<n;i++)
        cards.push_back(&tab[i]);
    random_shuffle(cards.begin(),cards.end());    
}

RiskCard* RiskDeck::drawCard(){
    if (cards.empty()){
        RiskCard *wsk=NULL;
        return wsk;
    }
    else{
        std::vector<RiskCard*>::iterator it=cards.begin();
        RiskCard *wsk=*it;
        cards.erase(it);
        return wsk; 
    }     
}
