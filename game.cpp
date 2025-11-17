#include <windows.h>
#include "game.h"
#include <iostream>
#include <cstdlib> 
#include <conio.h>
#include "snako.h"
#include "board.h"
#include "player.h"
#include "utilities.h"

using namespace std;

void Game::checkInput()
{
	if (_kbhit()) {
		int ch = _getch();
		if (ch == 27) {
			clearscreen();
			cout << "┌─────────────────────────────────────┐" << endl;
			cout << "│        ARE YOU SURE TO EXIT?        │" << endl;
			cout << "│                                     │" << endl;
			cout << "│      Press Yes to confirm exit othe wise        │" << endl;
			cout << "│      Any other key to continue      │" << endl;
			cout << "└─────────────────────────────────────┘" << endl;
			int confirm = _getch();
			if (confirm =='y'||confirm=='Y') {
				clearscreen();
				cout << "Good bye" << endl;
				heading = Exit;
				return;
			}
			clearscreen();
		heading = None;
		return;
		}
		char previous_ch;
		previous_ch = ch; 
		switch (ch) {
		case 'a':
		case 'A':
			if (heading != Right) {
				heading = Left;
				break;
			}
			else {
				heading = Right; break;
			}
		case 'd':
		case 'D':
			if (heading != Left) {
				heading = Right;
				break;
			}
			else {
				heading = Left;
				break;
			}
		case 'w':
		case 'W':
			if (heading != Down) {
				heading = Up; 
				break;
			}
			else {
				heading = Down;
				break;
			}
		case 's':
		case 'S':
			if (heading != Up) {
				heading = Down; 
				break;
			}
			else {
				heading = Up;
			break; // in all the cases , i  have to add this break . otherwise it will go for  the next command like here if u didnot write it , it will go for the stop command 
			}
		case 32:
			prevheading = heading;
			heading = Stop;
			break;
		//default:
			//heading = None;		
		}
	}

}

void Game::processingInputs()
{
	switch (heading) {
	case Stop:

		cout << "the game is paused , press any key to continue" << endl;
		int key;
		do {
			// this do while loop is just to keep the game stopped till u press another key and u will not go out form that loop till u press the space only 
			key = _getch(); // this is one is here , to make the game stopped cuz it will need u to press any key and the for while loop is forcing to press the space key only 
		} while (key != 32);
		heading = prevheading;// this will handle all the other keys , except the main ones , so it will just continue as it was moving before 
		break;
	case Exit:
		setgamestate(true);
		break;
	}
}

void Game::setwinstate(bool state)
{
	iswin = state;
}

bool Game::getthewinstate()
{
	return iswin;
}

bool Game::getgamestate()
{
	return isgameover;
}

void Game::setgamestate(bool state)
{
	isgameover = state;
}

void Game::playingthegame()
{
	// the follwoing stuff before writing the setup of the game is just to hide the small dash that keeps poping on the screen and this will hide any dash that u see when ur waiting for any input from the user 

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(console, &cursorInfo);
	cursorInfo.bVisible = false; // Hide the cursor
	SetConsoleCursorInfo(console, &cursorInfo);

	int width, height;
	cout << " enter the width and the height " << endl;
	cin >> width >> height;
	board obj(width, height);
	snake snake1(width, height);
	player person;
	int gameSpeed = 120;
	obj.creatingfruit(snake1); 
	while (!getgamestate()) {
		obj.drawingboard(snake1,person);
		if (person.getplayersatate()) {
			checkInput();
			// the following two functions , are there to handle all the cases of the heading variable , wethear it's a direction or stop or none 
			snake1.moving(heading,obj,person,snake1);
			processingInputs();
			Sleep(gameSpeed);// the speed here is fixed , and u have to connect its formula with the value of the height and the width
		}
		else {
			clearscreen();
		cout << "Game over" << endl;
		setgamestate(true);//////////////////////////////////////////////////////////////hereeeeee
			break;
		}
	}
	
	cout << "Game Exited" << endl;
}

void Game::setpreviousheading(direction heading)
{
	this->heading = prevheading; 
}
