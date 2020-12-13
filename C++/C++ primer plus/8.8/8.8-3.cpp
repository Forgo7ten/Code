#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void func(string& str);

int main()
{
    string str;
    cout << "Enter a string (q to quit): ";
    while (getline(cin, str) && !(str.length() == 1 && str[0] == 'q'))
    {
        func(str);
        cout << str << endl;
        cout << "Next string (q to quit): ";
    }
    cout << "Bye.\n";
    return 0;
}

void func(string& str)
{
    for (int i = 0; i < str.length(); ++i)
        str[i] = toupper(str[i]);
}