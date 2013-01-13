#include "Controller.h"
#include "RiskFrm.h"
#include "Phase.h"
#include "Util.h"
#include <algorithm>

#define ROLL_D6 (rand()%6+1)

void Controller::setSelectedRegion(unsigned int id){
    _selected_region = id;
    _window.paintSelectedRegion(id);
}
    
void Controller::nextPhase(){
    if(dynamic_cast<SetupPhase*>(_current_phase)){
        _current_player++;
        if(_current_player == _players_queue.end()){
            _current_player = _players_queue.begin();
            
            --_armies_to_distribute;
            if(_armies_to_distribute != 0){
                _window.info("Wojsk do rozmieszczenia: "+intToString(_armies_to_distribute));                
            }
            else{
                startGame();
            }
        }
        //startGame moze zmienic aktualna faze - w takim wypadku nie wypisuj aktualnego gracza
        if(dynamic_cast<SetupPhase*>(_current_phase))
            _window.info("Aktualny gracz :"+PlayersData::instance().player(currentPlayer()).name());
    }
    else if(dynamic_cast<ReinforcePhase*>(_current_phase)){
        delete _current_phase;
        _current_phase = new AttackPhase(*this);
        _window.info("Faza Walki: kliknij na swój region z dwoma lub wiêcej jednostkami, a nastêpnie na s¹siedni wrogi region, aby go zaatakowaæ");
        
    }
    else if(dynamic_cast<AttackPhase*>(_current_phase)){
        delete _current_phase;
        _current_phase = new FortifyPhase(*this);
        _window.info("Faza ruchu: kliknij na jeden ze swoich regionów z dwoma lub wiêcej jednostkami, a nastêpnie któryœ ze swoich s¹siednich regionów aby przemieœciæ tam wojska");
    }
    else if(dynamic_cast<FortifyPhase*>(_current_phase)){
        _current_player++;
        if(_current_player == _players_queue.end())
            _current_player = _players_queue.begin();        
        delete _current_phase;
        _current_phase = new ReinforcePhase(*this);
        _window.info("Faza Rekrutacji: kliknij na jeden ze swoich regionów aby umieœciæ tam dodatkowe jednostki");
        calculateNumberOfRecruits(currentPlayer());
        
    }
    
}

