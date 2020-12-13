#include <iostream>
#include <string>
using namespace std;
struct Pizza {
    char name[30];
    double diameter;
    double weight;
};
int main()
{
    Pizza* p = new Pizza;
    cin >> p->diameter;
    cin.get();
    cin.getline(p->name, 30);
    cin >> p->weight;
    cout << "name: " << p->name << "\ndiameter: " << p->diameter << "\nweight: " << p->weight;
    delete p;
    return 0;
}