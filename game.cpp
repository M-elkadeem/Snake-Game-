#include <windows.h>
#include "game.h"
#include <iostream>
#include <cstdlib> 
#include <conio.h>
#include "snako.h"
#include "board.h"
#include "player.h"

using namespace std;

void Game::checkInput()
{
	if (_kbhit()) {
		int ch = _getch();
		if (ch == 27) {
			system("cls");
			cout << "┌─────────────────────────────────────┐" << endl;
			cout << "│        ARE YOU SURE TO EXIT?        │" << endl;
			cout << "│                                     │" << endl;
			cout << "│      Press Y to confirm exit        │" << endl;
			cout << "│      Any other key to continue      │" << endl;
			cout << "└─────────────────────────────────────┘" << endl;
			int confirm = _getch();
			if (confirm =='y'||confirm=='Y') {
				system("cls");
				cout << "Good bye" << endl;
				//return Exit;
				heading = Exit;
				return;
			}
		system("cls"); 
			//return None;
		heading = None;
		return;
		}
		switch (ch) {
		case 'a':
		case 'A':
			heading = Left;
			//return Left;
			break;
		case 'd':
		case 'D':
		   // return Right;	
			heading = Right;
			break;
		case 'w':
		case 'W':
			//return Up;
			heading = Up;
			break;
		case 's':
		case 'S':
			//return Down;
			heading = Down;
			break;
		case 32:
		//return Stop;
			heading = Stop;
			break;
		default:
			//return None;
			heading = None;		
		}
	}
//	return None;
	//heading = None;
}

void Game::processingInputs()
{
	switch (heading) {
	case Stop:
		cout << "the game is paused , press any key to continue" << endl;
		(void)_getch();
		heading = None;// this will handle all the other keys , except the main ones , so it will just continue as it was moving before 
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
	int baseSpeed = 80;  // Base speed in milliseconds
	int speedAdjustment = (width + height) / 6;  // Larger boards get slightly slower
	int gameSpeed = max(30, min(150, baseSpeed + speedAdjustment));
	obj.creatingfruit();
	while (!getgamestate()) {
		obj.drawingboard(snake1,person);
		if (person.getplayersatate()) {
			checkInput();
			snake1.moving(heading,obj,person);
			processingInputs();
			Sleep(gameSpeed);// the speed here is fixed , and u have to connect its formula with the value of the height and the width
		}
		else {
			cout << "Game over" << endl;
			break;
		}
	}
	cout << "Game Exited" << endl;
}
