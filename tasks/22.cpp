#include <iostream>
using namespace std;

void swap(int* a, int* b) {
	int *temp = a;
	a = b;
	b = temp;
}

int msort(int* a, int* b, int* c) {
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > c) swap(a, c);
	return *c;
}

void info(const int* a) {
	cout << "Адрес: " <<a <<";" << " Значение: "<< *a << ";" << endl;
}

int* add(int* a, const int* b) {
	*a = *a + *b;
	return a;
}

int main(){
	setlocale(LC_ALL, "Russian");
	int a = 1, b = 2, c = 3;

	info(&a);
	info(&b);
	info(&c);

	cout << "Максимум " << msort(&a, &b, &c) << endl;

	info(add(&a, add(&b, &c)));
	return 0;
}