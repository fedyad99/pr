#include <iostream>
#include <time.h>
using namespace std;

/*			FOR TEST				*/

void print(int n, int m) {
	cout << "TEST; n  = " << n << " m = " << m << endl;
}

/*			FOR TEST				*/

void init(int** mas, int n, int m) {
	system("cls");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) mas[i][j] = 0;
	n = rand() % n;
	m = rand() % m;
	mas[n][m] = 1;

	/*			FOR TEST				*/
	print(n, m);
	/*			FOR TEST				*/
}

void game(int** mas, int n, int m) {
	init(mas, n, m);
	int CorX, CorY;
	int count = 1;
	while (count < 6) {
		cout << "Введите номер строки(0-9) и столбца(0-7)" << endl;
		cin >> CorX >> CorY;
		if (CorX > 9 || CorY < 0 || CorY>7 || CorY < 0) {
			cout << "Выход за границу массива" << endl;
			continue;
		}
		if (mas[CorX][CorY] == 2) {
			cout << "Эту уже проверяли" << endl;
			continue;
		}
		if (mas[CorX][CorY] == 1) {
			cout << " Вы угадали" << endl;
			return;
		}
		cout << "Нет" << endl;
		mas[CorX][CorY] = 2;
		count++;
		
	}
	cout << "GAME OVER" << endl;
}

int main(){
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int n = 10, m = 8; 
	int temp;

	int** mas = new int* [n];
	for (int i = 0; i < n; i++) mas[i] = new int[m] {0};

	do {
		game(mas, n, m);


		cout << endl << "Сыграть еще? 0 - выход" << endl;
		cin >> temp;
	} while (temp);
	return 0;
}
