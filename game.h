#pragma once
#include "snako.h"
#include "Direction.h"
class Game {
private:
	bool iswin;
	bool isgameover;
	direction heading;
	direction prevheading;
public:
	Game():iswin(true),isgameover(false),heading(None){}
	void checkInput();
	void processingInputs();
	void setwinstate(bool state);
	bool getthewinstate();
	bool getgamestate();
	void setgamestate(bool state);
	void playingthegame();

};

