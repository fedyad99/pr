#include <iostream>
#include <clocale>
#include <vector>
#include <ctime>
using namespace std;

enum Order { 
	ASC, // по возрастанию
	DESC // по убыванию
};

/*  Проверка   */
/*  Массив  */
bool check(int* a, int size, Order order) {
	switch (order) {
	case ASC:
		for (int i = 0; i < size - 1; i++) {
			if (a[i] > a[i + 1]) {
				return false;
				break;
			}
		}
		break;
	case DESC:
		for (int i = 0; i < size - 1; i++) {
			if (a[i] < a[i + 1]) {
				return false;
				break;
			}
		}
		break;
	}
	return true;
}

/*  Вектор  */
bool check(vector<int> &a, Order order) {
	switch (order) {
	case ASC:
		for (int i = 0; i < a.size() - 1; i++) {
			if (a[i] > a[i + 1]) {			
				return false;
				break;
			}
		}
		break;
	case DESC:
		for (int i = 0; i < a.size() - 1; i++) {
			if (a[i] < a[i + 1]) {				
				return false;
				break;
			}
		}
		break;
	}

	return true;
}

/*  3 числа  */
bool check(int a, int b, int c, Order order) {
	switch (order) {
	case ASC:
		if (b > c || a > b || a > c) return false;
		break;
	case DESC:
		if (b < c || a < b || a < c) return false;
		break;
	}
	return true;
}

/*  Сортировка  */
/*  Массив  */
void BozoSort(int *a, int size, Order order = ASC) {
	bool sorted = check(a,size,order);
	while (!sorted) {
		int index1 = rand() % size;
		int index2 = rand() % size;

		int temp = a[index2];
		a[index2] = a[index1];
		a[index1] = temp;

		sorted = check(a, size, order);

	}
}

/*  Вектор  */
void BozoSort(vector<int> &a, Order order = ASC) {
	bool sorted = check(a, order);
	while (!sorted) {
		int index1 = rand() % a.size();
		int index2 = rand() % a.size();
		
		int temp = a[index2];
		a[index2] = a[index1];
		a[index1] = temp;

		sorted = check(a, order);

	}
}

/*  3 числа  */
void BozoSort(int& x, int& y, int& z, Order order = ASC) {
	bool sorted = check(x, y, z, order);
	int temp;
	while (!sorted) {
		int index = rand() % 3;
		
		switch (index){
		case 0: 
			temp = x;
			x = y;
			y = temp;
			break;
		case 1: 
			temp = x;
			x = z;
			z = temp;
			break;
		case 2: 
			temp = z;
			z = y;
			y = temp;
			break;
		}
		sorted = check(x, y, z, order);
	}
}

/*  Вывод на экран  */
/*  Массив  */
void print(int* a, int n) {
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl << endl;
}

/*  Вектор  */
void print(vector<int> a) {
	for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
	cout << endl << endl;
}

/*  3 числа  */
void print(int a, int b, int c) {
	cout << a << " " << b << " " << c << endl << endl;
}

int main() {
	setlocale(LC_ALL, "russian");
	srand(time(0));
	int n;
	cin >> n;
	int* a = new int[n];

	for (int i = 0; i < n; i++) cin >> a[i];

	vector<int> b; 
	for (int i = 0; i < n; i++) {
		b.push_back(a[i]);
	}

	int x = b[0], y = b[1], z = b[2];

	cout << endl;
	cout <<"Массив: "<< endl;
	BozoSort(a, n, ASC);
	print(a, n);
	BozoSort(a, n, DESC);
	print(a, n);

	cout << "Вектор: " << endl;
	BozoSort(b, ASC);
	print(b);
	BozoSort(b, DESC);
	print(b);

	cout << "3 отдельных числа: " << endl;
	BozoSort(x, y, z, ASC);
	print(x, y, z);
	BozoSort(x, y, z, DESC);
	print(x, y, z);

	return 0;
}
