#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

double factorial(double integer)
    { double fact = 1;
        for (int k=1; k<=integer ;k++)
        {fact = fact*k;}
        return fact;
    }

int main()
{
    double x;
    int i;
    double total = 0;
    cin >> x >> i;
    cout << "sin(x) by cmath: " <<fixed << setprecision(15) << sin(x) << endl;
    cout << "Taylor series approximation:" << "\n";

    for (int j=0; j<=i; j++)
    { double nn = pow(-1.0,j);
      double fact = factorial(2*j+1);
      double temp = nn/fact;
      double temp2 = pow(x,2.0*j+1.0);
      total += temp*temp2;
      cout << j << " " << fixed << setprecision(15) << total << endl;
    }




}