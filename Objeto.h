#ifndef OBJETO
#define OBJETO

#include <iostream>
#include <windows.h>
using namespace std;

// Definando a área onde por onde os inimigos poderão se mover, para o bom funcionamento da função goToXY
#define LIMITEXMIN 9
#define LIMITEXMAX 70
#define LIMITEYMIN 5
#define LIMITEYMAX 50

#include "Tiro.h"

#include "getMouseXY.h"
#include "goToXY.h"

// Class base pura utilizada para definir os Objetos
class Objeto {
	private:
		// Coordenada da posição e um "vetor" que define a direção do movimento
		COORD Posicao;
		COORD Direcao;
		int Color = 15;
		Tiro *tiros[1] = { NULL };
	public:
		const COORD HitBoxUR; // U == "UP" && R == "RIGTH"
		const COORD HitBoxDL; // D == "DOWN" && L == "LEFT"
		
		Objeto(COORD, COORD = {0, 0}, COORD = {0, 0});
		void setX(int);
		int getX() const;
		void setY(int);
		int getY() const;
		void setPosicao(COORD);
		COORD getPosicao() const;
		void setDirecaoX(int);
		int getDirecaoX() const;
		void setDirecaoY(int);
		int getDirecaoY() const;
		void mover();
		void moverX(int);
		void moverY(int);
		void setColor(int);
		int getColor() const;
		void atirar(COORD);
		virtual void imprime() const = 0;
};

#endif
