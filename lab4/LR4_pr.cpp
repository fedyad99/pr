#include <iostream>
#include "Game_p.h"
using namespace std;

int main(){
	setlocale(LC_ALL, "Russian");
	char UserChar;
	cout << "Введите UserChar (O или X)" << endl;\

	do {
		cin >> UserChar;
	} while (UserChar != 'O' && UserChar != 'X');
	Game game = initGame(UserChar);

	do {
		updateDisplay(game);
		game.isUserTurn ? userTurn(&game) : botTurn(&game);
		updateGame(&game);
	} while (game.status == PLAY);
	
	if (game.status == NOT_WIN) cout << "Ничья!" << endl;
		else if (game.status == BOT_WIN) cout << "Победа бота!" << endl;
			else cout << "Победа игрока!" << endl;

	return 0;
}
