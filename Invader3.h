#ifndef INVADER3
#define INVADER3

#include "Objeto.h"

class Invader3 : public Objeto {
	public:
		static constexpr COORD HitBoxRU = {7, 3};
		static constexpr COORD HitBoxLD = {-7, -4};
		
		Invader3(COORD, COORD);
		void imprime() const;
};

#endif
