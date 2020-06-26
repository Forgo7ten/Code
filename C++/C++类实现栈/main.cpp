#include <iostream>
#include "stack0.h"

using std::cin;
using std::cout;
using std::endl;

void menu()
{
    cout << "\nPlease choose a option. Input 'Q' to quit.\n";
    cout <<
        "A. PUSH a value.\t\t\t\tB. POP a value\n"
        "E. Check that the stack is empty.\t\tF. Check that the stack is full.\n"
        "S. Show the stack.\t\t\t\tM. SHOW the menu.\n";
}
int main()
{
    char ch;
    int size = SKSize;
    SKtype value;

    cout << "Enter the size of the stack: ";
    if (!(cin >> size))
    {
        cout << "Input error! Bye~~\n";
        return 0;
    }
    Stack object(size);
    cout << "A stack was successfully created.\n";
    menu();
    while (cin >> ch && ch != 'Q')
    {
        switch (ch)
        {
        case 'A':
        case 'a':
            if (object.isfull())
                cout << "PUSH failed! The stack is full.\n";
            else
            {
                cout << "Please input value: ";
                (cin >> value).get();
                object.push(value);
                cout << "You've successfully push the \"" << value << "\"\n";
            }

            break;
        case 'B':
        case 'b':
            if (object.pop(value))
                cout << "You've successfully pop the \"" << value << "\"\n";
            else
                cout << "POP failed! The stack is empty.\n";
            break;
        case 'E':
        case 'e':
            if (object.isempty())
                cout << "The stack is empty.\n";
            else
                cout << "The stack isn't empty.\n";
            break;
        case 'F':
        case 'f':
            if (object.isfull())
                cout << "The stack is full.\n";
            else
                cout << "The stack isn't full.\n";
            break;
        case 'S':
        case 's':
            object.show();
            break;
        case 'M':
        case 'm':
            menu();
            break;
        default:
            cout << "Input error! Please input again!\n";
            break;
        }
    }
    cout << "\nBye~~\n";
    return 0;
}