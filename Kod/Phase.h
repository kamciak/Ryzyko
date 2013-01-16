#ifndef PHASE_H
#define PHASE_H


class Controller;

enum PhaseName{
    REINFORCE,
    FORTIFY,
    ATTACK,
    SETUP
};

class Phase{
public:
	virtual void handleRegionClicked(unsigned int id) = 0;
    virtual PhaseName phaseName() = 0;
};

class SetupPhase : public Phase{
private:
	Controller & _controller;
public:
	SetupPhase(Controller & controller) : _controller(controller){};
	void handleRegionClicked(unsigned int id);
    PhaseName phaseName();
};

class FortifyPhase : public Phase{
private:
	Controller & _controller;
public:
	FortifyPhase(Controller & controller) : _controller(controller){};
	void handleRegionClicked(unsigned int id);
    PhaseName phaseName();	
};

class AttackPhase : public Phase{
private:
	Controller & _controller;
public:
	AttackPhase(Controller & controller) : _controller(controller){};
	void handleRegionClicked(unsigned int id);
    PhaseName phaseName();
};

class ReinforcePhase : public Phase{
private:
	Controller & _controller;
public:
	ReinforcePhase(Controller & controller) : _controller(controller){};
	void handleRegionClicked(unsigned int id);
    PhaseName phaseName();
};



#endif
