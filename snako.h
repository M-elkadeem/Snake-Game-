#pragma once
#include "game.h"
#include "board.h"
#include "Direction.h"
#include "player.h"
class board;// u must write this , cuz the header file canot identify the stuff which u have included in the header files , only the cpp can do so 
class snake {
private:
	int H_snakeX;
	int H_snakeY;
	int* tailX;
	int* tailY;
	int ntail=0;

public:
	snake(int w, int h) {
		H_snakeX = w / 2;
		H_snakeY = h /  2;
		tailX = new int[ntail];
		tailY = new int[ntail];

	}
	int getH_snakeX();
	int getH_snakeY();
	void moving(direction heading,board &obj,player &person ,snake&snake1);
	void shifting_tail();
	int *gettailX();
	int *gettailY();
	int getNtail();
	void growing_tail();
	void drawingtail();
	~snake() {
		if (ntail > 0) {
			delete[] tailX;
			delete[] tailY;
		}
	}
};
