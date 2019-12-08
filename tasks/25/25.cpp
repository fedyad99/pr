#include <fstream>
#include <iostream>
using namespace std;

struct Students {
	char name[101];
	int group;
	int sec[5];
};

void init(Students* stud){
	char a[101];
	ifstream fin("data.txt", ios::in);
	if (!fin) {
		cout << "Файл " << "data.txt" << " не найден." << endl;
		return;
	}
	for (int i = 0; i < 10; i++) {
		fin.getline(a, 100);
		stud[i].group = atoi(a);
		fin.getline(stud[i].name, 100);
		for (int j = 0; j < 5; j++) {
			fin.getline(a, 100);
			stud[i].sec[j] = atoi(a);
		}
	}
}

void check(Students stud) {
	for (int i = 0; i < 5; i++) {
		if (stud.sec[i] < 3) {
			cout << stud.name << " " << stud.group <<endl;
			break;
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	Students stud[10]; 

	init(stud);
	
	for (int i = 0; i < 10; i++) check(stud[i]);
	return 0;
}
