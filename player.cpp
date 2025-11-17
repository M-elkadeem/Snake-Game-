#include "player.h"

void player::updatescore()
{
	score++;
}





int player::getscore()
{
	return score;
}

void player::setplayerstate(bool state)
{
	playerstate = state;
}
bool player::getplayersatate()
{
	return playerstate;
}

