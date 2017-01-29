#include "getMouseXY.h"

COORD getMouseXY() {
	POINT mousePos;
	GetCursorPos(&mousePos);
	return {(short int) mousePos.x, (short int) mousePos.y};
}
