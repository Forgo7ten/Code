#include <iostream>
using namespace std;
double func(double);
int main()
{
    double celsius, fahrenheit;
    cout << "Please enter a Celsius value: ";
    cin >> celsius;
    fahrenheit = func(celsius);
    cout << celsius << " degrees Celsius is "
        << fahrenheit << " degrees Fahrenheit" << endl;
    return 0;
}
double func(double n)
{
    double m;
    m = 1.8 * n + 32.0;
    return m;
}