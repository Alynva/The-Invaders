#include <iostream>
#include <windows.h>

// Definando a área onde por onde os inimigos poderão se mover, para o bom funcionamento da função goToXY
#define LIMITEXMIN 9
#define LIMITEXMAX 70
#define LIMITEYMIN 5
#define LIMITEYMAX 50

#define QTDTIROS 5

using namespace std;

// HANDLE usado para mudar o cursor ou a cor
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
// csbi usado para pegar a posição do cursor
CONSOLE_SCREEN_BUFFER_INFO csbi;
// CursorPosition usado para guardar a posição do cursor
COORD CursorPosition;
// mousePos usada para armazenar a posição do mouse
POINT mousePos;

// goToXY usado para mudar a posição do cursor
void goToXY(int x, int y) {
	CursorPosition = {x, y};
	SetConsoleCursorPosition(console,CursorPosition); 
}

// getMouseXY usado para receber a posição do mouse
COORD getMouseXY() {
	GetCursorPos(&mousePos);
	return {mousePos.x, mousePos.y};
}

class Tiro {
	private:
		COORD Posicao;
		COORD Direcao = {0, -1};
	public:
		Tiro(int x, int y) {
			this->setPosicao(x, y);
		};
		void setPosicao(int x, int y) {
			this->Posicao = {x, y};
		}
		COORD getPosicao() const {
			return this->Posicao;
		}
		void mover() {
			this->Posicao.X += this->Direcao.X;
			this->Posicao.Y += this->Direcao.Y;
		}
		void imprime() const {
			SetConsoleTextAttribute(console, 15);
			goToXY(this->Posicao.X, this->Posicao.Y); cout << "*";
		}
};

Tiro *tiros[QTDTIROS] = {NULL};

// Class base pura utilizada para definir os Objetos
class Objeto {
	private:
		// Coordenada da posição e um "vetor" que define a direção do movimento
		COORD Posicao;
		COORD Direcao;
		int Color = 15;
	public:
		Objeto(int x, int y) {
			this->setPosicao(x, y);
			this->Direcao = {1, 0};
		}
		void setX(int x) {
			if (x >= LIMITEXMIN && x <= LIMITEXMAX)
				this->Posicao.X = x;
			else if (x > LIMITEXMAX)
				this->Posicao.X = LIMITEXMAX;
			else if (x < LIMITEXMIN);
		}
		int getX() const {
			return this->Posicao.X;
		}
		void setY(int y) {
			if (y >= LIMITEYMIN && y <= LIMITEYMAX)
				this->Posicao.Y = y;
			else if (y > LIMITEYMAX)
				this->Posicao.Y = LIMITEYMAX;
			else if (y < LIMITEYMIN)
				this->Posicao.Y = LIMITEYMIN;
		}
		int getY() const {
			return this->Posicao.Y;
		}
		void setPosicao(int x, int y) {
			this->setX(x);
			this->setY(y);
		}
		COORD getPosicao() const {
			return this->Posicao;
		}
		void setDirecaoX(int direcaoX) {
			this->Direcao.X = direcaoX;
		}
		int getDirecaoX() const {
			return this->Direcao.X;
		}
		void setDirecaoY(int direcaoY) {
			this->Direcao.Y = direcaoY;
		}
		int getDirecaoY() const {
			return this->Direcao.Y;
		}
		void mover() {
			this->setPosicao(this->getX() + this->Direcao.X, this->getY() + this->Direcao.Y);
		}
		void moverX(int qtd) {
			this->setX(this->Posicao.X + qtd);
		}
		void moverY(int qtd) {
			this->setY(this->Posicao.Y + qtd);
		}
		void setColor(int color) {
			this->Color = color;
		}
		int getColor() const {
			return this->Color;
		}
		virtual void imprime() const = 0;
};

