#ifndef BATTLERESULTS_H
#define BATTLERESULTS_H
#include <vector>
class Region;

class BattleResults{	
public:
	Region & attacker;
	Region & defender;
	
	const unsigned int atk_losses;
	const unsigned int def_losses;	
	
	const std::vector<unsigned int> atk_rolls;
	const std::vector<unsigned int> def_rolls;

	BattleResults(Region & atk, Region & def, std::vector<unsigned int> at_rolls, std::vector<unsigned int> df_rolls, unsigned int atk_loss, unsigned int def_loss)
		: attacker(atk), defender(def), atk_losses(atk_loss), def_losses(def_loss), atk_rolls(at_rolls), def_rolls(df_rolls){
	}
};


#endif
