#ifndef PLAYERSDATA_H
#define PLAYERSDATA_H
#include <vector>
#include <string>

#include "Player.h"

#ifndef MAX_PLAYERS
    #define MAX_PLAYERS 6
#endif

enum PlayerColor;

///Klasa-singleton przechowuj¹ca informacje o graczach
class PlayersData{
private:
    std::vector<Player> _players;
	PlayersData();
	PlayersData(const PlayersData &p);
	PlayersData &operator=(const PlayersData &p);
public:
	static PlayersData &instance();
    Player & player(unsigned int id);
    void addPlayer(Player player);
    unsigned int numberOfPlayers();
};






#endif
