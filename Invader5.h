#ifndef INVADER5
#define INVADER5

#include "Objeto.h"

class Invader5 : public Objeto {
	public:
		static constexpr COORD HitBoxRU = {8, 4};
		static constexpr COORD HitBoxLD = {-8, -3};
		
		Invader5(COORD, COORD);
		void imprime() const;
};

#endif
