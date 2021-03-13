#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{    float x0;
     double power;
     double coeff;
     float b;
     cin >> x0 >> power >> coeff;
     b = coeff;
     for (int i=power-1; i>=0; i--)
     {
         cin >> coeff;
         b = coeff + b*x0;

     }

    cout << fixed <<  setprecision(6) << b << endl;
}
