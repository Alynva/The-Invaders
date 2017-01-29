#ifndef ATIRADOR
#define ATIRADOR

#include "Objeto.h"
#include "Tiro.h"

class Atirador : public Objeto {
	public:
		Atirador(COORD, COORD);
		void goToMouseX(int);
		void imprime() const;
};

#endif
