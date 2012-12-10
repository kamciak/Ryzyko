#include "PlayersData.h"
#include "MenuDlg.h"

PlayersData::PlayersData(){
	_names.push_back("Gracz 1");
	_names.push_back("Gracz 2");
	_names.push_back("Gracz 3");
	_names.push_back("Gracz 4");
	_names.push_back("Gracz 5");
	_names.push_back("Gracz 6");
	_used.push_back(true);
	_used.push_back(true);
	_used.push_back(false);
	_used.push_back(false);
	_used.push_back(false);
	_used.push_back(false);
	_colors.push_back(PlayerColor(1));
	_colors.push_back(PlayerColor(2));
	_colors.push_back(PlayerColor(3));
	_colors.push_back(PlayerColor(4));
	_colors.push_back(PlayerColor(5));
	_colors.push_back(PlayerColor(6));
}

PlayersData &PlayersData::instance(){
	static PlayersData _pd;
	return _pd;
}

void PlayersData::setPlayerName(unsigned int id, std::string s){
	_names.at(id)=s;
}

void PlayersData::setPlayerColor(unsigned int id, PlayerColor color){
	_colors.at(id)=color;
}

void PlayersData::setPlayerUsed(unsigned int id, bool b){
	_used.at(id)=b;
}

std::string PlayersData::getPlayerName(unsigned int id){
	return _names.at(id);
}

PlayerColor PlayersData::getPlayerColor(unsigned int id){
	return _colors.at(id);
}
	
bool PlayersData::getPlayerUsed(unsigned int id){
	return _used.at(id);
}

