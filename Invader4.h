#ifndef INVADER4
#define INVADER4

#include "Objeto.h"

class Invader4 : public Objeto {
	public:
		static constexpr COORD HitBoxRU = {4, 3};
		static constexpr COORD HitBoxLD = {-4, -4};
		
		Invader4(COORD, COORD);
		void imprime() const;
};

#endif
