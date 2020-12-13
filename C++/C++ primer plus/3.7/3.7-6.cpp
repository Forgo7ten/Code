#include <iostream>
using namespace std;

int main()
{
    int mile, gallon;
    double rate;
    cout << "Input mile: ";
    cin >> mile;
    cout << "Input gallon: ";
    cin >> gallon;
    rate = (double)mile / gallon;
    cout << "rate: " << rate;
    return 0;
}