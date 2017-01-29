#ifndef ATIRADOR
#define ATIRADOR

#include "Objeto.h"
#include "Tiro.h"

class Atirador : public Objeto {
	public:
		Atirador(COORD);
		void goToMouseX();
		void imprime() const;
};

#endif
