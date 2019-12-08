#include <iostream>
#include <clocale>
using namespace std;

long fact(int n){
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	else
		return n * fact(n - 1);
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cin >> n;
	cout << n << "! = " << fact(n);
	return 0;
}