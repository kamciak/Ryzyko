#include "Util.h"

std::string intToString(int n){
    std::stringstream ss;
    ss << n;
    std::string s;
    ss >> s;
    return s;
}
