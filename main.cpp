#define QTDTIROS 5

#include "Invader1.h"
#include "Invader2.h"
#include "Invader3.h"
#include "Invader4.h"
#include "Invader5.h"
#include "Atirador.h"

#include "goToXY.h"

int main() {
	
	int i = 0, j = 0;
	
	// Criando um vetor de Objetos, utilizando a classe base
	Objeto *objetos[13] = {NULL};
	Atirador jogador({10, LIMITEYMAX});
	
	// Inicializando os objetos com classes derivadas da classe base
	
	objetos[0] = new Invader5({35, 5});
	objetos[0]->setDirecaoX(3);
	objetos[0]->setColor(12);
	
	for (i = 1, j = 0; i < 4; i++, j++) {
		objetos[i] = new Invader2({j * 22 + 8 + LIMITEXMIN, 15});
		objetos[i]->setDirecaoX(-1);
		objetos[i]->setColor(i);
	}
	
	for (i = 4, j = 0; i < 7; i++, j++) {
		objetos[i] = new Invader4({j * 14 + 15 + LIMITEXMIN, 25});
		objetos[i]->setColor(i);
	}
	
	for (i = 7, j = 0; i < 10; i++, j++) {
		objetos[i] = new Invader3({j * 18 + 10 + LIMITEXMIN, 35});
		objetos[i]->setDirecaoX(-1);
		objetos[i]->setColor(i);
	}
	
	for (i = 10, j = 0; i < 13; i++, j++) {
		objetos[i] = new Invader1({j * 16 + 12 + LIMITEXMIN, 45});
		objetos[i]->setColor(i+3);
	}
	
	do {
		system("cls");
		
		for (i = 0; i < LIMITEXMAX + LIMITEXMIN; i++) {
			goToXY(i, 0); cout << "-";
			goToXY(i, LIMITEYMAX + 1); cout << "-";
		}
		for (i = 0; i < LIMITEYMAX + 1; i++) {
			goToXY(0, i); cout << "|";
			goToXY(LIMITEXMAX + LIMITEXMIN, i); cout << "|";
		}
		
		for (i = 0; i < 13; i++) {
			if (objetos[i] != NULL) {
//				if ((objetos[i]->getX() <= LIMITEXMIN && objetos[i]->getDirecaoX() < 0) || (objetos[i]->getX() >= LIMITEXMAX && objetos[i]->getDirecaoX() > 0)) {
//					objetos[i]->setDirecaoX(objetos[i]->getDirecaoX() * -1);
////					objetos[i]->moverY(10);
//				}
				// Atualiza a posi��o do objeto, de acordo com o "vetor" dire��o dele
				objetos[i]->mover();
				
				// Imprime o objeto em sua devida posi��o
				objetos[i]->imprime();
				
//				for (int j = 0; j < QTDTIROS; j++) {
//					if (tiros[j] != NULL) {
//						if (tiros[j]->getPosicao().X == objetos[i]->getPosicao().X && tiros[j]->getPosicao().Y == objetos[i]->getPosicao().Y) {
//							tiros[j] = { NULL };
//							objetos[i] = { NULL };
//							break;
//						}
//					}
//				}
			}
		}
		jogador.goToMouseX();
//		if (rand() % 100 < 50)
			jogador.atirar({0, -1});
		jogador.imprime();
		
		Sleep(200);
	} while (false);
	
	goToXY(0, LIMITEYMAX+10);
	
	return 7;
}
