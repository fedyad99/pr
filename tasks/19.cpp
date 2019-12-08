#include <iostream>
using namespace std;


int main(){
	int mas[10] = { 0 };
	int n,temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp >= 0 && temp <= 9) mas[temp]++;
	}

	for (int i = 0; i < 10; i++)
		if (mas[i] > 0) cout << i << ": " << mas[i] << endl;

	return 0;
}
