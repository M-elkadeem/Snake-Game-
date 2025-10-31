#include <iostream>
#include <conio.h>
#include "game.h"
#include <ctime>

using namespace std;
int main()
{
	srand(time(0));
	// what will be in the main here will be in a seperated class called game 
    char ch;
	Game playing;
    while (true) {
        // the following logic is working correctly  however there are some bugs which has poped up like the snake is not starting from the middle in the repeated game
        // and the second thing is you should display a good message rather these ones ,  and if there are better ways to do this logic , then go ahead and do it 

        if (playing.getgamestate() == false) {
            playing.playingthegame();
            playing.setpreviousheading(Stop);// this will set the previous direction to stop , to prevent the snake from moving into the same direction as before once we takt another trial for the game 
        }
        else {
            cout << "Do you want to play again " << endl;
            cin >> ch;
            if (ch == 'y'||ch=='Y') {
                playing.setgamestate(false);
            }
            else if (ch=='n'||ch=='N') {
                cout << "Game exited >>> good bye" << endl;
                break;
            }
            else {
                cout << "unknown input >> please try again " << endl;
                cin >> ch;
            }
        }
    }
	

	return 0 ;
}
