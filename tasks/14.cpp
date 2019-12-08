#include <iostream>
#include <clocale>
using namespace std;

void zap(long* mas, long a, long raz) {
	for (int i = 0; i < raz; i++) {
		mas[i] = a;
		a++;
	}
	return;
}

int main() {
	setlocale(LC_ALL, "Russian");

	long s, l1, r1, l2, r2, raz1, raz2;;
	cin >> s >> l1 >> r1 >> l2 >> r2;

	raz1 = r1 - l1 + 1;
	raz2 = r2 - l2 + 1;

	long* m1 = new long[raz1];
	long* m2 = new long[raz2];

	zap(m1, l1, raz1);
	zap(m2, l2, raz2);

	for(int i = 0;i<raz1;i++)
		for (int j = 0; j < raz2; j++) {
			if ((m1[i] + m2[j]) == s) {
				cout << m1[i] << " " << m2[j] << endl;
				return 0;
			}
		}
	cout << -1;
	return 0;
}