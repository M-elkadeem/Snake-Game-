#include <iostream>
#include "board.h"
#include "snako.h"

using namespace std;
int board::getwidth()
{
	return width;
}

int board::getheight()
{
	return height;
}

void board::drawingboard(snake& snk, player& person) // here is the drwaing of the game board and the initializaion of the snake 
{
	system("cls");
	for (int i = 0;i < height;i++) {
		for (int j = 0;j < width;j++) {
			if (i == 0 || i == height - 1) {
				cout << "*";
			}
			else if (j == 0 || j == width - 1) {
				cout << "*";
			}
			else if (i == snk.getH_snakeY() && j == snk.getH_snakeX()) {
				cout << "O";
			}
			else if (i == fruitY && j == fruitX) {
			cout << "$";
			}
			else {
				cout << " "; 
			}
			
		}
		cout << endl;
	}
	cout << "player score : " << "(" << person.getscore() << ")" << endl;
	snk.drawingtail();// here we are gonna call the drawing tail function after drawing the board 

}
void board::creatingfruit(snake &snake1)// here i will create the fruit and place in a random position 
{
	// here the coordinates will be generalting in this way to avoid mixing betweent the fruit and the boders of the board
	fruitX = rand() % (width - 2) + 1;

	fruitY = rand() % (height - 2) + 1;

}

int board::getfruitX()
{
	return fruitX;
}

int board::getfruitY()
{
	return fruitY;
}
