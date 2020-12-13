#include <iostream>

using namespace std;

typedef int ListType;

class List {
    static const int ListSize = 3;
    ListType list[ListSize];
    int top;
public:
    List();
    bool isempty() const;
    bool isfull() const;
    void visit(void (*pf)(ListType));
    bool addlist(const ListType& value);
    void showlist() const;
};
List::List()
{
    top = 0;
}
bool List::isempty() const
{
    return !top;
}
bool List::isfull() const
{
    return top == ListSize;
}
bool List::addlist(const ListType& value)
{
    if (top >= ListSize)
        return 0;
    list[top++] = value;
    return 1;
}
void List::visit(void (*pf)(ListType))
{
    for (int i = 0; i < top; i++)
        pf(list[i]);
}
void List::showlist() const
{
    for (int i = 0; i < top; i++)
        cout << "#" << i + 1 << ": " << list[i] << endl;
}
void addone(ListType& value)
{
    ++value;
}


int main()
{
    List player;
    player.isempty();
    player.addlist(20);
    player.showlist();
    player.isempty();
    player.addlist(30);
    player.showlist();
    return 0;
}