#pragma once
#include "snako.h"
#include "Direction.h"
class snake;
class player;// i always wirte these stuff here cuz this will prevetn anything not defined to happen 
class board {
private:
	int width;
	int height;
	int fruitX;
	int fruitY;
	char** grid;
public:
	board(int a, int b) : width(a), height(b), fruitX(0), fruitY(0) {
		char** grid = new char* [width];
		for (int i = 0;i < width;i++) {
			grid[i] = new char[height];
		}
	}
	int getwidth();
	int getheight();
	void drawingboard(snake &snk,player &person);
	void creatingfruit();
	int getfruitX();
	int getfruitY();
	//~board() {
	//	delete[]grid;
	//}
};
