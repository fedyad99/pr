#include <iostream>
#include <clocale>
using namespace std;

int main() {
	setlocale(LC_ALL, "russian");
	double a, b, c;
	cout << "Введите a,b,c" << endl;
	cin >> a >> b >> c;
	if (b * b - 4 * a * c < 0) {
		cout << "Действительных корней нет" << endl;
	} else if (b * b - 4 * a * c == 0) {
		cout << "x = " << -b / (2*a) << endl;
	} else if (a == 0) {
		cout << "x = " << -b / c << endl;
	  } else{
			cout << "x1 = " << (-b + sqrt(b * b - 4 * a * c))/ (2 * a) << endl;
			cout << "x2 = " << (-b - sqrt(b * b - 4 * a * c)) / (2 * a) << endl;
	   }
	return 0;
}