#include <iostream>
using namespace std;

struct IntArray {
	int* data;
	int size;
};

void create(IntArray* arr, int size) {
	arr->data = new int[size];
	arr->size = size;
}

int get(IntArray* arr, int index) {
	if (index >= arr->size || index < 0) return -999999;
	return arr->data[index];
}

void set(IntArray* arr, int index, int value) {
	if (index >= arr->size || index < 0) return;
	arr->data[index] = value;
}

void print(IntArray* arr) {
	cout << '[';
	for (int i = 0; i < arr->size - 1; i++) cout << get(arr,i) << ", ";
	cout << get(arr,arr->size-1) << "]" << endl;
}

int min(int a, int b) { return a < b ? a : b; }

void resize(IntArray* arr, int newSize) {
	IntArray temp = *arr;
	arr->data = nullptr;
	arr->data = new int[newSize] {0};
	arr->size = newSize;
	for (int i = 0; i < min(temp.size, newSize); i++) arr->data[i] = temp.data[i];
}

void free(IntArray* arr) {
	if (arr->data != nullptr) {
		arr->data = nullptr;
		arr->size = 0;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	IntArray arr;

	create(&arr, 30);
	for (int i = 0; i < 30; i++) set(&arr,i,i+1);
	print(&arr);
	resize(&arr, 50);
	print(&arr);
	resize(&arr, 10);
	print(&arr);
	free(&arr);
	return 0;
}
