#include "Board.h"
#include "Region.h"

Region &Board::getRegion(std::string name){
    for(unsigned int i = 0; i < _regions.size(); ++i){
        if(_regions[i]._name == name)
            return _regions[i];
    }   
    throw RegionNotFoundException();
}

Board::Board(){
    unsigned int i=0;
    _regions.push_back(Region(i++,"Test1"));    
    _regions.push_back(Region(i++,"Test2"));
    getRegion("Test1").addNeighbor(getRegion("Test2"));
}
