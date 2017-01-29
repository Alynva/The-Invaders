#ifndef INVADER1
#define INVADER1

#include "Objeto.h"

class Invader1 : public Objeto {
	public:
		static constexpr COORD HitBoxRU = {5, 3};
		static constexpr COORD HitBoxLD = {-5, -4};
		
		Invader1(COORD, COORD);
		void imprime() const;
};

#endif
