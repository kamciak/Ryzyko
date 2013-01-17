#include "Controller.h"
#include "RiskFrm.h"
#include "Phase.h"
#include "Util.h"
#include "NumberChoiceDialog.h"
#include "SoundController.h"
#include <algorithm>

#define ROLL_D6 (rand()%6+1)


void Controller::setSelectedRegion(unsigned int id){
    _selected_region = id;
    _window.paintSelectedRegion(id);
}
    
void Controller::startPhase(PhaseName phase){
    wxDELETE(_current_phase);
    switch(phase){
        case SETUP:
            _current_phase = new SetupPhase(*this);
            _armies_to_distribute = 50 - 5 * PlayersData::instance().numberOfPlayers(); 
            break;
        case REINFORCE:            
            _current_phase = new ReinforcePhase(*this);
            _current_player++;
            if(_current_player == _players_queue.end())
                _current_player = _players_queue.begin();
            calculateNumberOfRecruits();
            showCardsDialog();
            _window.endPhaseButtonEnabled(false);
            break;
        case ATTACK:
            _current_phase = new AttackPhase(*this);  
            _window.endPhaseButtonEnabled(true);
            break;
        case FORTIFY:
            _current_phase = new FortifyPhase(*this);
            _window.endPhaseButtonEnabled(true);
            break;
    }
}

void Controller::nextPhase(){    
    setSelectedRegion(NO_REGION_SELECTED);
    PhaseName phase = getPhaseName();
    switch(phase){
        case SETUP:
            _current_player++;
            if(_current_player == _players_queue.end()){
                _current_player = _players_queue.begin();            
                --_armies_to_distribute;
            }
            if(_armies_to_distribute == 0){                
                if(_skip_reinforce){
                    _skip_reinforce = false;
                    startPhase(ATTACK);
                }   
                else{
                    --_current_player;
                    startPhase(REINFORCE);     
                }           
            }
            break;
        case REINFORCE:
            startPhase(ATTACK);
            break;
        case ATTACK:
            startPhase(FORTIFY);
            attacker_rolls.clear();
            defender_rolls.clear();
            break;
        case FORTIFY:
            if(_conquest_flag){
                giveCard(currentPlayer(), CardsData::instance().deck().drawCard());
                _conquest_flag = false;
            }        
            startPhase(REINFORCE);
            break;
    }
   _window.setDrawFlag();
}

Controller::Controller(RiskFrm & window) 
    : _window(window), _selected_region(NO_REGION_SELECTED){    
    _conquest_flag = false;
    _sets_exchanged = 0;
}

Controller::~Controller(){
    delete _current_phase;
}

void Controller::regionClicked(unsigned int id){
    _current_phase -> handleRegionClicked(id);
}


unsigned int Controller::selectedRegion(){
    return _selected_region;
}

unsigned int Controller::currentPlayer(){
    return *_current_player;
}