class Invader1 : public Objeto {
	public:
		Invader1(int x, int y):Objeto(x, y) {}
		void imprime() const {
			SetConsoleTextAttribute(console, this->getColor());
			
			// LINHA 1
			goToXY(this->getX() - 3, this->getY() - 3); cout << "@";
			goToXY(this->getX() + 3, this->getY() - 3); cout << "@";
			
			// LINHA 2
			goToXY(this->getX() - 2, this->getY() - 2); cout << "@";
			goToXY(this->getX() + 2, this->getY() - 2); cout << "@";
			
			if (this->getX() % 2) {
				goToXY(this->getX() - 5, this->getY() - 2); cout << "@";
				goToXY(this->getX() + 5, this->getY() - 2); cout << "@";
			}
			
			// LINHA 3
			goToXY(this->getX() - 3, this->getY() - 1); cout << "@@@@@@@";
			
			if (this->getX() % 2) {
				goToXY(this->getX() - 5, this->getY() - 1); cout << "@";
				goToXY(this->getX() + 5, this->getY() - 1); cout << "@";
			}
			
			// LINHA 4
			goToXY(this->getX() - 4, this->getY()); cout << "@@";
			goToXY(this->getX() - 1, this->getY()); cout << "@@@";
			goToXY(this->getX() + 3, this->getY()); cout << "@@";
			
			if (this->getX() % 2) {
				goToXY(this->getX() - 5, this->getY()); cout << "@";
				goToXY(this->getX() + 5, this->getY()); cout << "@";
			}
			
			// LINHA 5
			goToXY(this->getX() - 5, this->getY() + 1); cout << "@@@@@@@@@@@";
			
			// LINHA 6
			goToXY(this->getX() - 3, this->getY() + 2); cout << "@@@@@@@";
			
			if (this->getX() % 2) {
				goToXY(this->getX() - 4, this->getY() + 2); cout << "@";
				goToXY(this->getX() + 4, this->getY() + 2); cout << "@";
			} else {
				goToXY(this->getX() - 5, this->getY() + 2); cout << "@";
				goToXY(this->getX() + 5, this->getY() + 2); cout << "@";
			}
			
			// LINHA 7
			goToXY(this->getX() - 3, this->getY() + 3); cout << "@";
			goToXY(this->getX() + 3, this->getY() + 3); cout << "@";
			
			if (this->getX() % 2 == 0){
				goToXY(this->getX() - 5, this->getY() + 3); cout << "@";
				goToXY(this->getX() + 5, this->getY() + 3); cout << "@";
			}
			
			// LINHA 8
			if (this->getX() % 2) {
				goToXY(this->getX() - 4, this->getY() + 4); cout << "@";
				goToXY(this->getX() + 4, this->getY() + 4); cout << "@";
			} else {
				goToXY(this->getX() - 2, this->getY() + 4); cout << "@@";
				goToXY(this->getX() + 1, this->getY() + 4); cout << "@@";
			}
			
			SetConsoleTextAttribute(console, 15);
		}
};

