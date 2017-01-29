#include "Invader5.h"

Invader5::Invader5(COORD posicao, COORD limites):Objeto(posicao, {8, 4}, {-8, -3}, limites) {
}

void Invader5::imprime() const {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), this->getColor());
	
	// LINHA 1
	goToXY(this->getX() - 3, this->getY() - 3); cout << "@@@@@@@";
	
	// LINHA 2
	goToXY(this->getX() - 5, this->getY() - 2); cout << "@@@@@@@@@@@";
	
	// LINHA 3
	goToXY(this->getX() - 6, this->getY() - 1); cout << "@@@@@@@@@@@@@";
	
	// LINHA 4
	goToXY(this->getX() - 7, this->getY()); cout << "@@";
	goToXY(this->getX() + 6, this->getY()); cout << "@@";
	
	if (this->getX() % 2) {
		goToXY(this->getX() - 5, this->getY()); cout << "@";
		goToXY(this->getX() - 3, this->getY()); cout << "@";
		goToXY(this->getX() - 1, this->getY()); cout << "@";
		goToXY(this->getX() + 1, this->getY()); cout << "@";
		goToXY(this->getX() + 3, this->getY()); cout << "@";
		goToXY(this->getX() + 5, this->getY()); cout << "@";
	} else {
		goToXY(this->getX() - 4, this->getY()); cout << "@";
		goToXY(this->getX() - 2, this->getY()); cout << "@";
		goToXY(this->getX(), this->getY()); cout << "@";
		goToXY(this->getX() + 2, this->getY()); cout << "@";
		goToXY(this->getX() + 4, this->getY()); cout << "@";
	}
	
	// LINHA 5
	goToXY(this->getX() - 8, this->getY() + 1); cout << "@@@@@@@@@@@@@@@@@";
	
	// LINHA 6
	goToXY(this->getX() - 6, this->getY() + 2); cout << "@@@";
	goToXY(this->getX() - 1, this->getY() + 2); cout << "@@@";
	goToXY(this->getX() + 4, this->getY() + 2); cout << "@@@";
	
	// LINHA 7
	goToXY(this->getX() - 5, this->getY() + 3); cout << "@";
	goToXY(this->getX() + 5, this->getY() + 3); cout << "@";
};
