#define QTDTIROS 5

#include "Invader1.h"
#include "Invader2.h"
#include "Invader3.h"
#include "Invader4.h"
#include "Invader5.h"
#include "Atirador.h"

int main() {
	int wFont, hFont;
	string null;
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << "\t>>\t\t!!!\t\t\tINSTRUCOES INICIAIS\t\t\t!!!\t\t<<" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "\t1.\tClique com o botao direito na barra superior da janela;" << endl;
	cout << "\t2.\tClique em \"Propriedades\";" << endl;
	cout << "\t\t2.1.\tPARA ALTERAR O TAMANHO DA FONTE" << endl;
	cout << "\t\t\t2.1.1.\tNavegue ate a aba \"Fonte\";" << endl;
	cout << "\t\t\t2.1.2.\tEscolha o tamanho desejado, lembre-se do escolhido pois sera necessario inseri-lo no termino das instrucoes;" << endl;
	cout << endl << "\t\t\t\tDICA: QUANTO MENOR A FONTE, MAIS ESPECO HAVERA" << endl << endl;
	cout << "\t\t2.2.\tPARA ALTERAR O TAMANHO DA JANELA (para as versoes anteriores ao Windows 10)" << endl;
	cout << "\t\t\t2.2.1.\tNavegue ate a aba \"Layout\";" << endl;
	cout << "\t\t\t2.2.2.\tDefina os valores na area \"Tamanho da janela\";" << endl;
	cout << "\t\t\t2.2.3.\tApos defini-lo, certifique-se que os valores de \"Tamanho do buffer de tela\" sao iguais aos de \"Tamanho da janela\", para que nao apareca a barra de rolagem e possa haver uma maior utilizacao da janela;" << endl;
	cout << "\t3.\tDe OK;" << endl;
	cout << "\t4.\tCaso a alteracao tenha cortado alguma instrucao que voce queira ler, feche o programa e abre-o novamente para que o programa as imprimam corretamente;" << endl;
	cout << "\t5.\tAgora, para calibrar a posicao do mouse, sera necessario que voce digite o tamanho da fonte inserida (exemplos: \"4 x 6\", \"8 x 8\", \"8 x 12\"): ";
	cin >> wFont >> null >> hFont;
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	
	int i = 0, j = 0;
	
	CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	COORD maxOnScreen {csbi.srWindow.Right - csbi.srWindow.Left, csbi.srWindow.Bottom - csbi.srWindow.Top};
	
	// Criando um vetor de Objetos, utilizando a classe base
	Objeto *objetos[13] = {NULL};
	Atirador jogador({10, maxOnScreen.Y}, maxOnScreen);
	Tiro *tiroJogador[1](jogador.getX(), jogador.getY() + jogador.HitBoxRU.Y);
	
	// Inicializando os objetos com classes derivadas da classe base
	
	int posInicial = rand() % maxOnScreen.X;
	int dirInicial;
	objetos[0] = new Invader5({posInicial, 5}, maxOnScreen);
	objetos[0]->setPosicao({objetos[0]->getX() + objetos[0]->HitBoxRU.X, objetos[0]->getY()});
	objetos[0]->setDirecaoX(3);
	objetos[0]->setColor(12);
	
	posInicial = rand() % maxOnScreen.X;
	for (i = 1, j = 0; i < 4; i++, j++) {
		objetos[i] = new Invader2({j * 23 + posInicial, 13}, maxOnScreen);
		objetos[i]->setPosicao({objetos[i]->getX() + objetos[i]->HitBoxRU.X, objetos[i]->getY()});
		objetos[i]->setDirecaoX(-1);
		objetos[i]->setColor(i);
	}
	
	posInicial = rand() % maxOnScreen.X;
	for (i = 4, j = 0; i < 7; i++, j++) {
		objetos[i] = new Invader4({j * 15 + posInicial, 23}, maxOnScreen);
		objetos[i]->setPosicao({objetos[i]->getX() + objetos[i]->HitBoxRU.X, objetos[i]->getY()});
		objetos[i]->setDirecaoX(1);
		objetos[i]->setColor(i);
	}
	
	posInicial = rand() % maxOnScreen.X;
	for (i = 7, j = 0; i < 10; i++, j++) {
		objetos[i] = new Invader1({j * 19 + posInicial, 31}, maxOnScreen);
		objetos[i]->setPosicao({objetos[i]->getX() + objetos[i]->HitBoxRU.X, objetos[i]->getY()});
		objetos[i]->setDirecaoX(-1);
		objetos[i]->setColor(i);
	}
	
	posInicial = rand() % maxOnScreen.X;
	for (i = 10, j = 0; i < 13; i++, j++) {
		objetos[i] = new Invader3({j * 23 + posInicial, 39}, maxOnScreen);
		objetos[i]->setPosicao({objetos[i]->getX() + objetos[i]->HitBoxRU.X, objetos[i]->getY()});
		objetos[i]->setDirecaoX(1);
		objetos[i]->setColor(i+3);
	}
	
	// CLIQUE DO MOUSE
	
    DWORD cNumRead, fdwMode, fdwSaveOldMode, q; 
    INPUT_RECORD irInBuf[128]; 

	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hStdin, &fdwSaveOldMode);
	fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT; 
    SetConsoleMode(hStdin, fdwMode);
    
	//
	int state = 0;
	do {
		system("cls");

//		for (i = 0; i < maxOnScreen.X + 1; i++) {
//			for (j = 0; j < maxOnScreen.Y + 1; j++) {
//				goToXY(i, j); cout << " ";
//			}
//		}
		
		// TESTE EVENTO DO MOUSE
//		GetNumberOfConsoleInputEvents (hStdin, &cNumRead);
//		if (cNumRead) {
//			ReadConsoleInput(hStdin, irInBuf, 128, &cNumRead);
//			cout << 1;
			for (q = 0; q < cNumRead; q++) {
//				cout << cNumRead;
	        	if (irInBuf[q].EventType == MOUSE_EVENT) {
	//        		printf("\nMouse event: ");
	        		if (irInBuf[q].Event.MouseEvent.dwEventFlags == 0) {
	        			if(irInBuf[q].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
//			                printf("left button press \n");
							state = 1;
			            } else if(irInBuf[q].Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED) {
	//		                printf("right button press \n");
							state = 2;
			            } else {
	//		                printf("button press\n");
							state = 3;
			            }
					}
				}
	        }
//	    }
//	    cout << state;
//		if (state == 1) cout << "left";
		
		//
		
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
		jogador.goToMouseX(wFont);
//		if (rand() % 100 < 50)
			jogador.atirar({0, -1});
		jogador.imprime();
		
		Sleep(100);
	} while (true);
	
	goToXY(0, LIMITEYMAX+10);
	
	return 7;
}
