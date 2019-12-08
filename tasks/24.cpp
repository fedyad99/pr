#include <iostream>
using namespace std;

size_t strlen_(const char* string) {
	size_t size = 0;
	for(size; string[size] != '\0'; size++);
	return size;
}

int min(int a, int b) { return a < b ? a : b; }

int strcmp_(const char* string1, const char* string2) {
	int sizeMin = min(strlen_(string1), strlen_(string2));
	for (int i = 0; i < sizeMin+1; i++) {
		if (string1[i] != string2[i]) return (int)string1[i] > (int)string2[i] ? 1 : -1;
	}
	return 0;
}

char* strstr_(char* string1, const char* string2){
	int l1 = strlen(string1), l2 = strlen(string2);
	int temp;
	for (int i = 0; i < l1; i++) {
		if (string1[i] == string2[0]) {
			temp = i + 1;
			int j;
			for (j = 1; j < l2; j++) {
				if (string1[temp] != string2[j]) break;
				temp++;
			}
			if (j == l2) return &string1[i];
		}
	}
}



char* strcat_(char* destptr, const char* srcptr){
	int l1 = strlen_(destptr);
	
	for (int i = l1; i <= strlen_(srcptr) + l1; i++)
		destptr[i] = srcptr[i - l1];
	return destptr;
}

int main(){
	setlocale(LC_ALL, "Russian");
	char line1[100], line2[51];
	cin.getline(line1, 50);
	cin.getline(line2, 50);

	cout << strlen_(line1) << " " << strlen_(line2) << endl;

	if (strcmp_(line1, line2) == 0) cout << "Строки равны" << endl;
	else if (strcmp_(line1, line2) > 0) cout << "Строка 1 больше строки 2" << endl;
	else cout << "Строка 2 больше строки 1" << endl;

	for (int i = 0; i < strlen_(line1); i++) {
		if (&*strstr_(line1, line2) == &line1[i]) {
			cout << i << endl;
			break;
		}
		if(i == strlen_(line1)-1)cout << "-1" << endl;
	} 

	cout << strcat_(line1, line2);
	return 0;
}
