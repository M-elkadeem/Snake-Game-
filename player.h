#pragma once
class player {
	int score;
	bool playerstate;
public :
	player ():score(0),playerstate(true){}
	void updatescore();
	int getscore();
	void setplayerstate(bool state);
	bool getplayersatate();
};