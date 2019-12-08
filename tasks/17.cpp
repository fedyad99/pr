#include <iostream>
using namespace std;

double BMI(double weight, double height) {
	return weight / (height * height);
}

void printBMI(double BMI) {
	if (BMI < 18.5) cout << "Underweight";
	else if (BMI < 25) cout << "Normal";
	else if (BMI < 30) cout << "Overweight";
	else cout << "Obesity";
}

int main(){
	double w, h;
	cin >> w >> h;
	printBMI(BMI(w, h / 100));
	return 0;
}