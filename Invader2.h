#ifndef INVADER2
#define INVADER2

#include "Objeto.h"

class Invader2 : public Objeto {
	public:
		static constexpr COORD HitBoxRU = {8, 4};
		static constexpr COORD HitBoxLD = {-8, -6};
		
		Invader2(COORD, COORD);
		void imprime() const;
};

#endif
