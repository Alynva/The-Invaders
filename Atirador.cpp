#include "Atirador.h"

Atirador::Atirador(COORD posicao, COORD limites):Objeto(posicao, {6, 4}, {-6, 0}, limites) {
}

void Atirador::goToMouseX(int wFont) {
	if (getMouseXY().X / wFont + this->HitBoxLD.X <= 0)
		this->setX(this->HitBoxLD.X * -1 - 1);
	else if (getMouseXY().X / wFont + this->HitBoxRU.X >= this->Limites.X)
		this->setX(this->Limites.X - this->HitBoxRU.X + 1);
	else
		this->setX(getMouseXY().X / wFont);
	this->mover();
}

void Atirador::imprime() const {
//	for (int i = 0; i < QTDTIROS; i++) {
//		if (tiros[i] != NULL) {
//			if (tiros[i]->getPosicao().Y > 1) {
//				tiros[i]->mover();
//				tiros[i]->imprime();
//			} else {
//				tiros[i] = { NULL };
//			}
//		}
//	}
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), this->getColor());
	
	// LINHA 1
	goToXY(this->getX(), this->getY() - 4); cout << "@";
	
	// LINHA 2
	goToXY(this->getX() - 1, this->getY() - 3); cout << "@@@";
	
	// LINHA 4
	goToXY(this->getX() - 5, this->getY() - 2); cout << "@@@@@@@@@@@";
	
	// LINHA 5
	goToXY(this->getX() - 6, this->getY() - 1); cout << "@@@@@@@@@@@@@";
	goToXY(this->getX() - 6, this->getY()); cout << "@@@@@@@@@@@@@";

}
