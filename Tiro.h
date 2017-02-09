#ifndef TIRO
#define TIRO

#include <windows.h>

class Tiro {
	private:
		COORD Posicao;
		COORD Direcao = {0, -1};
	public:
		Tiro(COORD);
		void setPosicao(COORD);
		COORD getPosicao() const;
		void setDirecao(COORD);
		COORD getDirecao() const;
		void mover();
		void imprime() const;
};
//Tiro *tiros[QTDTIROS] = {NULL};

#endif
