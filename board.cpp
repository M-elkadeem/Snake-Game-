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
	bool  isintersected = false;
	// here the coordinates will be generalting in this way to avoid mixing betweent the fruit and the boders of the board
	
//the next while loop is to prevent the fruit from being created over one of the segements of the snake itself , whether over the head or the tail itself  
	while (1) {
// so here if there will be any intersection,the isintersected will be set to true , and the code will go through loop till there is no any intersection between them 
		isintersected = false; 
		fruitX = rand() % (width - 2) + 1;
		fruitY = rand() % (height - 2) + 1;
		if (fruitX == snake1.getH_snakeX() && fruitY == snake1.getH_snakeY()) {
			isintersected = true;
			continue;
		}
			for (int i = 0; i < snake1.getNtail(); i++) {
				if (fruitX == snake1.gettailX()[i] && fruitY == snake1.gettailY()[i]) {
					isintersected = true;
					break;// it force us to exit,from the for loop itself not the while loop ( the closest loop 
				}
		}
		if (isintersected == false) {
			break;
		}
	}

}

int board::getfruitX()
{
	return fruitX;
}

int board::getfruitY()
{
	return fruitY;
}
