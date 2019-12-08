#include <iostream>
#include <clocale>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int key;
	cin >> key;
	switch (key) {
		case 1: 
			cout << "Введите длины сторон треугольника" << endl;
			double a, b, c;
			if(a <= 0 || b <= 0 || c <= 0 || (a+b)<=c || (b+c)<=a || (a+c)<+b){
			cout << "Введены некорректные данные"<<endl;
			break;
			}
			cin >> a >> b >> c;
			cout << "S = " << sqrt(((a + b + c) / 2) * (((a + b + c) / 2) - a )* (((a + b + c) / 2) - b )* (((a + b + c) / 2) - c))<<endl;
			break;
		case 2: 
			double A1, A2, B1, B2, C1, C2;
			cout << "Введите координаты сторон треугольника" << endl;
			cin >> A1 >> A2 >> B1 >> B2 >> C1 >> C2;
			cout << "S = " << abs((A1-C1)*(B2-C2) - (B2-C2)*(A2-C2))/2 << endl;
			break;
		default: cout << "Неверное значение ключа";
	}
	return 0;
}