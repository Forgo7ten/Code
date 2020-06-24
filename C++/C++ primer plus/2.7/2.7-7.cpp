#include <iostream>
using namespace std;

void func(int, int);

int main()
{
    int hours, minutes;
    cout << "Enter the number of hours: ";
    cin >> hours;
    cout << "Enter the number of minutes: ";
    cin >> minutes;
    func(hours, minutes);
    return 0;
}

void func(int hours, int minutes)
{
    cout << "Time: " << hours << ":" << minutes << endl;
}