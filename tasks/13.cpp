#include <iostream>
#include <clocale>
using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");
	long n,step = 1; int k = 0;
	cin >> n;
	if (n <= 0) {
		cout << 0;
		return 0;
	}
	while (step <= n) {
		k++;
		step *= 2;
	}
	cout << k;
	return 0;
}