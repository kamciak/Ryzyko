#ifndef RISKEXCEPTIONS_H
#define RISKEXCEPTIONS_H
#include <string>

class RiskException{
protected:
	RiskException(std::string s) : msg(s){}
public:
	const std::string msg;
};

class NoSuchRegionException : public RiskException{
public:
	NoSuchRegionException(std::string region_name) : RiskException("B³¹d! nie odnaleziono regionu: "+region_name){}
};

#endif
