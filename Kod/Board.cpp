#include "Board.h"

Board::Board(){
	_board.push_back(Region(_board.size(),"TestRegion1"));
	_board.push_back(Region(_board.size(),"TestRegion2"));
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

void Board::combat(unsigned int attacker, unsigned int defender){
	BattleResults br = region(attacker).attack(region(defender));
	//TODO - rozkaz oknu wyswietlic odpowiednie animacje (atak, zwyciestwo/porazka + kosci) i komunikaty 
	br.attacker.removeArmies(br.atk_losses);
	br.defender.removeArmies(br.def_losses);
}

