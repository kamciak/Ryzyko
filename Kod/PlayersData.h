#ifndef PLAYERSDATA_H
#define PLAYERSDATA_H
#include <vector>
#include <string>

#define MAX_PLAYERS 6
#include "MenuDlg.h"
enum PlayerColor;

///Klasa-singleton przechowuj¹ca informacje o graczach
class PlayersData{
private:
	std::vector<std::string> _names;
	std::vector<PlayerColor> _colors;
	std::vector<bool> _used;
	PlayersData();
	PlayersData(const PlayersData &p);
	PlayersData &operator=(const PlayersData &p);
public:
	static PlayersData &instance();
	void setPlayerName(unsigned int id, std::string s);
	void setPlayerColor(unsigned int id, PlayerColor color);
	void setPlayerUsed(unsigned int id, bool b);
	std::string getPlayerName(unsigned int id);
	PlayerColor getPlayerColor(unsigned int id);
	bool getPlayerUsed(unsigned int id);
};






#endif
