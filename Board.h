#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <iostream>
#include "Exceptions.h"
#include "Region.h"

class Board{
private:
    std::vector<Region> _regions;
public:
    Board();
    Region &getRegion(std::string name);
};


#endif
