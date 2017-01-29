#ifndef ATIRADOR
#define ATIRADOR

#include "Objeto.h"
#include "Tiro.h"

class Atirador : public Objeto {
	public:
//		static constexpr COORD HitBoxRU = {6, 4};
//		static constexpr COORD HitBoxLD = {-6, 0};
		
		Atirador(COORD, COORD);
		void goToMouseX();
		void imprime() const;
};

#endif
