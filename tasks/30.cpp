#include <iostream>
#include <cstring>
using namespace std;

char* strtok_1(char* string, const char* delim) {
	static char* last = 0;
	if (string) last = string;
	if ((last == NULL) || (*last == NULL)) return nullptr;

	char* temp = last;
	while (strchr(delim, *temp)) ++temp; //Поиск вхождения элементов разделителя
	if (*temp == 0) return nullptr; 
	char* start = temp; 
	while (*temp && (strchr(delim, *temp) == 0)) ++temp;
	if (*temp == 0){
		last = temp;
		return start;
	}
	*temp = 0;
	last = temp + 1;
	return start;
}

int main() {
	char string[100], delim[50];
	cin.getline(string, 100);
	cin.getline(delim, 50);

	char* ptr = strtok_1(string, delim); 
	int count = 0;
	
	while (ptr != nullptr) {
		cout << ptr << endl;
		count++;
		ptr = strtok_1(NULL, delim);
	}
	cout << "Words: " << count << endl;
	
	return 0;
}
