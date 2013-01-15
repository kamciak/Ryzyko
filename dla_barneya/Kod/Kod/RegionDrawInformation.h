#ifndef REGIONDRAWINFO_H
#define REGIONDRAWINFO_H

#include <wx/wx.h>

class RegionDrawInformation{
public:
    wxPoint point;
    wxImage * image;
    unsigned int armies;
    
    RegionDrawInformation(wxPoint p, wxImage & im, unsigned int arm) : point(p), image(&im), armies(arm){}
};

#endif
