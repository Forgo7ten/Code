#include <iostream>
using namespace std;

int main()
{
    int degree, minute, second;
    const double rate = 60;
    double degrees;
    cout << "Enter a latitude in degrees, minutes, and seconds:\nFirst, enter the degrees: ";
    cin >> degree;
    cout << "Next, enter the minutes of arc: ";
    cin >> minute;
    cout << "Finally, enter the seconds of arc: ";
    cin >> second;
    degrees = degree + minute / rate + second / (rate * rate);
    cout << degree << " degrees, "
        << minute << " minutes, "
        << second << " seconds = "
        << degrees << " degrees" << endl;
    return 0;
}