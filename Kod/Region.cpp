#include "Region.h"



Region::Region(unsigned int id,std::string region_name, wxPoint coords){
    _id = id;
    _name = region_name;
    _coords = coords;
    _controller = NO_CONTROLLER;
    _armies = 0;
}

void Region::addArmies(unsigned int num){
    _armies += num;
}

void Region::removeArmies(unsigned int num){
    _armies -= num;
}


void Region::addNeighbor(unsigned int id){
    if(!isNeighbor(id))
        _neighbors.push_back(id);
}


bool Region::isNeighbor(unsigned int id){
    for(int i = 0; i < _neighbors.size(); ++i){
        if(_neighbors[i] == id)
            return true;
    }
    
    return false;
}


wxPoint Region::center(){
    return _coords;
}


unsigned int Region::armyCount(){
    return _armies;
}   
    
std::string Region::name(){
    return _name;
}

unsigned int Region::id(){
    return _id;
}   
    
unsigned int Region::controller(){
    return _controller;
}

void Region::setController(unsigned int id){
    _controller = id;
}
