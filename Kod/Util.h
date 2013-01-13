#ifndef UTIL_H
#define UTIL_H
#include <sstream>

std::string intToString(int n){
    std::stringstream ss;
    ss << n;
    std::string s;
    ss >> s;
    return s;
}

#endif
