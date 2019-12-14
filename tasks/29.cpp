#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Russian");
	for (int i = 0; i < argc; i++) {
		if (!strcmp("-help", argv[i])) {
			cout << "Команды: -n, -b, -w" << endl;
			return 0;
		}
	}

	bool n = false;
	char* name = nullptr;
	bool b = false;
	bool w = false;
	char* name2 = nullptr;

	for (int i = 0; i < argc; i++) {
		if (!strcmp("-n", argv[i])) {
			if (i != argc - 1) {
				n = true;
				name = argv[++i];
			}
			else {
				cout << "Недопустимый параметр" << endl;
				return 0;
			}
		}
		else if (!strcmp("-b", argv[i])) {
			b = true;
		}
		else if (!strcmp("-w", argv[i])) {
			if (i != argc - 1) {
				w = true;
				name2 = argv[++i];
			}
		}
	}
	if (n || w) {
		if(b) cout<<"Пока, "<< (w ? name2 : name) << endl;
		else cout<< "Привет, " << (w ? name2 : name) << endl;
	}

	return 0;
}
