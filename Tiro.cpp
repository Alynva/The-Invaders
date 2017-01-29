#include "Tiro.h"

#include <iostream>
using namespace std;

#include "goToXY.h"

Tiro::Tiro(short int x, short int y) {
	this->setPosicao({x, y});
};

void Tiro::setPosicao(COORD posicao) {
	this->Posicao = posicao;
}

COORD Tiro::getPosicao() const {
	return this->Posicao;
}

void Tiro::setDirecao(COORD direcao) {
	this->Direcao = direcao;
}

COORD Tiro::getDirecao() const {
	return this->Direcao;
}

void Tiro::mover() {
	this->Posicao.X += this->Direcao.X;
	this->Posicao.Y += this->Direcao.Y;
}
void Tiro::imprime() const {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	goToXY(this->Posicao.X, this->Posicao.Y); cout << "*";
}
