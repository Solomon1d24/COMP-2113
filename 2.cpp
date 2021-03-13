#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a,b, Divisor1, Divisor2;
    cout << "a: " << "b: " << "Divisor 1: " << "Divisor 2: ";  
    cin >> a >> b >> Divisor1 >> Divisor2;
    cout << "M " << Divisor1 << " " << Divisor2 << "\n";
    for (int i=a; i< b ; i++)
    {   cout << i << " ";
        if (i%Divisor1 == 0)
            {cout << 1 << " ";}
        else
            {cout << 0 << " ";}
        if (i%Divisor2 == 0)
            {cout << 1 << "\n";}
        else
            {cout << 0 << "\n";}
    }


}