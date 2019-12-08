#include <iostream>
using namespace std;

int main()
{
    int a,b;
    double c,d;
    
    cout << "Введите 2 числа (int)"<<endl;
    cin >> a >> b;
    cout <<"Пара int-int:"<<endl;
    cout <<"a + b = " << a+b <<endl;
    cout <<"a * b = " << a*b <<endl;
    cout <<"a - b = " << a-b <<endl;
    cout <<"a / b = " << a/b <<endl;
    
    cout << "Введите 2 числа (double,double)"<<endl;
    cin >> c >> d;
    cout <<"Пара double-double:"<<endl;
    cout <<"c + d = " << c+d <<endl;
    cout <<"c * d = " << c*d <<endl;
    cout <<"c - d = " << c-d <<endl;
    cout <<"c / d = " << c/d <<endl;
    
    cout << "Введите 2 числа (int,double)"<<endl;
    cin >>a>>c;
    cout <<"Пара int-double:"<<endl;
    cout <<"a + c = " << a+c <<endl;
    cout <<"a * c = " << a*c <<endl;
    cout <<"a - c = " << a-c <<endl;
    cout <<"a / c = " << a/c <<endl;
    cout << "Введите 2 числа (double,int)"<<endl;
    cin >> c >> a;
    cout <<"Пара double-int:"<<endl;
    cout <<"c + a = " << c+a <<endl;
    cout <<"c * a = " << c*a <<endl;
    cout <<"c - a = " << c-a <<endl;
    cout <<"c / a = " << c/a <<endl;
    return 0;
}