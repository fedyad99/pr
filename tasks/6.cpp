#include <iostream>
#include <clocale>
using namespace std;

int main() {
	setlocale(LC_ALL, "russian");
	double a, b, c;
	cout << "Введите a,b,c" << endl;
	cin >> a >> b >> c;
	if (a + b + c == 0) cout << " 0 = 0, " << endl;
	else if (a + b == 0) cout << " Вы ввели " << c << " = 0, это не уравнение" << endl;
	else if (a + c == 0 || b + c == 0) {
		cout << "X = 0" << endl;
		return 0;
	}
	if (b * b - 4 * a * c < 0) {
		cout << "Действительных корней нет" << endl;
	}
	else if (b * b - 4 * a * c == 0) {
		cout << "x = " << -b / (2 * a) << endl;
	}
	else if (a == 0) {
		cout << "x = " << -c / b << endl;
	}
	else {
		cout << "x1 = " << (-b + sqrt(b * b - 4 * a * c)) / (2 * a) << endl;
		cout << "x2 = " << (-b - sqrt(b * b - 4 * a * c)) / (2 * a) << endl;
	}
	return 0;
}
