#include "Objeto.h"

Objeto::Objeto(COORD posicao, COORD hitboxur, COORD hitboxdl, COORD limites):HitBoxUR(hitboxur), HitBoxDL(hitboxdl), Limites(limites) 
{
	this->setPosicao(posicao);
	this->Direcao = {1, 0};
}

void Objeto::setX(int x) {
//	if (x >= LIMITEXMIN && x <= LIMITEXMAX)
		this->Posicao.X = x;
//	else if (x > LIMITEXMAX)
//		this->Posicao.X = LIMITEXMAX;
//	else if (x < LIMITEXMIN);
}

int Objeto::getX() const {
	return this->Posicao.X;
}

void Objeto::setY(int y) {
//	if (y >= LIMITEYMIN && y <= LIMITEYMAX)
		this->Posicao.Y = y;
//	else if (y > LIMITEYMAX)
//		this->Posicao.Y = LIMITEYMAX;
//	else if (y < LIMITEYMIN)
//		this->Posicao.Y = LIMITEYMIN;
}

int Objeto::getY() const {
	return this->Posicao.Y;
}

void Objeto::setPosicao(COORD posicao) {
	this->setX(posicao.X);
	this->setY(posicao.Y);
}

COORD Objeto::getPosicao() const {
	return this->Posicao;
}

void Objeto::setDirecaoX(int direcaoX) {
	this->Direcao.X = direcaoX;
}

int Objeto::getDirecaoX() const {
	return this->Direcao.X;
}

void Objeto::setDirecaoY(int direcaoY) {
	this->Direcao.Y = direcaoY;
}

int Objeto::getDirecaoY() const {
	return this->Direcao.Y;
}

void Objeto::mover() {
	this->setPosicao({this->getX() + this->Direcao.X, this->getY() + this->Direcao.Y});
	
	if ((this->getX() <= LIMITEXMIN && this->getDirecaoX() < 0) || (this->getX() >= LIMITEXMAX && this->getDirecaoX() > 0)) {
		this->setDirecaoX(this->getDirecaoX() * -1);
		this->mover();
	}
}

void Objeto::moverX(int qtd) {
	this->setX(this->Posicao.X + qtd);
}

void Objeto::moverY(int qtd) {
	this->setY(this->Posicao.Y + qtd);
}

void Objeto::setColor(int color) {
	this->Color = color;
}

int Objeto::getColor() const {
	return this->Color;
}

void Objeto::atirar(COORD direcao) {
	int i = 0;
	bool achou = false;
	while (!achou) {
		if (this->tiros[i] == NULL) {
			achou = true;
//			tiros[i] = new Tiro({(short int) this->getX(), (short int) this->getY() - 4});
//			tiros[i].setDirecao(direcao);
		}
		i++;
	}
}
