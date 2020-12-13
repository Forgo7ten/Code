#include <iostream>

using namespace std;
const int strsize = 40;
const int num = 5;

struct bop {
    char fullname[strsize];
    char title[strsize];
    char bopname[strsize];
    int preference;
};
bop player[num] = {
    {"name1","job1","bop1",0},
    {"name2","job2","bop2",1},
    {"name3","job3","bop3",2},
    {"name4","job4","bop4",1},
    {"name5","job5","bop5",2}
};
void menu(void)
{
    cout << "a. display by name\tb. display by title\n"
        << "c. display by bopname\td. display by preference\n"
        << "q. quit\n";
}
void funa(void)
{
    for (int i = 0; i < num; i++)
        cout << player[i].fullname << endl;
}
void funb(void)
{
    for (int i = 0; i < num; i++)
        cout << player[i].title << endl;
}
void func(void)
{
    for (int i = 0; i < num; i++)
        cout << player[i].bopname << endl;
}
void fund(void)
{
    for (int i = 0; i < num; i++)
    {
        switch (player[i].preference)
        {
        case 0:
            cout << player[i].fullname << endl;
            break;
        case 1:
            cout << player[i].title << endl;
            break;
        case 2:
            cout << player[i].bopname << endl;
            break;
        }
    }
}

int main()
{
    char ch;
    menu();
    cout << "Enter your choice: ";
    cin >> ch;
    while (ch != 'q')
    {
        switch (ch)
        {
        case 'a':
            funa();
            break;
        case 'b':
            funb();
            break;
        case 'c':
            func();
            break;
        case 'd':
            fund();
            break;
        default:
            cout << "Input error! Please enter again!\n";
            cin >> ch;
            continue;
        }
        cout << "Next choice: ";
        cin >> ch;
    }
    cout << "Bye!\n";
    return 0;
}