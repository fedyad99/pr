#include "Game_p.h"
#include <iomanip>
#include <ctime>
#include <iostream>
using namespace std;

Game initGame(char userChar) {
	Game temp;
	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			temp.bord[i][j] = ' '; // Очистка поля

	time(NULL) % 2 == 0 ? temp.isUserTurn = true : temp.isUserTurn = false;  // Случайное определение первого хода

	temp.userChar = userChar; // Символ игрока
	temp.userChar == 'O' ? temp.botChar = 'X' : temp.botChar = 'O';  // Символ бота
	temp.status = PLAY;
	return temp;
}

void updateDisplay(const Game game) {
	system("cls");

	cout << "     1   2   3" << endl;
	cout << "   -------------" << endl;
	for (int j = 0; j < 3; j++) {
			cout <<" "<< j + 1 << " | "  << game.bord[j][0] << " | " << game.bord[j][1] << " | "  << game.bord[j][2] << " |" << endl;
			cout << "   -------------" << endl;
	}
}

void userTurn(Game* game) {
	cout << "Введите номер строки и столбца ячейки" << endl;
	char x1[3], y1[3];
	int x, y;
	cin >> x1; cin.get();
	cin >> y1; cin.get();
	do {
		x = atoi(x1); y = atoi(y1);
		 if (!x || !y || x > 3 || y > 3 || x < 1 || y < 1 || game->bord[x-1][y-1] == game->botChar || game->bord[x-1][y-1] == game->userChar) {
			updateDisplay(*game);
			cout << "Некорректные данные" << endl;
			userTurn(game);
			return;
		} else break;
	} while (1);
	game->bord[x-1][y-1] = game->userChar;
	updateDisplay(*game);
	game->isUserTurn = !game->isUserTurn;
}

int BordNotNullCount(Game game) {
	int k = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) if (game.bord[i][j] != ' ') k++;
	return k;
}

int* randTurn(Game game) {
	srand(time(NULL));
	static int turn[2];
	do{
		turn[0] = rand() % 3;
		turn[1] = rand() % 3;
		if (game.bord[turn[0]][turn[1]] == ' ') break;
	} while (true);
	return turn;
}

void botTurn(Game* game) {
	bool flag = true;
	if (BordNotNullCount(*game) == 0) game->bord[1][1] = game->botChar;
	else {
		//строка 1
		if (flag) {
			int k = 0;
			for (int i = 0; i < 3; i++) if (game->bord[0][i] == game->userChar) k++;
			if (k == 2) 
				for (int i = 0; i < 3; i++) 
					if (game->bord[0][i] == ' ') {
						game->bord[0][i] = game->botChar;
						flag = false;
						break;
					}
		}

		//строка 2
		if (flag) {
			int k = 0;
			for (int i = 0; i < 3; i++) if (game->bord[1][i] == game->userChar) k++;
			if (k == 2)
				for (int i = 0; i < 3; i++)
					if (game->bord[1][i] == ' ') {
						game->bord[1][i] = game->botChar;
						flag = false;
						break;
					}
		}

		//строка 3
		if (flag) {
			int k = 0;
			for (int i = 0; i < 3; i++) if (game->bord[2][i] == game->userChar) k++;
			if (k == 2)
				for (int i = 0; i < 3; i++)
					if (game->bord[2][i] == ' ') {
						game->bord[2][i] = game->botChar;
						flag = false;
						break;
					}
		}

		//столбик 1
		if (flag) {
			int k = 0;
			for (int i = 0; i < 3; i++) if (game->bord[i][0] == game->userChar) k++;
			if (k == 2)
				for (int i = 0; i < 3; i++)
					if (game->bord[i][0] == ' ') {
						game->bord[i][0] = game->botChar;
						flag = false;
						break;
					}
		}

		//столбик 2
		if (flag) {
			int k = 0;
			for (int i = 0; i < 3; i++) if (game->bord[i][0] == game->userChar) k++;
			if (k == 2)
				for (int i = 0; i < 3; i++)
					if (game->bord[i][0] == ' ') {
						game->bord[i][0] = game->botChar;
						flag = false;
						break;
					}
		}

		//столбик 3
		if (flag) {
			int k = 0;
			for (int i = 0; i < 3; i++) if (game->bord[i][0] == game->userChar) k++;
			if (k == 2)
				for (int i = 0; i < 3; i++)
					if (game->bord[i][0] == ' ') {
						game->bord[i][0] = game->botChar;
						flag = false;
						break;
					}
		}

		//главная диагональ
		if (flag) {
			int k = 0;
			for (int i = 0; i < 3; i++) if (game->bord[i][i] == game->userChar) k++;
			if (k == 2)
				for (int i = 0; i < 3; i++)
					if (game->bord[i][i] == ' ') {
						game->bord[i][i] = game->botChar;
						flag = false;
						break;
					}
		}

		//побочная диагональ
		if (flag) {
			int k = 0;
			if (game->bord[2][0] == game->userChar) k++;
			if (game->bord[1][1] == game->userChar) k++;
			if (game->bord[0][2] == game->userChar) k++;
			if (k == 2) {
				if (game->bord[2][0] == ' ') game->bord[2][0] = game->botChar;
				if (game->bord[1][1] == ' ') game->bord[2][0] = game->botChar;
				if (game->bord[0][2] == ' ') game->bord[2][0] = game->botChar;
				flag = false;
			}
		}

		//ход наугад
		if (flag) {
			int* turn = randTurn(*game);
			game->bord[turn[0]][turn[1]] = game->botChar;
			flag = false;
		}

	}

	updateDisplay(*game);
	game->isUserTurn = !game->isUserTurn;
}

bool checkSTR(Game game,int i) {
	if (game.bord[i][0] == game.bord[i][1] && game.bord[i][1] == game.bord[i][2])
		if (game.bord[i][0] != ' ') return true;
	return false;
}

bool checkST(Game game, int i) {
	if (game.bord[0][i] == game.bord[1][i] && game.bord[1][i] == game.bord[2][i])
		if(game.bord[0][i] != ' ') return true;
	return false;
}

bool checkDiagOS(Game game) {
	if (game.bord[0][0] == game.bord[1][1] && game.bord[1][1] == game.bord[2][2])
		if (game.bord[0][0] != ' ') return true;

	return false;
}

bool checkDiagPob(Game game) {
	if (game.bord[2][0] == game.bord[1][1] && game.bord[1][1] == game.bord[0][2])
		if (game.bord[1][1] != ' ') return true;

	return false;
}

bool updateGame(Game* game) {
	for (int i = 0; i < 3; i++) if (checkSTR(*game, i)) {
		game->bord[i][0] == game->botChar ? game->status = BOT_WIN : game->status = USER_WIN;
		return true;
	}

	for (int i = 0; i < 3; i++) if (checkST(*game, i)) {
		game->bord[0][i] == game->botChar ? game->status = BOT_WIN : game->status = USER_WIN;
		return true;
	}

	if (checkDiagOS(*game)) {
		game->bord[1][1] == game->botChar ? game->status = BOT_WIN : game->status = USER_WIN;
		return true;
	}

	if (checkDiagPob(*game)) {
		game->bord[1][1] == game->botChar ? game->status = BOT_WIN : game->status = USER_WIN;
		return true;
	}

	if (BordNotNullCount(*game) == 9) { game->status = NOT_WIN; return true; } 

	return false;
}