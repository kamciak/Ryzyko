#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>
class RiskException{
public:
    const std::string msg;
protected:
    RiskException(std::string s):msg(s){      
    }
};

class RegionNotFoundException: public RiskException{
public:
    RegionNotFoundException():RiskException("Blad! Nie znaleziono regionu!"){
    }
};

#endif
