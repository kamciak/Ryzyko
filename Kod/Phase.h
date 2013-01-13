#ifndef PHASE_H
#define PHASE_H


class Controller;

class Phase{
public:
	virtual void handleRegionClicked(unsigned int id) = 0;
};

class SetupPhase : public Phase{
private:
	Controller & _controller;
public:
	SetupPhase(Controller & controller) : _controller(controller){};
	void handleRegionClicked(unsigned int id);
};

class FortifyPhase : public Phase{
private:
	Controller & _controller;
public:
	FortifyPhase(Controller & controller) : _controller(controller){};
	void handleRegionClicked(unsigned int id);	
};

class AttackPhase : public Phase{
private:
	Controller & _controller;
public:
	AttackPhase(Controller & controller) : _controller(controller){};
	void handleRegionClicked(unsigned int id);
};

class ReinforcePhase : public Phase{
private:
	Controller & _controller;
public:
	ReinforcePhase(Controller & controller) : _controller(controller){};
	void handleRegionClicked(unsigned int id);
};

#endif
