#include <iostream>
#include <conio.h>
#include "game.h"
#include <ctime>

using namespace std;
int main()
{
	srand(time(0));
	// what will be in the main here will be in a seperated class called game 
	Game playing;
	playing.playingthegame();

	return 0 ;
}
/* some notes , u have to modify the value of rand function every thime , cuz what is he giving u always will be random however it will be the same random ones always 
so u have to use another function called *** srand()**** and then u can connect to to anything else like the time or anything 

when u call rand , it will only give u the random values all the time and if u want different values each time , u should use srand , but donot call each time and that is why i wrote it in the main and that is it 

// some new notes about using the library that is about the keyboard 
_getch() returns an integer representing the key pressed.
You compare that integer to character literals like 'w' or 'W'.
No manual conversion needed — it’s automatic.


// here u could add system("pause") but it will be kinds of weired dut to the printed senteces


// some notes about the function getch 

What’s _getch()?
It’s a function from <conio.h> (mostly in Windows C/C++) that waits for a keypress and returns the key code.

Usually used to pause the program until the user presses a key.

The return value is the key pressed, but you don’t have to use it if you only want to pause


some important notes , whnever u have errors like when some variables are not defined and he is teelling u that there are mistakes in the typing , the best solution for these 
stuff is to seperates ur files  and keep in u rmind that u cannot implement something from the upcoming class in another class that has been implemented and written before it 
and if u wanna do so , u should at least write the name of the class before it like the following ( class "name" ) 



 it's recommand to use the following function instead of using system(cls) and here is it 
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {0, 0};
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(hStdOut, &csbi);
    DWORD cellCount = csbi.dwSize.X * csbi.dwSize.Y;
    FillConsoleOutputCharacter(hStdOut, ' ', cellCount, coord, &count);
    SetConsoleCursorPosition(hStdOut, coord);
*/


/*the upcoming features  like 
 integerating a userinterface , and a gui interface ( new version ) 
 the possiblily for playing mulitiple times in case of losing 
 file handling , to save the scorec of each user , 
 the excetption handling as well is a must 
 and the last thing , in case there are not new feautres fro adding , ( the documentation )
*/