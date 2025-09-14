#include "utilities.h"
// i got the next function by searching about it , and it just help the program to not be heavy and work smoothly 

void clearscreen()
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { 0, 0 };
    DWORD count;
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(hStdOut, &csbi);
    DWORD cellCount = csbi.dwSize.X * csbi.dwSize.Y;
    FillConsoleOutputCharacter(hStdOut, ' ', cellCount, coord, &count);
    SetConsoleCursorPosition(hStdOut, coord);
}
