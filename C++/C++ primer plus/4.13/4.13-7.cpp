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
    Pizza pizza;
    cin.getline(pizza.name, 30);
    cin >> pizza.diameter >> pizza.weight;
    cout << "name: " << pizza.name << "\ndiameter: " << pizza.diameter << "\nweight: " << pizza.weight;
    return 0;
}