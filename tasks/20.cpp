#include <iostream>
using namespace std;

void init(int* a,int size){
	for (int i = 0; i < size; i++) cin >> a[i];
}

void sort(int* a, int size) {
	int temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void print(int* a, int size) {
	for (int i = 0; i < size; i++) cout << a[i] <<" ";
}

int main(){
	int size;
	cin >> size;
	int* a = new int[size];
	init(a, size);
	sort(a, size);
	print(a, size);
	return 0;
}