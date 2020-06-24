#include <iostream>

using namespace std;

struct CandyBar {
    char brand[30];
    double weight;
    int calorie;
};

void func(CandyBar& cb, const char* brand = "Millennium Munch", const double weight = 2.85, const int calorie = 350);
void show(const CandyBar& p);
int main()
{
    CandyBar one, two, three, four;
    func(one);
    func(two, "two");
    func(three, "three", 2.95);
    func(four, "four", 3.11, 500);
    show(one);
    cout << "========================================\n";
    show(two);
    cout << "========================================\n";
    show(three);
    cout << "========================================\n";
    show(four);
    return 0;
}


void func(CandyBar& cb, const char* brand, const double weight, const int calorie)
{
    strcpy(cb.brand, brand);
    cb.weight = weight;
    cb.calorie = calorie;
}
void show(const CandyBar& p)
{
    cout << "Brand: " << p.brand
        << "\nWeight: " << p.weight
        << "\nCalorie: " << p.calorie << endl;
}