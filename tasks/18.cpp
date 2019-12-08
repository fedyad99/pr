#include <iostream>
#include <time.h>
using namespace std;


int main(){
	srand(time(NULL));
	const int size = 20;
	int mas[size];

	for (int i = 0; i < size; i++) mas[i] = rand() % 201 - 100;
	for (int i = 0; i < size; i++) cout << mas[i] << " ";

	int max = mas[0], min = mas[0];
	for (int i = 1; i < size; i++) {
		if (mas[i] > max) max = mas[i];
		else if (mas[i] < min) min = mas[i];
	}
	cout << endl << min << endl << max;
	return 0;
}
