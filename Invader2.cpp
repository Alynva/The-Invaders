#include "Invader2.h"

Invader2::Invader2(COORD posicao, COORD limites):Objeto(posicao, limites) {
}

void Invader2::imprime() const {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), this->getColor());
	
	// LINHA 1
	goToXY(this->getX() - 2, this->getY() - 4); cout << "@";
	goToXY(this->getX() + 2, this->getY() - 4); cout << "@";
	
	// LINHA 2
	goToXY(this->getX() - 2, this->getY() - 3); cout << "@@@@@";
	
	// LINHA 3
	goToXY(this->getX() - 4, this->getY() - 2); cout << "@@@@@@@@@";
	
	// LINHA 4
	goToXY(this->getX() - 5, this->getY() - 1); cout << "@";
	goToXY(this->getX() - 2, this->getY() - 1); cout << "@@@@@";
	goToXY(this->getX() + 5, this->getY() - 1); cout << "@";
	
	if (this->getX() % 2) {
		goToXY(this->getX() - 4, this->getY() - 1); cout << "@@";
		goToXY(this->getX() + 3, this->getY() - 1); cout << "@@";
	}
	
	// LINHA 5
	goToXY(this->getX() - 6, this->getY()); cout << "@@";
	goToXY(this->getX() - 1, this->getY()); cout << "@@@";
	goToXY(this->getX() + 5, this->getY()); cout << "@@";
	
	// LINHA 6
	goToXY(this->getX() - 8, this->getY() + 1); cout << "@@@@";
	goToXY(this->getX() - 1, this->getY() + 1); cout << "@";
	goToXY(this->getX() + 1, this->getY() + 1); cout << "@";
	goToXY(this->getX() + 5, this->getY() + 1); cout << "@@@@";
	
	// LINHA 7
	goToXY(this->getX() - 5, this->getY() + 2); cout << "@@@@@";
	goToXY(this->getX() + 1, this->getY() + 2); cout << "@@@@@";
	
	// LINHA 8
	goToXY(this->getX() - 3, this->getY() + 3); cout << "@@@@@@@";
	
	if (this->getX() % 2) {
		goToXY(this->getX() - 6, this->getY() + 3); cout << "@";
		goToXY(this->getX() + 6, this->getY() + 3); cout << "@";
	} else {
		goToXY(this->getX() - 5, this->getY() + 3); cout << "@";
		goToXY(this->getX() + 5, this->getY() + 3); cout << "@";
	}
	
	// LINHA 9
	goToXY(this->getX() - 3, this->getY() + 4); cout << "@";
	goToXY(this->getX() - 1, this->getY() + 4); cout << "@";
	goToXY(this->getX() + 1, this->getY() + 4); cout << "@";
	goToXY(this->getX() + 3, this->getY() + 4); cout << "@";
	
	if (this->getX() % 2) {
		goToXY(this->getX() - 7, this->getY() + 4); cout << "@";
		goToXY(this->getX() + 7, this->getY() + 4); cout << "@";
	} else {
		goToXY(this->getX() - 6, this->getY() + 4); cout << "@";
		goToXY(this->getX() + 6, this->getY() + 4); cout << "@";
	}
	
	// LINHA 10
	if (this->getX() % 2) {
		goToXY(this->getX() - 7, this->getY() + 5); cout << "@";
		goToXY(this->getX() + 7, this->getY() + 5); cout << "@";
	} else {
		goToXY(this->getX() - 6, this->getY() + 5); cout << "@";
		goToXY(this->getX() + 6, this->getY() + 5); cout << "@";
	}
	
	// LINHA 11
	if (this->getX() % 2) {
		goToXY(this->getX() - 6, this->getY() + 6); cout << "@";
		goToXY(this->getX() + 6, this->getY() + 6); cout << "@";
	} else {
		goToXY(this->getX() - 5, this->getY() + 6); cout << "@";
		goToXY(this->getX() + 5, this->getY() + 6); cout << "@";
	}
		
}
