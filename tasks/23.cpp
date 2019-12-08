#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;

bool poll(char line[]) {
	vector<char> l;
	int leng = strlen(line);
	for (int i = 0; i < leng; i++) {
		if (isdigit(line[i])) l.push_back(line[i]);
		else if (isalpha(line[i])) l.push_back(tolower(line[i]));
	}

	if (l.size() == 0) return false;
	for (int i = 0; i < l.size() / 2; i++) if (l[i] != l[l.size() - 1 - i]) return false;
	return true;
}

int main(){
	setlocale(LC_ALL, "Russian");
	char line[21];
	cin.getline(line,21);

	if (poll(line)) cout << "Палиндром"<< endl; else cout << "Не палиндром" << endl;
	return 0;
}