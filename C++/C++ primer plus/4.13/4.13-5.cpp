#include <iostream>
#include <string>
using namespace std;
struct CandyBar {
    string brand;
    double weight;
    int calorie;
};
int main()
{
    struct CandyBar snack = {"Mocha Munch", 2.3, 350 };
    cout << snack.brand << " " << snack.weight << " " << snack.calorie << endl;
    return 0;
}