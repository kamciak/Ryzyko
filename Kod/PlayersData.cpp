#include "PlayersData.h"
#include "MenuDlg.h"
#include <sstream>

PlayersData::PlayersData(){}

PlayersData &PlayersData::instance(){
	static PlayersData pd;
	return pd;
}

Player & PlayersData::player(unsigned int id){
    return _players.at(id);
}

void PlayersData::addPlayer(Player player){
    _players.push_back(player);
}

unsigned int PlayersData::numberOfPlayers(){
    return _players.size();
}   
