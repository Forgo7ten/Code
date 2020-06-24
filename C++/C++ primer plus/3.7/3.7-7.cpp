#include <iostream>
using namespace std;

int main()
{
    const double mile = 62.14, rate = 3.875;
    double mpg, gallon, result;
    cout << "Input mpg: ";
    cin >> mpg;
    gallon = mpg / rate;
    result = mile / gallon;
    cout << "result: " << result;
    return 0;
}