class Invader2 : public Objeto {
	public:
		Invader2(int x, int y):Objeto(x, y) {}
		void imprime() const {
			SetConsoleTextAttribute(console, this->getColor());
			
			// LINHA 1
			goToXY(this->getX() - 2, this->getY() - 4); cout << "@";
			goToXY(this->getX() + 2, this->getY() - 4); cout << "@";
			
			// LINHA 2
			goToXY(this->getX() - 2, this->getY() - 3); cout << "@@@@@";
			
			// LINHA 3
			goToXY(this->getX() - 4, this->getY() - 2); cout << "@@@@@@@@@";
			
			// LINHA 4
			goToXY(this->getX() - 5, this->getY() - 1); cout << "@";
			goToXY(this->getX() - 2, this->getY() - 1); cout << "@@@@@";
			goToXY(this->getX() + 5, this->getY() - 1); cout << "@";
			
			if (this->getX() % 2) {
				goToXY(this->getX() - 4, this->getY() - 1); cout << "@@";
				goToXY(this->getX() + 3, this->getY() - 1); cout << "@@";
			}
			
			// LINHA 5
			goToXY(this->getX() - 6, this->getY()); cout << "@@";
			goToXY(this->getX() - 1, this->getY()); cout << "@@@";
			goToXY(this->getX() + 5, this->getY()); cout << "@@";
			
			// LINHA 6
			goToXY(this->getX() - 8, this->getY() + 1); cout << "@@@@";
			goToXY(this->getX() - 1, this->getY() + 1); cout << "@";
			goToXY(this->getX() + 1, this->getY() + 1); cout << "@";
			goToXY(this->getX() + 5, this->getY() + 1); cout << "@@@@";
			
			// LINHA 7
			goToXY(this->getX() - 5, this->getY() + 2); cout << "@@@@@";
			goToXY(this->getX() + 1, this->getY() + 2); cout << "@@@@@";
			
			// LINHA 8
			goToXY(this->getX() - 3, this->getY() + 3); cout << "@@@@@@@";
			
			if (this->getX() % 2) {
				goToXY(this->getX() - 6, this->getY() + 3); cout << "@";
				goToXY(this->getX() + 6, this->getY() + 3); cout << "@";
			} else {
				goToXY(this->getX() - 5, this->getY() + 3); cout << "@";
				goToXY(this->getX() + 5, this->getY() + 3); cout << "@";
			}
			
			// LINHA 9
			goToXY(this->getX() - 3, this->getY() + 4); cout << "@";
			goToXY(this->getX() - 1, this->getY() + 4); cout << "@";
			goToXY(this->getX() + 1, this->getY() + 4); cout << "@";
			goToXY(this->getX() + 3, this->getY() + 4); cout << "@";
			
			if (this->getX() % 2) {
				goToXY(this->getX() - 7, this->getY() + 4); cout << "@";
				goToXY(this->getX() + 7, this->getY() + 4); cout << "@";
			} else {
				goToXY(this->getX() - 6, this->getY() + 4); cout << "@";
				goToXY(this->getX() + 6, this->getY() + 4); cout << "@";
			}
			
			// LINHA 10
			if (this->getX() % 2) {
				goToXY(this->getX() - 7, this->getY() + 5); cout << "@";
				goToXY(this->getX() + 7, this->getY() + 5); cout << "@";
			} else {
				goToXY(this->getX() - 6, this->getY() + 5); cout << "@";
				goToXY(this->getX() + 6, this->getY() + 5); cout << "@";
			}
			
			// LINHA 11
			if (this->getX() % 2) {
				goToXY(this->getX() - 6, this->getY() + 6); cout << "@";
				goToXY(this->getX() + 6, this->getY() + 6); cout << "@";
			} else {
				goToXY(this->getX() - 5, this->getY() + 6); cout << "@";
				goToXY(this->getX() + 5, this->getY() + 6); cout << "@";
			}
				
		}
};

class Invader3 : public Objeto {
	public:
		Invader3(int x, int y):Objeto(x, y) {}
		void imprime() const {
			SetConsoleTextAttribute(console, this->getColor());
			
			// LINHA 1
			goToXY(this->getX() - 2, this->getY() - 3); cout << "@@@@@";
			
			// LINHA 2
			goToXY(this->getX() - 5, this->getY() - 2); cout << "@@@@@@@@@@@";
			
			// LINHA 3
			goToXY(this->getX() - 6, this->getY() - 1); cout << "@@@@@@@@@@@@@";
			
			// LINHA 4
			goToXY(this->getX() - 6, this->getY()); cout << "@@@";
			goToXY(this->getX() - 1, this->getY()); cout << "@@@";
			goToXY(this->getX() + 4, this->getY()); cout << "@@@";
			
			// LINHA 5
			goToXY(this->getX() - 6, this->getY() + 1); cout << "@@@@@@@@@@@@@";
			
			// LINHA 6
			goToXY(this->getX() - 3, this->getY() + 2); cout << "@@";
			goToXY(this->getX() + 2, this->getY() + 2); cout << "@@";
			
			if (this->getX() % 2 == 0) {
				goToXY(this->getX() - 4, this->getY() + 2); cout << "@";
				goToXY(this->getX() + 4, this->getY() + 2); cout << "@";
			}
			
			// LINHA 7
			goToXY(this->getX() - 5, this->getY() + 3); cout << "@@";
			goToXY(this->getX() - 1, this->getY() + 3); cout << "@@@";
			goToXY(this->getX() + 4, this->getY() + 3); cout << "@@";
			
			// LINHA 8
			if (this->getX() % 2) {
				goToXY(this->getX() - 7, this->getY() + 4); cout << "@@";
				goToXY(this->getX() + 6, this->getY() + 4); cout << "@@";
			} else {
				goToXY(this->getX() - 4, this->getY() + 4); cout << "@@";
				goToXY(this->getX() + 3, this->getY() + 4); cout << "@@";
			}
		};
};

