#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <Windows.h>
using namespace std;

void sort(int* arr, int len) {
	int temp;
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return;
}

int main() {
	setlocale(LC_ALL, "russian");
	int a;
	cin >> a;
	int* mas = new int[a];
	for (int i = 0; i < a; i++) {
		cin >> mas[i];
		cout << endl << endl;
		sort(mas, i + 1);
		for (int j = 0; j < i + 1; j++) {
			if (j < 4) {
				for (int k = j; k >= 0; k--) {
					cout << mas[k] << " ";
				}
			}
			else {
				for (int k = 4; k >= 0; k--) {
					cout << mas[k] << " ";
				}
			}
			cout << endl;
		}
		cout << endl << endl;
	}
	system("pause");
	return 0;
}