bool Controller::initPlayers(){
    bool color_taken[NUMBER_OF_COLORS];
    for(int i = 0; i < NUMBER_OF_COLORS; ++i){
        color_taken[i] = false;
    }

    std::vector<Player> players;
    PlayersData &pd = PlayersData::instance();
    MenuDlg &menu = *(_window.menu);

    int sel = menu.WxBitmapComboBox1->GetCurrentSelection();
    wxString name = menu.WxEdit1->GetValue();
    if(name == "")
        name = "Gracz 1";
    
    if(sel >= 0 && sel < NUMBER_OF_COLORS){        
        color_taken[sel] = true;
        players.push_back(Player(name, PlayerColor(sel)));
    }
    else{
        wxMessageBox("Wybierz kolor gracza 1!");
        return false;
    }

    sel = menu.WxBitmapComboBox2->GetCurrentSelection();

    name = menu.WxEdit2->GetValue();    
    if(name == "")
        name = "Gracz 2";
    
    if(sel >= 0 && sel < NUMBER_OF_COLORS){
        if(color_taken[sel]){
            wxMessageBox("Kolory graczy musz¹ byæ unikalne!");
            return false;
        }
        color_taken[sel] = true;
        players.push_back(Player(name, PlayerColor(sel)));
    }
    else{
        wxMessageBox("Wybierz kolor gracza 2!");
        return false;
    }

    if(menu.isPlayer3){
        sel = menu.WxBitmapComboBox3->GetCurrentSelection();
        name = menu.WxEdit3->GetValue();
        if(name == "")
            name = "Gracz 3";
    
        if(sel >= 0 && sel < NUMBER_OF_COLORS){
            if(color_taken[sel]){
                wxMessageBox("Kolory graczy musz¹ byæ unikalne!");
                return false;
            }
            color_taken[sel] = true;
            players.push_back(Player(name, PlayerColor(sel)));
        }
        else{
            wxMessageBox("Wybierz kolor gracza 3!");
            return false;
        }
    }

    if(menu.isPlayer4){
        sel = menu.WxBitmapComboBox4->GetCurrentSelection();
        name = menu.WxEdit4->GetValue();
        if(name == "")
            name = "Gracz 4";
    
        if(sel >= 0 && sel < NUMBER_OF_COLORS){
            if(color_taken[sel]){
                wxMessageBox("Kolory graczy musz¹ byæ unikalne!");
                return false;
            }
            color_taken[sel] = true;
            players.push_back(Player(name, PlayerColor(sel)));
        }
        else{
            wxMessageBox("Wybierz kolor gracza 4!");
            return false;
        }
    }

    if(menu.isPlayer5){
        sel = menu.WxBitmapComboBox5->GetCurrentSelection();
        name = menu.WxEdit5->GetValue();
        if(name == "")
            name = "Gracz 5";
    
        if(sel >= 0 && sel < NUMBER_OF_COLORS){
            if(color_taken[sel]){
                wxMessageBox("Kolory graczy musz¹ byæ unikalne!");
                return false;
            }
            color_taken[sel] = true;
            players.push_back(Player(name, PlayerColor(sel)));
        }
        else{
            wxMessageBox("Wybierz kolor gracza 5!");
            return false;
        }
    }

    if(menu.isPlayer6){
        sel = menu.WxBitmapComboBox6->GetCurrentSelection();
        name = menu.WxEdit6->GetValue();
        if(name == "")
            name = "Gracz 6";
    
        if(sel >= 0 && sel < NUMBER_OF_COLORS){
            if(color_taken[sel]){
                wxMessageBox("Kolory graczy musz¹ byæ unikalne!");
                return false;
            }
            color_taken[sel] = true;
            players.push_back(Player(name, PlayerColor(sel)));
        }
        else{
            wxMessageBox("Wybierz kolor gracza 6!");
            return false;
        }
    }
    
    for(int i = 0; i < players.size(); ++i){
        pd.addPlayer(players[i]);
    }

    for(int i = 0; i < pd.numberOfPlayers(); ++i){
        _players_queue.push_back(i);
    }
    srand(time(0));
    std::random_shuffle(_players_queue.begin(),_players_queue.end());
    _current_player = _players_queue.begin();
    _skip_reinforce = _players_queue.size() == 2 ? true : false;
    startPhase(SETUP);
    SoundController::playSound(START_GAME);    
    return true;
    
}

bool Controller::allRegionsTaken(){
    Board & board = Board::instance();
    for(int i = 0; i < board.numberOfRegions(); ++i){
        if(board.region(i).owner() == NO_OWNER)
            return false;
    }
    return true;
}



std::vector<RegionDrawInformation> Controller::getRegionDrawInfo(bool big_image){
    std::vector<RegionDrawInformation> draw_info;
    for(int id = 0; id < Board::instance().numberOfRegions(); ++id){
        wxPoint prescale = Board::instance().region(id).center();
        double scale = _window.GetSize().GetWidth()/1366.0;

        wxPoint postscale(prescale.x * scale, prescale.y * scale); 
        unsigned int armies = Board::instance().region(id).armyCount();

        unsigned int owner_id = Board::instance().region(id).owner();
        if(owner_id != NO_OWNER){
            wxImage & image = PlayersData::instance().player(owner_id).image(big_image);
    
            draw_info.push_back(RegionDrawInformation(postscale,image,armies));
        }
    }
    return draw_info;
}

std::vector<PlayerDrawInfo> Controller::getPlayerDrawInfo(){
    PlayersData & pd = PlayersData::instance();
    std::vector<PlayerDrawInfo> col;
    std::vector<unsigned int>::iterator i;
    for(i = _players_queue.begin(); i != _players_queue.end(); ++i){
        col.push_back(PlayerDrawInfo(*i == currentPlayer(), pd.player(*i).color(), regionsOwnedByPlayer(*i), pd.player(*i).name()));
    }
    return col;
}

