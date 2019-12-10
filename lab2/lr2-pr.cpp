#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	setlocale(LC_ALL,"Russian");
	double a, b, xn, xk, dx;
	cout << "Введите a, b, xn, xk, dx" << endl;
	cin >> a >> b >> xn >> xk >> dx;
	double y, min, max;
	for (double x = xn; x < xk+0.05; x += dx) {
		
		if (x <= a) {
			y = exp(x);
		}
		else if (x < b) {
			y = exp(x) + cos(x);
		}
		else {
			if (cos(x) != 0) {
				y = tan(x);
			}
			else cout << "При x = " << x << " корней нет" << endl;
		}
		if (x == xn) {
			min = y;
			max = y;
		}

		if (y > max) max = y;
		if (y < min) min = y;
		cout << "X = " << setw(4)<< x << " Y = " << setw(6) << y << endl;
	}
	cout << "Максимум: "<< max << endl;
	cout << "Минимум: " << min << endl;
	return 0;
}
