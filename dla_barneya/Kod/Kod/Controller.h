#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Board.h"
#include "PlayersData.h"
#include "RegionDrawInformation.h"
#include "Phase.h"
class RiskFrm;
class Phase;



///Klasa odpowiedzialna za wspó³pracê danych ze stron¹ graficzn¹
class Controller{
private:
    ///Deklaracja kontstruktora kopiujacego, zapobiega kopiowaniu kontrolerow    
    Controller(const Controller & c);
    ///Deklaracja operatora przypisania, zapobiega kopiowaniu kontrolerow
    Controller & operator=(const Controller & c);
    ///Id aktualnie wybranego regionu 
    unsigned int _selected_region;
    ///Referencja do okna(czesci graficznej) aplikacji    
    RiskFrm & _window;
    ///Aktualna faza gry (stan), od niej zale¿y jak obs³ugiwane s¹ zdarzenia takie jak klikniecie na region
    Phase *_current_phase;
    ///Kolejnosc graczy uczestniczasych w grze
    std::vector<unsigned int> _players_queue;
    ///Iterator na aktualnego gracza
    std::vector<unsigned int>::iterator _current_player;
    ///Ilosc armii do rozdania na poczatku gry lub w fazie rekrutacji
    unsigned int _armies_to_distribute;
    ///Oblicza ile armii gracz otrzymuje w swojej fazie rekrutacji, uaktualnia _armies_to_distribute i wypisuje informacjo w oknie informacji
    void calculateNumberOfRecruits(unsigned int player_id);
public:    
    void regionClicked(unsigned int id);
    Controller(RiskFrm & window);
    ~Controller();

    ///Zwraca wartoœæ PhaseName odpowiadaj¹c¹ aktualnej fazie
    PhaseName getPhaseName();
    ///Koñczy fazê rozmieszczania pocz¹tkowych pionków i rozpoczyna grê
    void startGame();
    ///Przechodzi do nastepnej fazy w turze, lub konczy ture jezeli jest to ostatnia faza
    void nextPhase();
    ///Ustawia region jako zaznaczony i rozkazuje oknu pomalowanie go
    void setSelectedRegion(unsigned int id);
    ///Zwraca id wybranego aktualnie regionu
    unsigned int selectedRegion();
    ///Zwraca id aktualnego gracza
    unsigned int currentPlayer();
    ///Inicjalizuje graczy danymi z okna menu
    bool initPlayers();
    ///Zwraca wartosc logiczna czy wszystkie regiony maja juz wlasciciela 
    bool allRegionsTaken();
    ///Zwraca obiekt przechowujacy wszystkie dane potrzebne do przedstawienia danych o regionie na mapie
    std::vector<RegionDrawInformation> getRegionDrawInfo(bool big_image);
    ///Zwraca ilosc armii pozosta³ych do rozdzielenia
    unsigned int armiesToDistribute();
    ///Dodaje armie do regionu i usuwa je z puli armii do rozdzielenia
    void recruitArmies(unsigned int region_id, unsigned int amount);
    ///Przeprowadza walkê miêdzy regionami o podancych id i zwraca jej rezultat
	void combat(unsigned int attacker, unsigned int defender);
};



#endif
