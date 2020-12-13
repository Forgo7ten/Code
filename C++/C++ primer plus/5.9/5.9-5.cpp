#include <iostream>

using namespace std;

int main()
{
    string moth[12] = {
        "1",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
        "10",
        "11",
        "12",
    };
    int num[12], sum = 0;
    for (int i = 0; i < 12; i++)
    {
        cout << moth[i] << " books: ";
        cin >> num[i];
        sum += num[i];
    }
    cout << "This year booknum is: " << sum << endl;
    return 0;
}