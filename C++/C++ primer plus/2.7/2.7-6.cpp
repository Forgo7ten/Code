#include <iostream>
using namespace std;

double func(double);

int main()
{
    double year, unit;
    cout << "Enter the number of light years: ";
    cin >> year;
    unit = func(year);
    cout << year << " light years = "
        << unit << " astronomical units." << endl;
    return 0;
}

double func(double years)
{
    double units;
    units = years * 63240;
    return units;
}