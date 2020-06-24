#include <iostream>
#include <string>
using namespace std;

struct car {
    string brand;
    int years;
};

int main()
{
    int num;
    cout << "How many cars do you wish to catalog? ";
    cin >> num;
    car* cp = new car[num];
    cin.get();
    for (int i = 0; i < num; i++)
    {
        cout << "Car #" << i + 1 << ":\nPlease enter the make: ";
        getline(cin, cp[i].brand);
        cout << "Please enter the year made: ";
        cin >> cp[i].years;
        cin.get();
    }
    cout << "Here is your collection:\n";
    for (int i = 0; i < num; i++)
        cout << cp[i].years << " " << cp[i].brand << endl;
    delete[] cp;
    return 0;
}