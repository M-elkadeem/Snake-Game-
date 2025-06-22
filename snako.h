#pragma once
#include "game.h"
#include "board.h"
#include "Direction.h"
#include "player.h"

class board;
class snake {
private:
	int H_snakeX;
	int H_snakeY;
public:
	snake(int w, int h) {
		H_snakeX = w / 2;
		H_snakeY = h /  2;
	}
	int getH_snakeX();
	int getH_snakeY();
	void moving(direction heading,board &obj,player &person);
};
