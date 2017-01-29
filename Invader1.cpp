#include "Invader1.h"

Invader1::Invader1(COORD posicao):Objeto({posicao.X, posicao.Y}) {}

void Invader1::imprime() const {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), this->getColor());
	
	// LINHA 1
	goToXY(this->getX() - 3, this->getY() - 3); cout << "@";
	goToXY(this->getX() + 3, this->getY() - 3); cout << "@";
	
	// LINHA 2
	goToXY(this->getX() - 2, this->getY() - 2); cout << "@";
	goToXY(this->getX() + 2, this->getY() - 2); cout << "@";
	
	if (this->getX() % 2) {
		goToXY(this->getX() - 5, this->getY() - 2); cout << "@";
		goToXY(this->getX() + 5, this->getY() - 2); cout << "@";
	}
	
	// LINHA 3
	goToXY(this->getX() - 3, this->getY() - 1); cout << "@@@@@@@";
	
	if (this->getX() % 2) {
		goToXY(this->getX() - 5, this->getY() - 1); cout << "@";
		goToXY(this->getX() + 5, this->getY() - 1); cout << "@";
	}
	
	// LINHA 4
	goToXY(this->getX() - 4, this->getY()); cout << "@@";
	goToXY(this->getX() - 1, this->getY()); cout << "@@@";
	goToXY(this->getX() + 3, this->getY()); cout << "@@";
	
	if (this->getX() % 2) {
		goToXY(this->getX() - 5, this->getY()); cout << "@";
		goToXY(this->getX() + 5, this->getY()); cout << "@";
	}
	
	// LINHA 5
	goToXY(this->getX() - 5, this->getY() + 1); cout << "@@@@@@@@@@@";
	
	// LINHA 6
	goToXY(this->getX() - 3, this->getY() + 2); cout << "@@@@@@@";
	
	if (this->getX() % 2) {
		goToXY(this->getX() - 4, this->getY() + 2); cout << "@";
		goToXY(this->getX() + 4, this->getY() + 2); cout << "@";
	} else {
		goToXY(this->getX() - 5, this->getY() + 2); cout << "@";
		goToXY(this->getX() + 5, this->getY() + 2); cout << "@";
	}
	
	// LINHA 7
	goToXY(this->getX() - 3, this->getY() + 3); cout << "@";
	goToXY(this->getX() + 3, this->getY() + 3); cout << "@";
	
	if (this->getX() % 2 == 0){
		goToXY(this->getX() - 5, this->getY() + 3); cout << "@";
		goToXY(this->getX() + 5, this->getY() + 3); cout << "@";
	}
	
	// LINHA 8
	if (this->getX() % 2) {
		goToXY(this->getX() - 4, this->getY() + 4); cout << "@";
		goToXY(this->getX() + 4, this->getY() + 4); cout << "@";
	} else {
		goToXY(this->getX() - 2, this->getY() + 4); cout << "@@";
		goToXY(this->getX() + 1, this->getY() + 4); cout << "@@";
	}
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
