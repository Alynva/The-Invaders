#include "Objeto.h"

Objeto::Objeto(COORD posicao, COORD hitboxru, COORD hitboxld, COORD limites):HitBoxRU(hitboxru), HitBoxLD(hitboxld), Limites(limites) {
	this->setPosicao(posicao);
	this->Direcao = {1, 0};
}

void Objeto::setX(int x) {
	this->Posicao.X = x;
}

int Objeto::getX() const {
	return this->Posicao.X;
}

void Objeto::setY(int y) {
	this->Posicao.Y = y;
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
	
	if (
		(this->getX() + this->HitBoxLD.X < 0 && this->getDirecaoX() < 0) ||
		(this->getX() + this->HitBoxRU.X > this->Limites.X && this->getDirecaoX() > 0)
	) {
		this->setDirecaoX(this->getDirecaoX() * -1);
		this->mover();
	} else if (this->getX() + this->HitBoxLD.X < 0 && this->getDirecaoX() == 0) {
		this->setDirecaoX(1);
		this->mover();
	} else if (this->getX() + this->HitBoxRU.X > this->Limites.X && this->getDirecaoX() == 0) {
		this->setDirecaoX(-1);
		this->mover();
	}
	
	if (
		(this->getY() - this->HitBoxRU.Y < 0 && this->getDirecaoY() < 0) ||
		(this->getY() - this->HitBoxLD.Y > this->Limites.Y && this->getDirecaoY() > 0)
	) {
		this->setDirecaoY(this->getDirecaoY() * -1);
		this->mover();
	} else if (this->getY() - this->HitBoxRU.Y < 0 && this->getDirecaoY() == 0) {
		this->setDirecaoY(1);
		this->mover();
	} else if (this->getY() - this->HitBoxLD.Y > this->Limites.Y && this->getDirecaoY() == 0) {
		this->setDirecaoY(-1);
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