unsigned int Controller::regionsOwnedByPlayer(unsigned int player_id){
    unsigned int count = 0;
    for(int i = 0; i < Board::instance().numberOfRegions(); ++i){
        if(Board::instance().region(i).owner() == player_id)
            ++count;
    }
    return count;
}

void Controller::calculateNumberOfRecruits(){
    unsigned int player_id = currentPlayer();
    Board & board = Board::instance();
    int total = 0;
    int standard = 0;
    for(int i = 0; i < board.numberOfRegions(); ++i){
        if(board.region(i).owner() == player_id)
            ++standard;
    }
    standard = (standard/3) < 3 ? 3 : (standard/3);
    
    total += standard;

//Kontrola nad kontynentami:
    //Azja:
    if(board.region("Erdenet").owner() == player_id &&
    board.region("Ulan-Ude").owner() == player_id &&
    board.region("Vorkuta").owner() == player_id &&    
    board.region("Achinsk").owner() == player_id &&    
    board.region("Bratsk").owner() == player_id &&    
    board.region("Yakutsk").owner() == player_id &&    
    board.region("Neyungri").owner() == player_id &&    
    board.region("Ajmer").owner() == player_id &&    
    board.region("Lao").owner() == player_id &&    
    board.region("Chengdu").owner() == player_id &&    
    board.region("Magadan").owner() == player_id &&    
    board.region("Aomori").owner() == player_id){
        //_window.info("\tKontrola nad Azj¹: 7");
        total += 7;
    }            

    //Ameryka Pó³nocna: 
    if(board.region("Fairbanks").owner() == player_id &&
    board.region("Terrace").owner() == player_id &&
    board.region("Yellowknife").owner() == player_id &&    
    board.region("Manitoba").owner() == player_id &&    
    board.region("Saguenay").owner() == player_id &&    
    board.region("Riverton").owner() == player_id &&    
    board.region("Hoover").owner() == player_id &&    
    board.region("Teape").owner() == player_id &&    
    board.region("Qaanaaq").owner() == player_id){
        //_window.info("\tKontrola nad Ameryk¹ Pó³nocn¹: 5");
        total += 5;
    }    

    //Europa:
    if(board.region("Reykjavik").owner() == player_id &&
    board.region("Evel").owner() == player_id &&
    board.region("Oulu").owner() == player_id &&    
    board.region("Lida").owner() == player_id &&    
    board.region("Gijon").owner() == player_id &&    
    board.region("Temi").owner() == player_id &&    
    board.region("Kansk").owner() == player_id){
        //_window.info("\tKontrola nad Europ¹: 5");
        total += 5;
    }

    //Afryka:
    if(board.region("Bobo-Dioulasso").owner() == player_id &&
    board.region("Mut").owner() == player_id &&
    board.region("Dessie").owner() == player_id &&    
    board.region("Likasi").owner() == player_id &&    
    board.region("Cradock").owner() == player_id &&    
    board.region("Saka").owner() == player_id){
        //_window.info("\tKontrola nad Afryk¹: 3");
        total += 3;
    }
    
    //Australia:
    if(board.region("Kapit").owner() == player_id &&
    board.region("Jayapura").owner() == player_id &&
    board.region("Karratha").owner() == player_id &&    
    board.region("Yeppon").owner() == player_id){
        //_window.info("\tKontrola nad Australi¹: 2");
        total += 2;
    }    
    //Ameryka Po³udniowa
    if(board.region("Sipapo").owner() == player_id &&
    board.region("Potosi").owner() == player_id &&
    board.region("Bahia").owner() == player_id &&    
    board.region("Tandil").owner() == player_id){
        //_window.info("\tKontrola nad Ameryk¹ Po³udniow¹: 2");
        total += 2;
    }    

    //_window.info("\tRazem:"+intToString(total));
    _armies_to_distribute = total;
    
}

unsigned int Controller::armiesToDistribute(){
    return _armies_to_distribute;
}

void Controller::recruitArmies(unsigned int region_id, unsigned int amount){
    Board::instance().region(region_id).addArmies(amount);
    _armies_to_distribute -= amount;
    if(_armies_to_distribute != 0){
        //_window.info("Armii do rozmieszczenia: "+intToString(_armies_to_distribute));
    }
}

void Controller::giveCard(unsigned int player_id, RiskCard * card){
    if(card)
        PlayersData::instance().player(player_id).hand.push_back(card);
}

