#include "snako.h"
#include "game.h"
int snake::getH_snakeX()
{
	return H_snakeX;
}

int snake::getH_snakeY()
{
	return H_snakeY;
}
void snake::moving(direction heading,board &obj,player &person) {
	switch (heading) {
	case Up:
		H_snakeY--;
		break;
	case Down:
		H_snakeY++;
		break;
	case Right:
		H_snakeX++;
		break;
	case Left:
		H_snakeX--;
		break;
	}
	if (H_snakeX <= 0 || H_snakeY <= 0 || H_snakeX >= obj.getwidth() || H_snakeY >= obj.getheight()) {
		person.setplayerstate(false);
	}
	if (H_snakeX == obj.getfruitX() && H_snakeY == obj.getfruitY()) {
		obj.creatingfruit();
		person.updatescore();
	}

}