class Invader4 : public Objeto {
	public:
		Invader4(int x, int y):Objeto(x, y) {}
		void imprime() const {
			SetConsoleTextAttribute(console, this->getColor());
			
			// LINHA 1
			goToXY(this->getX() - 1, this->getY() - 3); cout << "@@@";
			
			// LINHA 2
			goToXY(this->getX() - 2, this->getY() - 2); cout << "@@@@@";
			
			// LINHA 3
			goToXY(this->getX() - 3, this->getY() - 1); cout << "@@@@@@@";
			
			// LINHA 4
			goToXY(this->getX() - 4, this->getY()); cout << "@@";
			goToXY(this->getX() - 1, this->getY()); cout << "@@@";
			goToXY(this->getX() + 3, this->getY()); cout << "@@";
			
			// LINHA 5
			goToXY(this->getX() - 4, this->getY() + 1); cout << "@@@@@@@@@";
			
			// LINHA 6
			if (this->getX() % 2) {
				goToXY(this->getX() - 3, this->getY() + 2); cout << "@";
				goToXY(this->getX() - 1, this->getY() + 2); cout << "@@@";
				goToXY(this->getX() + 3, this->getY() + 2); cout << "@";
			} else {
				goToXY(this->getX() - 2, this->getY() + 2); cout << "@";
				goToXY(this->getX() + 2, this->getY() + 2); cout << "@";
			}
			
			// LINHA 7
			if (this->getX() % 2) {
				goToXY(this->getX() - 4, this->getY() + 3); cout << "@";
				goToXY(this->getX() + 4, this->getY() + 3); cout << "@";
			} else {
				goToXY(this->getX() - 3, this->getY() + 3); cout << "@";
				goToXY(this->getX() - 1, this->getY() + 3); cout << "@@@";
				goToXY(this->getX() + 3, this->getY() + 3); cout << "@";
			}
			
			// LINHA 8
			if (this->getX() % 2) {
				goToXY(this->getX() - 3, this->getY() + 4); cout << "@";
				goToXY(this->getX() + 3, this->getY() + 4); cout << "@";
			} else {
				goToXY(this->getX() - 4, this->getY() + 4); cout << "@";
				goToXY(this->getX() - 2, this->getY() + 4); cout << "@";
				goToXY(this->getX() + 2, this->getY() + 4); cout << "@";
				goToXY(this->getX() + 4, this->getY() + 4); cout << "@";
			}
		};
};

class Invader5 : public Objeto {
	public:
		Invader5(int x, int y):Objeto(x, y) {}
		void imprime() const {
			SetConsoleTextAttribute(console, this->getColor());
			
			// LINHA 1
			goToXY(this->getX() - 3, this->getY() - 3); cout << "@@@@@@@";
			
			// LINHA 2
			goToXY(this->getX() - 5, this->getY() - 2); cout << "@@@@@@@@@@@";
			
			// LINHA 3
			goToXY(this->getX() - 6, this->getY() - 1); cout << "@@@@@@@@@@@@@";
			
			// LINHA 4
			goToXY(this->getX() - 7, this->getY()); cout << "@@";
			goToXY(this->getX() + 6, this->getY()); cout << "@@";
			
			if (this->getX() % 2) {
				goToXY(this->getX() - 5, this->getY()); cout << "@";
				goToXY(this->getX() - 3, this->getY()); cout << "@";
				goToXY(this->getX() - 1, this->getY()); cout << "@";
				goToXY(this->getX() + 1, this->getY()); cout << "@";
				goToXY(this->getX() + 3, this->getY()); cout << "@";
				goToXY(this->getX() + 5, this->getY()); cout << "@";
			} else {
				goToXY(this->getX() - 4, this->getY()); cout << "@";
				goToXY(this->getX() - 2, this->getY()); cout << "@";
				goToXY(this->getX(), this->getY()); cout << "@";
				goToXY(this->getX() + 2, this->getY()); cout << "@";
				goToXY(this->getX() + 4, this->getY()); cout << "@";
			}
			
			// LINHA 5
			goToXY(this->getX() - 8, this->getY() + 1); cout << "@@@@@@@@@@@@@@@@@";
			
			// LINHA 6
			goToXY(this->getX() - 6, this->getY() + 2); cout << "@@@";
			goToXY(this->getX() - 1, this->getY() + 2); cout << "@@@";
			goToXY(this->getX() + 4, this->getY() + 2); cout << "@@@";
			
			// LINHA 7
			goToXY(this->getX() - 5, this->getY() + 3); cout << "@";
			goToXY(this->getX() + 5, this->getY() + 3); cout << "@";
		};
};

