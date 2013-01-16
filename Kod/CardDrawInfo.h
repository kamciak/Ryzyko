#ifndef CARDDRAWINFO_H
#define CARDDRAWINFO_H

class CardDrawInfo{
public:
    CardDrawInfo(std::string region, wxBitmap * img) : region_name(region), image(img){}
    wxBitmap *image;
    std::string region_name;
};

#endif
