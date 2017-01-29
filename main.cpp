#define QTDTIROS 5

#include "Invader1.h"
#include "Invader2.h"
#include "Invader3.h"
#include "Invader4.h"
#include "Invader5.h"
#include "Atirador.h"

int main() {
	
	int i = 0, j = 0;
	
	bool pronto = false;
	COORD maxOnScreen {10, 10};
	string cmd;
	short int x, y;
	do {
		system("cls");
		
		for (i = 0; i < maxOnScreen.X; i++) {
			goToXY(i, 0); cout << "-";
			goToXY(i, maxOnScreen.Y); cout << "-";
		}
		for (i = 0; i < maxOnScreen.Y; i++) {
			goToXY(0, i); cout << "|";
			goToXY(maxOnScreen.X, i); cout << "|";
		}
		goToXY(0, 0); cout << "+";
		goToXY(maxOnScreen.X, 0); cout << "+";
		goToXY(0, maxOnScreen.Y); cout << "+";
		goToXY(maxOnScreen.X, maxOnScreen.Y); cout << "+";
		
		goToXY(2, 0);
		
		cout << "Maximize a área para caber dentro da sua tela (formado \"x: [valor] y: [valor]\")(atual: " << maxOnScreen.X << " " << maxOnScreen.Y << ")(digite \"sair\" para continuar): ";
		cin >> cmd;
		if (cmd != "sair") {
			cin >> x >> cmd >> y;
			maxOnScreen = {x, y};
		} else {
			pronto = true;
		}
	} while (!pronto);
	
	// Criando um vetor de Objetos, utilizando a classe base
	Objeto *objetos[13] = {NULL};
	Atirador jogador({10, LIMITEYMAX}, maxOnScreen);
	
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
		
		for (i = 0; i < 13; i++) {
			if (objetos[i] != NULL) {
//				if ((objetos[i]->getX() <= LIMITEXMIN && objetos[i]->getDirecaoX() < 0) || (objetos[i]->getX() >= LIMITEXMAX && objetos[i]->getDirecaoX() > 0)) {
//					objetos[i]->setDirecaoX(objetos[i]->getDirecaoX() * -1);
////					objetos[i]->moverY(10);
//				}
				// Atualiza a posição do objeto, de acordo com o "vetor" direção dele
				objetos[i]->mover();
				
				// Imprime o objeto em sua devida posição
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
	} while (true);
	
	goToXY(0, LIMITEYMAX+10);
	
	return 7;
}
