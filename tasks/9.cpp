#include <iostream>
#include <clocale>
#include <ctime> 
#include <cstdlib> 
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	bool flag = true;
	int n,i,r;
	do {
		int k = rand() % 101;
		cout << "{Приветственное сообщение от игры}" << endl;
		for (i = 0; i < 5; i++) {
			cin >> n;
			if (n == k) {
				cout << "Поздравляю! Вы угадали" << endl;
				break;
			}
			else if (n < k) {
				cout << "Загаданное число больше" << endl;
			}
			else cout << "Загаданное число меньше"<< endl;
		}
		if (i == 5) cout << "Вы проиграли. Было загадано: " << k << endl;
		
		cout << "Хотите начать сначала? (1 - ДА )" << endl;
		cin >> r;
		if (r == 1) flag = true; else flag = false;
	} while (flag);
	return 0;
}