#ifndef BOARD_H
#define BOARD_H
#include "snako.h"
#include "Direction.h"
class snake;
class player; // i always wirte these stuff here cuz this will prevetn anything not defined to happen 
class board {
private:
	int width;
	int height;
	int fruitX;
	int fruitY;
	char** grid;
public:
	board(int a, int b) : width(a), height(b), fruitX(0), fruitY(0) {
		// the following should be like that not char** = .................... cuz then it will be a local vaiable , so i will crash , so u have to make it general 

		grid = new char* [width];
		for (int i = 0;i < height;i++) {
			grid[i] = new char[width];
		}
	}
	int getwidth();
	int getheight();
	void drawingboard(snake &snk,player &person);
	void creatingfruit();
	int getfruitX();
	int getfruitY();
	~board() {
		// u have to delete each grid ur creating 
		for (int i = 0; i < height; i++) {
			delete[] grid[i];
		}
		delete[]grid;
	}
};

#endif