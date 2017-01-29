#include "goToXY.h"

#include <windows.h>

void goToXY(short int x, short int y) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {x, y}); 
}
