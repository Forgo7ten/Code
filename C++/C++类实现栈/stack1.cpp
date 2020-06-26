#include <iostream>
#include "stack0.h"

using std::cout;
using std::endl;

Stack::Stack(int Size)
{
    space = new SKtype[Size];
    top = 0;
    size = Size;
}
Stack::~Stack()
{
    delete[] space;
    cout << "~Stack!\n";
}
bool Stack::isempty() const
{
    return !top;
}
bool Stack::isfull() const
{
    return top >= size;
}
bool Stack::push(const SKtype& value)
{
    if (!isfull())
    {
        space[top++] = value;
        return 1;
    }
    else
        return 0;
}
bool Stack::pop(SKtype& value)
{
    if (!isempty())
        value = space[--top];
    else
        return 0;
    return 1;
}
void Stack::show() const
{
    int i, j;
    cout.setf(std::ios::left); //×ó¶ÔÆë
    if (!isempty())
    {
        for (i = 0; i < top; i++)
        {
            if (!i)
                cout << "********************" << endl;
            cout << "**  ";
            cout.width(12);
            cout << space[i];
            cout << "  **\n";
            cout << "********************" << endl;
        }
    }
    else
        cout << "The stack is empty!" << endl;
    cout.setf(std::ios::right); //»Ö¸´ÓÒ¶ÔÆë
}