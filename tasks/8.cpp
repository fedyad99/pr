#include <iostream>
#include <clocale>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	double a, b; char n;
	cin >> a >> n >> b;
	switch (n) {
		case '+': cout << a << " + " << b << " = " << a + b << endl; break;
		case '-': cout << a << " - " << b << " = " << a - b << endl; break;
		case '*': cout << a << " * " << b << " = " << a * b << endl; break;
		case '/': 
			if (b == 0) {
				cout << "Делить на 0 нельзя" << endl;
				break;
			}
			cout << a << " / " << b << " = " << a / b << endl; break;
			break;
		default: cout << "Необходимо ввести один из знаков: +,/,-,*" << endl;
	}
	return 0;
}