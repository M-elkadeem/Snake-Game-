#include "snako.h"
#include "game.h"
#include <iostream>
#include <Windows.h>
void gotoXY(int x, int y) {
	COORD pos = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


using namespace std;
int snake::getH_snakeX()
{
	return H_snakeX;
}

int snake::getH_snakeY()
{
	return H_snakeY;
}
void snake::moving(direction heading,board &obj,player &person,snake &snake1) {
	//  here i will add the shifting function
  // we have to call the shifting function for every single move adn here is it 
	shifting_tail();
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
	/// in the following if statment , we are just checking the wall collision in case the snake has touched any wall , it will be game over 
	if (H_snakeX <= 0 || H_snakeY <= 0 || H_snakeX >= (obj.getwidth()-1) || H_snakeY >= (obj.getheight()-1)) { // i added , the -1 , just to prevent the snake from walking on the walls themselves 
		person.setplayerstate(false);
	}
	 // in the next for loop,we are checking the snake collision,in case the snake bite himself or something 
	for (int i = 1; i < ntail; i++) {// here we have to start the i from 1	cuz Collision detection triggers false game over after pause/resume 
		//because head and first tail segment temporarily share the same position during pause state so it will cause the game to be over when u resume the game again 
		// so as long as the fist segement is always safe , so we can ingore it from the loop and that is all 
		if (H_snakeX == tailX[i]&&H_snakeY == tailY[i]) {
			person.setplayerstate(false);
			return;
		}
	}
	if (H_snakeX == obj.getfruitX() && H_snakeY == obj.getfruitY()) {
		growing_tail();  /// once it eats any fruit , it will get the tail to increase " 
	
		obj.creatingfruit(snake1);
		person.updatescore();// in the update function , it will increase the score by one 
	}

}

void snake::shifting_tail()
{
	if (ntail == 0) return; // here we are just checking if ntail is 0 so there is no shifting needed 
	// the following , is the core of the shifting  where all the segments of the tail will keep shifting , with each other , to make them followed after each other 
	for (int i = ntail - 1; i > 0; i--) {
		tailX[i] = tailX[i - 1];
		tailY[i] = tailY[i - 1];

	}
	// notice the head is changing whenver we do any move and the first segment will always be as the HEADcoordinates 
	tailX[0] = H_snakeX;
	tailY[0] = H_snakeY;

}

int* snake::gettailX()
{
	return tailX;
}

int* snake::gettailY()
{
	return tailY;
}
int snake::getNtail() {
	return ntail;
}
void snake::growing_tail()
{
     int old_ntail = ntail;
	ntail++;

	int *newtailX = new int[ntail];// here we have created the place for the new segement , but it's still has a garbage value 
	int *newtailY = new int[ntail];
	for (int i = 0;i <old_ntail;i++) {
		newtailX[i] = tailX[i];
		newtailY[i] = tailY[i];

	}
	if (old_ntail == 0) {// this a specail case where we have to handle when the tail is still 0 
		newtailX[0] = H_snakeX;
		newtailX[0] = H_snakeY;

	}
	else {

	}
	// in the following we are given the new segement a value , where we have copied the last segement into it 

	newtailX[old_ntail] = tailX[old_ntail-1];
	newtailY[old_ntail] = tailY[old_ntail - 1];
	
	delete[]tailX;// here i have to deallocate the last tail 
	delete[]tailY;
	//  and in the following , im gonna make the orginal tail pointing to the newtail , to be able to use the original tail segments  
	tailX = newtailX;
	tailY = newtailY;
}

void snake::drawingtail()
{
	for (int i = 0;i < ntail;i++) {
// and here im  gonna use gotoXY function , cuz it can move the cursor to the exact coordinates 
	gotoXY(tailX[i], tailY[i]);
	cout << "o";
	}
}
