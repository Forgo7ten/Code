#include <iostream>
using namespace std;

int main()
{
    char name[20], last[20];
    cout << "Enter your first name: ";
    cin.getline(name, 20);
    cout << "Enter your last name: ";
    cin.getline(last, 20);
    cout << "Here's the information in a single string: " << last << ", " << name;
    return 0;
}