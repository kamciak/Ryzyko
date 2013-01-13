#include "Phase.h"
#include "Controller.h"
#include "RiskFrm.h"
#include "Board.h"

void FortifyPhase::handleRegionClicked(unsigned int id){
    unsigned int selected_region = _controller.selectedRegion();
    Board & board = Board::instance();

	if(selected_region != NO_REGION_SELECTED){
	    if(selected_region == id)
            _controller.setSelectedRegion(NO_REGION_SELECTED);
        else{            
            if(board.region(selected_region).isNeighbor(id) && 
            (board.region(selected_region).controller() == board.region(id).controller())){
                //TODO: kod przemieszczania wojsk
            }
        }
    }             
    else if(_controller.currentPlayer() == board.region(id).controller()){
        _controller.setSelectedRegion(id);
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
            (board.region(selected_region).controller() != board.region(id).controller())){
                if(board.region(selected_region).armyCount() > 1)
                    _controller.combat(selected_region,id);
            }
        }
    }             
    else if(_controller.currentPlayer() == board.region(id).controller()){
        _controller.setSelectedRegion(id);
    }
}

void ReinforcePhase::handleRegionClicked(unsigned int id){
    Board & board = Board::instance();
    
    if(board.region(id).controller() == _controller.currentPlayer()){
        _controller.recruitArmies(id,1);
        if(_controller.armiesToDistribute() == 0){
            _controller.nextPhase();
        }
    }
}

void SetupPhase::handleRegionClicked(unsigned int id){
	unsigned int selected_region = _controller.selectedRegion();
    Board & board = Board::instance();
    
    if(board.region(id).controller() == NO_CONTROLLER){
        board.region(id).setController(_controller.currentPlayer());
        board.region(id).addArmies(1);
        _controller.nextPhase();
    }
    else if(_controller.allRegionsTaken() && board.region(id).controller() == _controller.currentPlayer()){
        board.region(id).addArmies(1);
        _controller.nextPhase();
    }
    
    
}