class Atirador : public Objeto {
	public:
		Atirador(int x, int y):Objeto(x, y) {}
		void mover() {
			this->setX(getMouseXY().X / 8.5);
		}
		void atirar() {
			int i = 0;
			while (tiros[i] != NULL)
				i++;
			if (tiros[i] == NULL)
				tiros[i] = new Tiro(this->getX(), this->getY() - 4);
		}
		void imprime() const {
			for (int i = 0; i < QTDTIROS; i++) {
				if (tiros[i] != NULL) {
					if (tiros[i]->getPosicao().Y > 1) {
						tiros[i]->mover();
						tiros[i]->imprime();
					} else {
						tiros[i] = { NULL };
					}
				}
			}
			
			SetConsoleTextAttribute(console, this->getColor());
			
			// LINHA 1
			goToXY(this->getX(), this->getY() - 4); cout << "@";
			
			// LINHA 2
			goToXY(this->getX() - 1, this->getY() - 3); cout << "@@@";
			
			// LINHA 4
			goToXY(this->getX() - 5, this->getY() - 2); cout << "@@@@@@@@@@@";
			
			// LINHA 5
			goToXY(this->getX() - 6, this->getY() - 1); cout << "@@@@@@@@@@@@@";
			goToXY(this->getX() - 6, this->getY()); cout << "@@@@@@@@@@@@@";
			
		}
};

int main() {
	
	int i = 0, j = 0;
	
	// Criando um vetor de Objetos, utilizando a classe base
	Objeto *objetos[13] = {NULL};
	Atirador jogador(10, LIMITEYMAX);
	
	// Inicializando os objetos com classes derivadas da classe base
	
	objetos[0] = new Invader5(35, 5);
	objetos[0]->setColor(12);
	
	for (i = 1, j = 0; i < 4; i++, j++) {
		objetos[i] = new Invader2(j * 22 + 8 + LIMITEXMIN, 15);
		objetos[i]->setDirecaoX(-1);
		objetos[i]->setColor(i);
	}
	
	for (i = 4, j = 0; i < 7; i++, j++) {
		objetos[i] = new Invader4(j * 14 + 15 + LIMITEXMIN, 25);
		objetos[i]->setColor(i);
	}
	
	for (i = 7, j = 0; i < 10; i++, j++) {
		objetos[i] = new Invader3(j * 18 + 10 + LIMITEXMIN, 35);
		objetos[i]->setDirecaoX(-1);
		objetos[i]->setColor(i);
	}
	
	for (i = 10, j = 0; i < 13; i++, j++) {
		objetos[i] = new Invader1(j * 16 + 12 + LIMITEXMIN, 45);
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
				if (objetos[i]->getX() <= LIMITEXMIN && objetos[i]->getDirecaoX() < 0) {
					objetos[i]->setDirecaoX(1);
//					objetos[i]->moverY(10); // Em outro exemplo, ustilizava o método moverY para possibilitar movê-lo uma "linha" pra baixo sem necessitar alterar o "vetor" direção
				} else if (objetos[i]->getX() >= LIMITEXMAX && objetos[i]->getDirecaoX() > 0) {
					objetos[i]->setDirecaoX(-1);
//					objetos[i]->moverY(10);
				}
				// Atualiza a posição do objeto, de acordo com o "vetor" direção dele
				objetos[i]->mover();
				
				// Imprime o objeto em sua devida posição
				objetos[i]->imprime();
				
				for (int j = 0; j < QTDTIROS; j++) {
					if (tiros[j] != NULL) {
						if (tiros[j]->getPosicao().X == objetos[i]->getPosicao().X && tiros[j]->getPosicao().Y == objetos[i]->getPosicao().Y) {
							tiros[j] = { NULL };
							objetos[i] = { NULL };
							break;
						}
					}
				}
			}
		}
		jogador.mover();
//		if (rand() % 100 < 50)
			jogador.atirar();
		jogador.imprime();
		
		Sleep(200);
	} while (true);
	
	goToXY(0, LIMITEYMAX+10);
	
	return 7;
}
