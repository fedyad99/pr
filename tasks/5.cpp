#include <iostream>
using namespace std;

const double g = 9.8;

int main()
{
   double x, x0, v0, t;
   cout << "Введите x0, v0, t"<<endl;
   cin >> x0 >> v0 >> t;
   x = x0 + v0 * t + g * t * t / 2;
   cout<<x<<" м";
   return 0;
}