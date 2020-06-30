#include <iostream>
#include "complex0.h" // to avoid confusion with complex.h
using namespace std;

int main()
{
    complex a(3.0, 4.0); // initialize to (3,4i)
    complex C;
    cout << "Enter a complex number (q to quit) :\n";
    while (cin >> C)
    {
        cout << "C is " << C << '\n';
        cout << "complex conjugate is " << ~C << '\n';
        cout << "a is " << a << '\n';
        cout << "a + C is " << a + C << '\n';
        cout << "a - C is " << a - C << '\n';
        cout << "a * C is " << a * C << "\n";
        cout << "2 * c is " << 2 * C << '\n';
        cout << "Enter a complex number (qito quit) :\n";
    }
    cout << "Done! \n";
    return 0;
}