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
    struct CandyBar snack[3] = {
    {"Mocha Munch", 2.3, 350 },
    {"Mocha", 3.4, 460},
    {"Munch", 4.5, 570}
    };
    cout << snack[0].brand << "\t" << snack[0].weight << " " << snack[0].calorie << endl;
    cout << snack[1].brand << "\t" << snack[1].weight << " " << snack[1].calorie << endl;
    cout << snack[2].brand << "\t" << snack[2].weight << " " << snack[2].calorie << endl;
    return 0;
}