#include <algorithm>
#include "Board.h"




Board::Board(){
	_board.push_back(Region(_board.size(),"Yeppon",wxPoint(1215,570)));
	_board.push_back(Region(_board.size(),"Karratha",wxPoint(1150,560)));
    _board.push_back(Region(_board.size(),"Jayapura",wxPoint(1190,515)));
    _board.push_back(Region(_board.size(),"Kapit",wxPoint(1110,490)));
    _board.push_back(Region(_board.size(),"Lao",wxPoint(1035,425)));
    _board.push_back(Region(_board.size(),"Chengdu",wxPoint(1080,400)));
    _board.push_back(Region(_board.size(),"Neyungri",wxPoint(1110,340)));
    _board.push_back(Region(_board.size(),"Aomori",wxPoint(1180,400)));
    _board.push_back(Region(_board.size(),"Magadan",wxPoint(1285,255)));
    _board.push_back(Region(_board.size(),"Bratsk",wxPoint(1100,270)));	
    _board.push_back(Region(_board.size(),"Yakutsk",wxPoint(1065,215)));
    _board.push_back(Region(_board.size(),"Achinsk",wxPoint(960,235)));
    _board.push_back(Region(_board.size(),"Ulan-Ude",wxPoint(960,345)));
    _board.push_back(Region(_board.size(),"Ajmer",wxPoint(960,450)));
    _board.push_back(Region(_board.size(),"Erdenet",wxPoint(875,400)));
    _board.push_back(Region(_board.size(),"Kansk",wxPoint(820,330)));
    _board.push_back(Region(_board.size(),"Vorkuta",wxPoint(895,280)));    
	_board.push_back(Region(_board.size(),"Oulu",wxPoint(735,255)));
    _board.push_back(Region(_board.size(),"Lida",wxPoint(755,325)));
    _board.push_back(Region(_board.size(),"Temi",wxPoint(740,360)));
    _board.push_back(Region(_board.size(),"Gijon",wxPoint(675,370)));
    _board.push_back(Region(_board.size(),"Evel",wxPoint(650,325)));
    _board.push_back(Region(_board.size(),"Reykjavik",wxPoint(600,260)));
    _board.push_back(Region(_board.size(),"Mut",wxPoint(800,440)));
    _board.push_back(Region(_board.size(),"Dessie",wxPoint(825,530)));
    _board.push_back(Region(_board.size(),"Saka",wxPoint(840,560)));
    _board.push_back(Region(_board.size(),"Cradock",wxPoint(735,580)));
    _board.push_back(Region(_board.size(),"Likasi",wxPoint(740,530)));
    _board.push_back(Region(_board.size(),"Bobo-Dioulasso",wxPoint(730,480)));
    _board.push_back(Region(_board.size(),"Qaanaaq",wxPoint(540,210)));
    _board.push_back(Region(_board.size(),"Yellowknife",wxPoint(275,220)));
    _board.push_back(Region(_board.size(),"Fairbanks",wxPoint(130,230)));
    _board.push_back(Region(_board.size(),"Terrace",wxPoint(275,310)));
    _board.push_back(Region(_board.size(),"Manitoba",wxPoint(370,330)));
    _board.push_back(Region(_board.size(),"Saguenay",wxPoint(425,305)));
    _board.push_back(Region(_board.size(),"Hoover",wxPoint(390,405)));
    _board.push_back(Region(_board.size(),"Riverton",wxPoint(300,355)));
    _board.push_back(Region(_board.size(),"Teape",wxPoint(345,455)));
    _board.push_back(Region(_board.size(),"Sipapo",wxPoint(465,500)));
    _board.push_back(Region(_board.size(),"Bahia",wxPoint(505,530)));
    _board.push_back(Region(_board.size(),"Potosi",wxPoint(415,545)));
    _board.push_back(Region(_board.size(),"Tandil",wxPoint(420,675)));
	
    
    
   
    
    
    try{
        addConnection("Yeppon","Karratha");
        addConnection("Yeppon","Jayapura");
        
        addConnection("Karratha","Kapit");
        addConnection("Karratha","Jayapura");
        addConnection("Karratha","Yeppon");
        addConnection("Karratha","Jayapura");
        
        addConnection("Jayapura","Kapit");
        addConnection("Jayapura","Karratha");
        addConnection("Jayapura","Yeppon");
        
        addConnection("Kapit","Lao");
        addConnection("Kapit","Jayapura");
        addConnection("Kapit","Karratha");
        
        addConnection("Lao","Chengdu");
        addConnection("Lao","Ajmer");
        addConnection("Lao","Kapit");
        
        addConnection("Chengdu","Ulan-Ude");
        addConnection("Chengdu","Neyungri");
        addConnection("Chengdu","Lao");
        addConnection("Chengdu","Ajmer");
        addConnection("Chengdu","Achinsk");
        
        addConnection("Neyungri","Aomori");
        addConnection("Neyungri","Bratsk");
        addConnection("Neyungri","Magadan");
        addConnection("Neyungri","Chengdu");
        addConnection("Neyungri","Achinsk");
        
        addConnection("Aomori","Magadan");
        addConnection("Aomori","Chengdu");

        addConnection("Bratsk","Achinsk");
        addConnection("Bratsk","Yakutsk");
        addConnection("Bratsk","Magadan");
        addConnection("Bratsk","Neyungri");
        
        addConnection("Magadan","Fairbanks");
        addConnection("Magadan","Aomori");
        addConnection("Magadan","Yakutsk");
        addConnection("Magadan","Bratsk");
        addConnection("Magadan","Neyungri");
        
        addConnection("Yakutsk","Magadan");
        addConnection("Yakutsk","Bratsk");
        addConnection("Yakutsk","Achinsk");
        
        addConnection("Bratsk","Achinsk");
        addConnection("Bratsk","Yakutsk");
        addConnection("Bratsk","Neyungri");
        addConnection("Bratsk","Magadan");
        
        addConnection("Achinsk","Vorkuta");
        addConnection("Achinsk","Ulan-Ude");
        addConnection("Achinsk","Chengdu");
        addConnection("Achinsk","Neyungri");
        addConnection("Achinsk","Bratsk");
        addConnection("Achinsk","Yakutsk");
        
        addConnection("Ulan-Ude","Ajmer");
        addConnection("Ulan-Ude","Erdenet");
        addConnection("Ulan-Ude","Kansk");
        addConnection("Ulan-Ude","Vorkuta");
        addConnection("Ulan-Ude","Achinsk");
        addConnection("Ulan-Ude","Chengdu");
        
        addConnection("Ajmer","Erdenet");
        addConnection("Ajmer","Lao");
        addConnection("Ajmer","Chengdu");
        addConnection("Ajmer","Ulan-Ude");
        
        addConnection("Kansk","Oulu");
        addConnection("Kansk","Lida");
        addConnection("Kansk","Temi");
        addConnection("Kansk","Erdenet");
        addConnection("Kansk","Ulan-Ude");
        addConnection("Kansk","Vorkuta");
        
        addConnection("Vorkuta","Kansk");
        addConnection("Vorkuta","Achinsk");
        
        addConnection("Erdenet","Ajmer");
        addConnection("Erdenet","Ulan-Ude");
        addConnection("Erdenet","Kansk");
        addConnection("Erdenet","Temi");
        addConnection("Erdenet","Mut");
        addConnection("Erdenet","Dessie");
        
        addConnection("Lida","Kansk");
        addConnection("Lida","Temi");
        addConnection("Lida","Oulu");
        addConnection("Lida","Gijon");

        addConnection("Oulu","Lida");
        addConnection("Oulu","Evel");
        addConnection("Oulu","Reykjavik");
        addConnection("Oulu","Kansk");
        
        addConnection("Evel","Reykjavik");
        addConnection("Evel","Lida");
        addConnection("Evel","Gijon");
        addConnection("Evel","Oulu");
        
        addConnection("Gijon","Temi");
        addConnection("Gijon","Lida");
        addConnection("Gijon","Evel");
        addConnection("Gijon","Bobo-Dioulasso");
        
        addConnection("Temi","Lida");
        addConnection("Temi","Erdenet");
        addConnection("Temi","Gijon");
        addConnection("Temi","Kansk");
        addConnection("Temi","Mut");
        addConnection("Temi","Bobo-Dioulasso");
        
        addConnection("Reykjavik","Qaanaaq");
        addConnection("Reykjavik","Evel");
        addConnection("Reykjavik","Oulu");
        
        addConnection("Qaanaaq","Yellowknife");
        addConnection("Qaanaaq","Saguenay");
        addConnection("Qaanaaq","Manitoba");
        addConnection("Qaanaaq","Reykjavik");
        
        addConnection("Saguenay","Manitoba");
        addConnection("Saguenay","Qaanaaq");
        
        addConnection("Manitoba","Yellowknife");
        addConnection("Manitoba","Terrace");
        addConnection("Manitoba","Riverton");
        addConnection("Manitoba","Hoover");
        addConnection("Manitoba","Saguenay");
        addConnection("Manitoba","Qaanaaq");
        
        addConnection("Yellowknife","Fairbanks");
        addConnection("Yellowknife","Terrace");
        addConnection("Yellowknife","Qaanaaq");
        addConnection("Yellowknife","Manitoba");
        
        addConnection("Terrace","Fairbanks");
        addConnection("Terrace","Riverton");
        addConnection("Terrace","Yellowknife");
        addConnection("Terrace","Manitoba");
        
        addConnection("Riverton","Teape");
        addConnection("Riverton","Hoover");
        addConnection("Riverton","Terrace");
        addConnection("Riverton","Manitoba");
        
        addConnection("Hoover","Teape");
        addConnection("Hoover","Riverton");
        addConnection("Hoover","Manitoba");
        
        addConnection("Teape","Riverton");
        addConnection("Teape","Hoover");
        addConnection("Teape","Sipapo");
        
        addConnection("Fairbanks","Magadan");
        addConnection("Fairbanks","Yellowknife");
        addConnection("Fairbanks","Terrace");
        
        addConnection("Sipapo","Potosi");
        addConnection("Sipapo","Bahia");
        addConnection("Sipapo","Teape");
        
        addConnection("Potosi","Bahia");
        addConnection("Potosi","Tandil");
        addConnection("Potosi","Sipapo");
        
        addConnection("Bahia","Tandil");
        addConnection("Bahia","Bobo-Dioulasso");
        addConnection("Bahia","Potosi");
        addConnection("Bahia","Sipapo");

        addConnection("Tandil","Bahia");
        addConnection("Tandil","Potosi");
        
        addConnection("Bobo-Dioulasso","Mut");
        addConnection("Bobo-Dioulasso","Dessie");
        addConnection("Bobo-Dioulasso","Likasi");
        addConnection("Bobo-Dioulasso","Bahia");
        addConnection("Bobo-Dioulasso","Gijon");
        addConnection("Bobo-Dioulasso","Temi");
        
        addConnection("Mut","Dessie");
        addConnection("Mut","Erdenet");
        addConnection("Mut","Bobo-Dioulasso");
        addConnection("Mut","Temi");
        
        addConnection("Likasi","Dessie");
        addConnection("Likasi","Cradock");
        addConnection("Likasi","Bobo-Dioulasso");
        
        addConnection("Dessie","Erdenet");
        addConnection("Dessie","Mut");
        addConnection("Dessie","Bobo-Dioulasso");
        addConnection("Dessie","Likasi");
        addConnection("Dessie","Cradock");
        addConnection("Dessie","Saka");
        
        addConnection("Saka","Dessie");
        addConnection("Saka","Cradock");

        addConnection("Cradock","Saka");
        addConnection("Cradock","Dessie");
        addConnection("Cradock","Likasi");
    }
    catch(RiskException &e){
        wxMessageBox(e.msg);
    }
}

Region & Board::region(std::string name){
	for(int i = 0; i < _board.size(); ++i){
		if(_board[i].name() == name)
			return _board[i];
	}
	
	throw NoSuchRegionException(name);
}

Region & Board::region(unsigned int id){
	return _board.at(id);
}

Board & Board::instance(){
	static Board board;
	return board;
}




void Board::addConnection(std::string reg1, std::string reg2){
    region(reg1).addNeighbor(region(reg2).id());
    region(reg1).addNeighbor(region(reg1).id());
}


unsigned int Board::numberOfRegions(){
    return _board.size();
}
