#include <iostream>
#include <clocale>
using namespace std;

bool prost(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cin >> n;
	if (prost(n)) cout << n << " - простое" << endl;
	else cout << n << " - составное" << endl;
	return 0;
}