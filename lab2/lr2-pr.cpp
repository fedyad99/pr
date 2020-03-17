#include <iostream>
#include <iomanip>
using namespace std;

bool Equal(double a, double b, double epsilon)
{
	return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

int main(){
	setlocale(LC_ALL,"Russian");
	double a, b, xn, xk, dx;
	cout << "Введите a, b, xn, xk, dx" << endl;
	cin >> a >> b >> xn >> xk >> dx;
	double y, min, max;
	for (double x = xn; x < xk || Equal(x, xk, 0.00001); x += dx) {
		
		if (x < a || Equal(x, a, 0.00001)) {
			y = exp(x);
		}
		else if (x < b) {
			y = exp(x) + cos(x);
		}
		else {
			if ( Equal( cos(x), 0, 0.0001)) {
				y = tan(x);
			}
			else cout << "При x = " << x << " корней нет" << endl;
		}
		if (Equal(x, xn, 0.00001)) {
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
