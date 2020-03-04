#include <iostream>

double Step(double a, double b)
{
	if (b < 2) return a;
	return Step(a, b - 1)*a;
}

int main()
{
	double a, b;

	std::cin >> a >> b;
	std::cout << Step(a, b);
}