void Controller::combat(unsigned int attacker, unsigned int defender){   
    
    Board & board = Board::instance();

    unsigned int attacking_player = board.region(attacker).owner();
    unsigned int defending_player = board.region(defender).owner();

	unsigned int atk_dice = board.region(attacker).armyCount() > 4 ? 3 : board.region(attacker).armyCount() - 1;
	unsigned int def_dice = board.region(defender).armyCount() > 1 ? 2 : 1;
	
	std::vector<unsigned int> atk_rolls;
	std::vector<unsigned int> def_rolls;
	
	for(int i = 0; i < atk_dice; ++i){
		atk_rolls.push_back(ROLL_D6);
	}
	
	for(int i = 0; i < def_dice; ++i){
		def_rolls.push_back(ROLL_D6);
	}
	
	std::sort(atk_rolls.rbegin(),atk_rolls.rend());
	std::sort(def_rolls.rbegin(),def_rolls.rend());

    attacker_rolls = atk_rolls;
    defender_rolls = def_rolls;    
	
	unsigned int comparisons = atk_dice > def_dice ? def_dice : atk_dice;
	
	int atk_losses=0;
	int def_losses=0;
	
	for(int i = 0; i < comparisons; ++i){
		if(atk_rolls[i] > def_rolls[i])
			++def_losses;
		else
			++atk_losses;
	}
	
    board.region(attacker).removeArmies(atk_losses);
    board.region(defender).removeArmies(def_losses);
    if(board.region(attacker).armyCount() == 1)
        setSelectedRegion(NO_REGION_SELECTED);
    
    if(board.region(defender).armyCount() == 0){
        SoundController::playSound(REGION_CONQUERED);
        _conquest_flag = true;
        
        

        //sprawdzenie czy wlasciciel podbitego regionu kontroluje jeszcze jakies regiony
        bool owns = false;
        for(int i = 0; i < board.numberOfRegions(); ++i){
            if(i != defender && board.region(i).owner() == defending_player)
                owns = true;
        }
        //przemieszczenie armi armii z regionu atakujacego do atakowanego
        board.region(defender).setOwner(attacking_player);
        showFortifyDialog(attacker,defender,false);
        setSelectedRegion(NO_REGION_SELECTED);

        if(!owns){
            _window.setPermaDraw();
            wxMessageBox(PlayersData::instance().player(defending_player).name()+" przegrywa!");
            _window.unsetPermaDraw();
            std::vector<unsigned int>::iterator iter;
            for(iter = _players_queue.begin(); iter != _players_queue.end(); ++iter){
                if(*iter == defending_player){
                    _players_queue.erase(iter);
                    break;
                }                    
            }   
            if(_players_queue.size() == 1){
                _window.setPermaDraw();
                wxMessageBox(PlayersData::instance().player(currentPlayer()).name()+" wygrywa!");
                _window.setPermaDraw();
                wxExit();
            }
        }   
        
        
        
        
    }

}

PhaseName Controller::getPhaseName(){
    return _current_phase->phaseName();
}

void Controller::showFortifyDialog(unsigned int region_start, unsigned int region_end, bool optional){
    Board & board = Board::instance();
    unsigned int army_count = board.region(selectedRegion()).armyCount(); 
    _window.setPermaDraw();          
    NumberChoiceDialog * s = new NumberChoiceDialog(*this,1,army_count - 1,region_start,region_end, optional, &_window);
    s->ShowModal();
    _window.unsetPermaDraw();
    wxDELETE(s);
}

void Controller::showCardsDialog(){
    if(PlayersData::instance().player(currentPlayer()).hand.size() > 0){
        _window.setPermaDraw();
        CardDialog * dlg = new CardDialog(*this,&_window);
        dlg->ShowModal();
        wxDELETE(dlg);
        _window.unsetPermaDraw();
    }    
    
}

void Controller::moveArmies(unsigned region_start, unsigned region_end, unsigned number){
    Board & board = Board::instance();
    board.region(region_start).removeArmies(number);
    board.region(region_end).addArmies(number);
    if(getPhaseName() == FORTIFY){
        nextPhase();
    }
}

bool Controller::mustExchange(){
    return (PlayersData::instance().player(currentPlayer()).hand.size() > 4);
}

