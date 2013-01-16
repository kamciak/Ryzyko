#include "Phase.h"
#include "Controller.h"
#include "RiskFrm.h"
#include "Board.h"



void FortifyPhase::handleRegionClicked(unsigned int id){
    unsigned int selected_region = _controller.selectedRegion();
    Board & board = Board::instance();
    
    if(board.region(id).owner() == _controller.currentPlayer()){
        if(selected_region == NO_REGION_SELECTED)
            _controller.setSelectedRegion(id);
        else if (board.region(id).isNeighbor(selected_region) 
        && id != selected_region 
        && (board.region(selected_region).armyCount() > 1)){ 
            _controller.showFortifyDialog(selected_region, id);
        }   
        else
            _controller.setSelectedRegion(NO_REGION_SELECTED);
          
    }
    

}

void AttackPhase::handleRegionClicked(unsigned int id){
	unsigned int selected_region = _controller.selectedRegion();
    Board & board = Board::instance();

	if(selected_region != NO_REGION_SELECTED){
	    if(selected_region == id)
            _controller.setSelectedRegion(NO_REGION_SELECTED);
        else{            
            if(board.region(selected_region).isNeighbor(id) && 
            (board.region(selected_region).owner() != board.region(id).owner())){
                if(board.region(selected_region).armyCount() > 1)
                    _controller.combat(selected_region,id);
            }
        }
    }             
    else if(_controller.currentPlayer() == board.region(id).owner()){
        _controller.setSelectedRegion(id);
    }
}

void ReinforcePhase::handleRegionClicked(unsigned int id){
    Board & board = Board::instance();
    
    if(board.region(id).owner() == _controller.currentPlayer()){
        _controller.recruitArmies(id,1);
        if(_controller.armiesToDistribute() == 0){
            _controller.nextPhase();
        }
    }
}

void SetupPhase::handleRegionClicked(unsigned int id){
	unsigned int selected_region = _controller.selectedRegion();
    Board & board = Board::instance();
    
    if(board.region(id).owner() == NO_OWNER){
        board.region(id).setOwner(_controller.currentPlayer());
        board.region(id).addArmies(1);
        _controller.nextPhase();
    }
    else if(_controller.allRegionsTaken() && board.region(id).owner() == _controller.currentPlayer()){
        board.region(id).addArmies(1);
        _controller.nextPhase();
    }
    
    
}

void CardPhase::handleRegionClicked(unsigned int id){
    
}


PhaseName AttackPhase::phaseName(){
    return ATTACK;
}

PhaseName SetupPhase::phaseName(){
    return SETUP;
}

PhaseName ReinforcePhase::phaseName(){
    return REINFORCE;
}

PhaseName FortifyPhase::phaseName(){
    return FORTIFY;
}

PhaseName CardPhase::phaseName(){
    return CARD;
}

