#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    cout << "Введите 2 числа" << endl;
    cin >> a >>b;
    c = a;
    a = b;
    b = c;
    cout << a << " " << b;
    
    cout << "Введите 2 числа" << endl;
    cin >> a >> b;
	  a = a + b;
    b = a - b;
  	a = a - b;
    cout << a << " " << b;
    
    return 0;
}
