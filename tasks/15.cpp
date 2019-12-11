#include <Windows.h>
#include <iostream>
using namespace std;

void sort(int* a,int size) {
	int temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (a[j] < a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void print(int* a, int size) {
	for (int i = 0; i < size; i++) cout << a[i] << " ";
	cout << endl;
}

int main() {
	int n, temp, max, maxIndex;
	cin >> n;
	int a[5] = { NULL };
	
	cin >> a[0];
	cout <<endl<< a[0] << endl;
	max = a[0];
	maxIndex = 0;
	for (int i = 1; i < n; i++) {
		if (i < 5) {
			cin >> a[i];
			sort(a, i + 1);
			max = a[0];
		}
		else {
			cin >> temp;
			if (temp < max) {
				a[maxIndex] = temp;
				sort(a, 5);
				max = a[0];
				maxIndex = 0;
			}
		}
		i < 5 ? print(a, i + 1) : print(a, 5);
	}

	system("pause");
	return 0;
}