Controller::Controller(RiskFrm & window) 
    : _window(window), _selected_region(NO_REGION_SELECTED){
    _current_phase = new SetupPhase(*this);
    _window.info("Faza rozmieszczania wojsk: Wybierz jeden z wolnych regionów (lub jeden ze swoich, jeœli wszystkie s¹ zajête), aby umieœciæ tam jednostkê");
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
    PlayersData &pd = PlayersData::instance();
    MenuDlg &menu = *(_window.menu);

    int sel = menu.WxBitmapComboBox1->GetCurrentSelection();
    wxString name = menu.WxEdit1->GetValue();
    if(name == "")
        name = "Gracz 1";
    
    if(sel >= 0 && sel <= 9){
        pd.addPlayer(Player(name, PlayerColor(sel)));
    }
    else{
        wxMessageBox("Wybierz kolor gracza 1!");
        return false;
    }

    sel = menu.WxBitmapComboBox2->GetCurrentSelection();
    name = menu.WxEdit2->GetValue();
    if(name == "")
        name = "Gracz 2";
    
    if(sel >= 0 && sel <= 9){
        pd.addPlayer(Player(name, PlayerColor(sel)));
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
    
        if(sel >= 0 && sel <= 9){
            pd.addPlayer(Player(name, PlayerColor(sel)));
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
    
        if(sel >= 0 && sel <= 9){
            pd.addPlayer(Player(name, PlayerColor(sel)));
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
    
        if(sel >= 0 && sel <= 9){
            pd.addPlayer(Player(name, PlayerColor(sel)));
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
    
        if(sel >= 0 && sel <= 9){
            pd.addPlayer(Player(name, PlayerColor(sel)));
        }
        else{
            wxMessageBox("Wybierz kolor gracza 6!");
            return false;
        }
    }
    
    for(int i = 0; i < pd.numberOfPlayers(); ++i){
        _players_queue.push_back(i);
    }
    std::random_shuffle(_players_queue.begin(),_players_queue.end());
    _current_player = _players_queue.begin();

    _armies_to_distribute = 50-(pd.numberOfPlayers() * 5);
    _window.info("Wojsk do roznmieszczenia:"+intToString(_armies_to_distribute));
    return true;
    
}

bool Controller::allRegionsTaken(){
    Board & board = Board::instance();
    for(int i = 0; i < board.numberOfRegions(); ++i){
        if(board.region(i).controller() == NO_CONTROLLER)
            return false;
    }
    return true;
}


void Controller::startGame(){
    delete _current_phase;
    _current_phase = new ReinforcePhase(*this);
    _window.info("Aktualny gracz: "+PlayersData::instance().player(currentPlayer()).name());
    _window.info("Faza Rekrutacji: kliknij na jeden ze swoich regionów aby umieœciæ tam dodatkowe jednostki");
    calculateNumberOfRecruits(currentPlayer());
}

std::vector<RegionDrawInformation> Controller::getRegionDrawInfo(){
    std::vector<RegionDrawInformation> draw_info;
    for(int id = 0; id < Board::instance().numberOfRegions(); ++id){
        wxPoint prescale = Board::instance().region(id).center();
        double scale = _window.GetSize().GetWidth()/1366.0;

        wxPoint postscale(prescale.x * scale, prescale.y * scale); 
        unsigned int armies = Board::instance().region(id).armyCount();

        unsigned int controller_id = Board::instance().region(id).controller();
        if(controller_id != NO_CONTROLLER){
            wxImage & image = PlayersData::instance().player(controller_id).image();
    
            draw_info.push_back(RegionDrawInformation(postscale,image,armies));
        }
    }
    return draw_info;
}


void Controller::calculateNumberOfRecruits(unsigned int player_id){
    Board & board = Board::instance();
    int total = 0;
    int standard = 0;
    for(int i = 0; i < board.numberOfRegions(); ++i){
        if(board.region(i).controller() == player_id)
            ++standard;
    }
    standard = (standard/3) < 3 ? 3 : (standard/3);
    _window.info("Iloœæ armii do rozmiesczenia:");
    _window.info("\tPodstawowy przyrost: "+intToString(standard));
    
    total += standard;

//Kontrola nad kontynentami:
    //Azja:
    if(board.region("Erdenet").controller() == player_id &&
    board.region("Ulan-Ude").controller() == player_id &&
    board.region("Vorkuta").controller() == player_id &&    
    board.region("Achinsk").controller() == player_id &&    
    board.region("Bratsk").controller() == player_id &&    
    board.region("Yakutsk").controller() == player_id &&    
    board.region("Neyungri").controller() == player_id &&    
    board.region("Ajmer").controller() == player_id &&    
    board.region("Lao").controller() == player_id &&    
    board.region("Chengdu").controller() == player_id &&    
    board.region("Magadan").controller() == player_id &&    
    board.region("Aomori").controller() == player_id){
        _window.info("\tKontrola nad Azj¹: 7");
        total += 7;
    }            

    //Ameryka Pó³nocna: 
    if(board.region("Fairbanks").controller() == player_id &&
    board.region("Terrace").controller() == player_id &&
    board.region("Yellowknife").controller() == player_id &&    
    board.region("Manitoba").controller() == player_id &&    
    board.region("Saguenay").controller() == player_id &&    
    board.region("Riverton").controller() == player_id &&    
    board.region("Hoover").controller() == player_id &&    
    board.region("Teape").controller() == player_id &&    
    board.region("Qaanaaq").controller() == player_id){
        _window.info("\tKontrola nad Ameryk¹ Pó³nocn¹: 5");
        total += 5;
    }    

    //Europa:
    if(board.region("Reykjavik").controller() == player_id &&
    board.region("Evel").controller() == player_id &&
    board.region("Oulu").controller() == player_id &&    
    board.region("Lida").controller() == player_id &&    
    board.region("Gijon").controller() == player_id &&    
    board.region("Temi").controller() == player_id &&    
    board.region("Kansk").controller() == player_id){
        _window.info("\tKontrola nad Europ¹: 5");
        total += 5;
    }

    //Afryka:
    if(board.region("Bobo-Dioulasso").controller() == player_id &&
    board.region("Mut").controller() == player_id &&
    board.region("Dessie").controller() == player_id &&    
    board.region("Likasi").controller() == player_id &&    
    board.region("Cradock").controller() == player_id &&    
    board.region("Saka").controller() == player_id){
        _window.info("\tKontrola nad Afryk¹: 3");
        total += 3;
    }
    
    //Australia:
    if(board.region("Kapit").controller() == player_id &&
    board.region("Jayapura").controller() == player_id &&
    board.region("Karratha").controller() == player_id &&    
    board.region("Yeppon").controller() == player_id){
        _window.info("\tKontrola nad Australi¹: 2");
        total += 2;
    }    
    //Ameryka Po³udniowa
    if(board.region("Sipapo").controller() == player_id &&
    board.region("Potosi").controller() == player_id &&
    board.region("Bahia").controller() == player_id &&    
    board.region("Tandil").controller() == player_id){
        _window.info("\tKontrola nad Ameryk¹ Po³udniow¹: 2");
        total += 2;
    }    

    _window.info("\tRazem:"+intToString(total));
    _armies_to_distribute = total;
    
}

unsigned int Controller::armiesToDistribute(){
    return _armies_to_distribute;
}

void Controller::recruitArmies(unsigned int region_id, unsigned int amount){
    Board::instance().region(region_id).addArmies(amount);
    _armies_to_distribute -= amount;
    if(_armies_to_distribute != 0){
        _window.info("Armii do rozmieszczenia: "+intToString(_armies_to_distribute));
    }
}

void Controller::combat(unsigned int attacker, unsigned int defender){
    srand(time(0));
    Board & board = Board::instance();

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
    if(board.region(defender).armyCount() == 0){
        board.region(defender).setController(currentPlayer());
        board.region(attacker).removeArmies(atk_dice - atk_losses);
        board.region(defender).addArmies(atk_dice - atk_losses);
    }

    //TODO: Kod animacji itd;
    _window.info("Bitwa "+board.region(attacker).name()+"-"+board.region(defender).name());
    _window.info("Wyniki:");
    wxString atk_txt = "\tAtakuj¹cy:";
    wxString def_txt = "\tBroni¹cy :";
    for(int i = 0; i < atk_rolls.size(); ++i){
        atk_txt += " "+intToString(atk_rolls[i]);
    }

    for(int i = 0; i < def_rolls.size(); ++i){
        def_txt += " "+intToString(def_rolls[i]);
    }
    _window.info(atk_txt);
    _window.info(def_txt);
    wxString losses_txt = "Straty: ";
    if(atk_losses != 0){
        losses_txt += ("Atakuj¹cy "+intToString(atk_losses));
        if(def_losses != 0)
            losses_txt += ", ";
    }
    if(def_losses != 0)
        losses_txt += ("Broni¹cy "+intToString(def_losses));

    _window.info(losses_txt);
}
