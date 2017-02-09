#define QTDTIROSJOGADOR 3
#define QTDVIDASJOGADOR 1

#define QTDTIROSALIENS 5

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
	cout << ">>\t!!!\t\tINSTRUCOES DE CONFIGURACAO\t\t!!!\t<<" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "1.\tClique com o botao direito na barra superior da janela;" << endl;
	cout << "2.\tClique em \"Propriedades\";" << endl;
	cout << "\t2.1.\tPARA ALTERAR O TAMANHO DA FONTE" << endl;
	cout << "\t\t2.1.1.\tNavegue ate a aba \"Fonte\";" << endl;
	cout << "\t\t2.1.2.\tEscolha o tamanho desejado, lembre-se do escolhido pois sera necessario inseri-lo no termino das instrucoes;" << endl;
	cout << endl << "\t\t\tDICA: QUANTO MENOR A FONTE, MAIS ESPECO HAVERA" << endl << endl;
	cout << "\t2.2.\tPARA ALTERAR O TAMANHO DA JANELA (para as versoes anteriores ao Windows 10)" << endl;
	cout << "\t\t2.2.1.\tNavegue ate a aba \"Layout\";" << endl;
	cout << "\t\t2.2.2.\tDefina os valores na area \"Tamanho da janela\";" << endl;
	cout << "\t\t2.2.3.\tApos defini-lo, certifique-se que os valores de \"Tamanho do buffer de tela\" sao iguais aos de \"Tamanho da janela\", para que nao apareca a barra de rolagem e possa haver uma maior utilizacao da janela;" << endl;
	cout << "3.\tDe OK;" << endl;
	cout << "4.\tCaso a alteracao tenha cortado alguma instrucao que voce queira ler, feche o programa e abre-o novamente para que o programa as imprimam corretamente;" << endl;
	cout << "5.\tAgora, para calibrar a posicao do mouse, sera necessario que voce digite o tamanho da fonte inserida (exemplos: \"4 x 6\", \"8 x 8\", \"8 x 12\"): ";
	cin >> wFont >> null >> hFont;
	
	system("cls");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	cout << ">>\t!!!\t\tINSTRUCOES DE JOGABILIDADE\t\t!!!\t<<" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	
	cout << "1.\tA posicao do Canhao Laser e baseada na posicao do seu mouse;" << endl;
	cout << "2.\tOs Lasers sao disparados em espacos de tempo aleatorios, com o limite de " << QTDTIROSJOGADOR << " tiros para o jogador e " << QTDTIROSALIENS << " tiros para os inimigos;" << endl;
	cout << "3.\tVocê tera apenas " << QTDVIDASJOGADOR << " vidas, o programa fechara a sim que elas chegarem a 0 (zero)." << endl << endl;
	
	system("pause");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
	
	CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	COORD maxOnScreen {csbi.srWindow.Right - csbi.srWindow.Left, csbi.srWindow.Bottom - csbi.srWindow.Top};
	
	int i = 0, j = 0, nvl = 1;
	
	// Criando um vetor de Objetos, utilizando a classe base
	Objeto *aliens;
	Tiro *tirosAliens[QTDTIROSALIENS] = { NULL };
	Atirador jogador({10, maxOnScreen.Y}, maxOnScreen);
	Tiro *tirosJogador[QTDTIROSJOGADOR] = { NULL };
	int armaAquecidaJogador = 0;
	
	do {
	

	//	objetos[0] = new Invader5({10, 5}, maxOnScreen);
	//	objetos[0]->setPosicao({(short int) objetos[0]->getX() + objetos[0]->HitBoxRU.X, (short int) objetos[0]->getY()});
	//	objetos[0]->setDirecaoX(3);
	//	objetos[0]->setColor(12);
	//	
	//	posInicial = rand() % maxOnScreen.X;
	//	for (i = 1, j = 0; i < 4; i++, j++) {
	//		objetos[i] = new Invader2({(short int) j * 23 + 30, (short int) 13}, maxOnScreen);
	//		objetos[i]->setPosicao({(short int) objetos[i]->getX() + objetos[i]->HitBoxRU.X, (short int) objetos[i]->getY()});
	//		objetos[i]->setDirecaoX(-1);
	//		objetos[i]->setColor(i);
	//	}
	//	
	//	posInicial = rand() % maxOnScreen.X;
	//	for (i = 4, j = 0; i < 7; i++, j++) {
	//		objetos[i] = new Invader4({j * 15 + posInicial, 23}, maxOnScreen);
	//		objetos[i]->setPosicao({objetos[i]->getX() + objetos[i]->HitBoxRU.X, objetos[i]->getY()});
	//		objetos[i]->setDirecaoX(1);
	//		objetos[i]->setColor(i);
	//	}
	//	
	//	posInicial = rand() % maxOnScreen.X;
	//	for (i = 7, j = 0; i < 10; i++, j++) {
	//		objetos[i] = new Invader1({j * 19 + posInicial, 31}, maxOnScreen);
	//		objetos[i]->setPosicao({objetos[i]->getX() + objetos[i]->HitBoxRU.X, objetos[i]->getY()});
	//		objetos[i]->setDirecaoX(-1);
	//		objetos[i]->setColor(i);
	//	}
	//	
	//	posInicial = rand() % maxOnScreen.X;
	//	for (i = 10, j = 0; i < 13; i++, j++) {
	//		objetos[i] = new Invader3({j * 23 + posInicial, 39}, maxOnScreen);
	//		objetos[i]->setPosicao({objetos[i]->getX() + objetos[i]->HitBoxRU.X, objetos[i]->getY()});
	//		objetos[i]->setDirecaoX(1);
	//		objetos[i]->setColor(i+3);
	//	}
		
		do {
			system("cls");
								
			for (j = 0; j < QTDTIROSALIENS; j++)
				if (tirosAliens[j] != NULL) {
					tirosAliens[j]->mover();
					tirosAliens[j]->imprime();
					if (tirosAliens[j]->getPosicao().Y > maxOnScreen.Y - 4)
						tirosAliens[j] = { NULL };
				}
								
			for (j = 0; j < QTDTIROSJOGADOR; j++)
				if (tirosJogador[j] != NULL) {
					tirosJogador[j]->mover();
					tirosJogador[j]->imprime();
					if (tirosJogador[j]->getPosicao().Y < 4)
						tirosJogador[j] = { NULL };
				}
			
	//		for (i = 0; i < 13; i++) {
	//			if (objetos[i] != NULL) {
	//				// Atualiza a posição do objeto, de acordo com o "vetor" direção dele
	//				objetos[i]->mover();
	//				
	//				if (rand() % 100 < 2) {
	//					int index = rand() % QTDTIROSALIENS;
	//						if (tirosAliens[index] == NULL) {
	//							tirosAliens[index] = new Tiro({(short int) objetos[i]->getX(), (short int) objetos[i]->getY() - objetos[i]->HitBoxLD.Y});
	//							tirosAliens[index]->setDirecao({0, 3});
	//						}
	//				}
	//				
	//				// Imprime o objeto em sua devida posição
	//				objetos[i]->imprime();
	//				
	//				for (j = 0; j < QTDTIROSJOGADOR; j++)
	//					if (tirosJogador[j] != NULL)
	//						if (
	//							tirosJogador[j]->getPosicao().X >= objetos[i]->getPosicao().X + objetos[i]->HitBoxLD.X &&
	//							tirosJogador[j]->getPosicao().X <= objetos[i]->getPosicao().X + objetos[i]->HitBoxRU.X &&
	//							
	//							tirosJogador[j]->getPosicao().Y >= objetos[i]->getPosicao().Y - objetos[i]->HitBoxRU.Y &&
	//							tirosJogador[j]->getPosicao().Y <= objetos[i]->getPosicao().Y - objetos[i]->HitBoxLD.Y
	//						) {
	//							objetos[i] = { NULL };
	//							tirosJogador[j] = { NULL };
	//							break;
	//						}
	//			}
	//		}
			
			jogador.goToMouseX(wFont);
			
			if (!armaAquecidaJogador)
				for (j = 0; j < QTDTIROSJOGADOR; j++)
					if (tirosJogador[j] == NULL) {
						tirosJogador[j] = new Tiro({(short int) jogador.getX(), (short int) jogador.getY() - jogador.HitBoxLD.Y});
						tirosJogador[j]->setDirecao({0, -3});
						armaAquecidaJogador -= 10;
						break;
					}
			jogador.imprime();
			
			if (armaAquecidaJogador < 0)
			armaAquecidaJogador++;
			
			for (j = 0; j < QTDTIROSALIENS; j++)
				if (tirosAliens[j] != NULL)
					if (
						tirosAliens[j]->getPosicao().X >= jogador.getPosicao().X + jogador.HitBoxLD.X &&
						tirosAliens[j]->getPosicao().X <= jogador.getPosicao().X + jogador.HitBoxRU.X &&
						
						tirosAliens[j]->getPosicao().Y >= jogador.getPosicao().Y - jogador.HitBoxRU.Y &&
						tirosAliens[j]->getPosicao().Y <= jogador.getPosicao().Y - jogador.HitBoxLD.Y
					) {
						goToXY(0, LIMITEYMAX+10); return 100;
					}
	
			Sleep(100);
		} while (true);
	} while (nvl < 5);
	
	goToXY(0, LIMITEYMAX+10); return 7;
}
