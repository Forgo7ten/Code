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
    CandyBar* p = new CandyBar[3];
    p[0] = { "Mocha Munch", 2.3, 350 };
    p[1] = { "Mocha", 3.4, 460 };
    p[2] = { "Munch", 4.5, 570 };
    cout << p[0].brand << "\t" << p[0].weight << " " << p[0].calorie << endl;
    cout << p[1].brand << "\t" << p[1].weight << " " << p[1].calorie << endl;
    cout << p[2].brand << "\t" << p[2].weight << " " << p[2].calorie << endl;
    return 0;
}