bool Controller::hasThreeOfAKind(){
    std::vector<RiskCard*> & hand = PlayersData::instance().player(currentPlayer()).hand;
    int count[3] = {0,0,0};
    for(int i = 0; i < hand.size(); ++i){
        switch(hand[i]->getArmy()){
            case 'i':
                count[0]++;
                break;
            case 'c':
                count[1]++;
                break;
            case 'a':
                count[2]++;
                break;
        }
    }
    if(count[0] >= 3 || count[1] >= 3 || count[2] >= 3)
        return true;
    else
        return false;
}

bool Controller::hasThreeDifferent(){
    std::vector<RiskCard*> & hand = PlayersData::instance().player(currentPlayer()).hand;
    int count[3] = {0,0,0};
    for(int i = 0; i < hand.size(); ++i){
        switch(hand[i]->getArmy()){
            case 'i':
                count[0]++;
                break;
            case 'c':
                count[1]++;
                break;
            case 'a':
                count[2]++;
                break;
        }
    }
    if(count[0] > 0 && count[1] > 0 && count[2] > 0)
        return true;
    else
        return false;
}

std::vector<CardDrawInfo> Controller::getCardDrawInfo(){
    std::vector<RiskCard*> & hand = PlayersData::instance().player(currentPlayer()).hand;
    std::vector<CardDrawInfo> result;
    for(int i = 0; i < hand.size(); ++i){
        std::string region = hand[i]->getRegion();
        wxBitmap * bmp;
        switch(hand[i]->getArmy()){
            case 'i':
                bmp = CardsData::instance().infantryBitmap();
                break;
            case 'c':
                bmp = CardsData::instance().cavalryBitmap();
                break;
            case 'a':
                bmp = CardsData::instance().artilleryBitmap();
                break;
        }
        result.push_back(CardDrawInfo(region, bmp));
    }   
    return result;
}

void Controller::exchangeSame(){
    std::vector<RiskCard*> & hand = PlayersData::instance().player(currentPlayer()).hand;
    int count[3] = {0,0,0};
    for(int i = 0; i < hand.size(); ++i){
        switch(hand[i]->getArmy()){
            case 'i':
                count[0]++;
                break;
            case 'c':
                count[1]++;
                break;
            case 'a':
                count[2]++;
                break;
        }
    }
    
    char type;
    if(count[0] >= 3){
        type = 'i';
    }
    else if(count[1] >= 3){
        type = 'c';
    }
    else if(count[2] >= 3){
        type = 'a';
    }
    for(int i = 0; i < 3; i++){
        std::vector<RiskCard*>::iterator iter;  
        for(iter = hand.begin(); (*iter)->getArmy() != type; ++iter);
        if(Board::instance().region((*iter)->getRegion()).owner() == currentPlayer())
            Board::instance().region((*iter)->getRegion()).addArmies(2);
        hand.erase(iter);
    }    
    _armies_to_distribute += CardDialog::set_values[_sets_exchanged];
    _sets_exchanged++;
}

void Controller::exchangeDifferent(){
    std::vector<RiskCard*> & hand = PlayersData::instance().player(currentPlayer()).hand;
    int count[3] = {0,0,0};
    for(int i = 0; i < hand.size(); ++i){
        switch(hand[i]->getArmy()){
            case 'i':
                count[0]++;
                break;
            case 'c':
                count[1]++;
                break;
            case 'a':
                count[2]++;
                break;
        }
    }
    std::vector<RiskCard*>::iterator iter; 
    for(iter = hand.begin(); (*iter)->getArmy() != 'i'; ++iter);
    if(Board::instance().region((*iter)->getRegion()).owner() == currentPlayer())
        Board::instance().region((*iter)->getRegion()).addArmies(2);
    hand.erase(iter);

    for(iter = hand.begin(); (*iter)->getArmy() != 'c'; ++iter);
    if(Board::instance().region((*iter)->getRegion()).owner() == currentPlayer())
       Board::instance().region((*iter)->getRegion()).addArmies(2);
    hand.erase(iter);

    for(iter = hand.begin(); (*iter)->getArmy() != 'a'; ++iter);
    if(Board::instance().region((*iter)->getRegion()).owner() == currentPlayer())
        Board::instance().region((*iter)->getRegion()).addArmies(2);
    hand.erase(iter);

    _armies_to_distribute += CardDialog::set_values[_sets_exchanged];
    _sets_exchanged++;
}

unsigned int Controller::exchangedSets(){
    return _sets_exchanged;
}
