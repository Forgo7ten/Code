#include <iostream>
using namespace std;

long double probability(unsigned picks);
const int total = 47;
const int special = 27;
int main()
{
    double choices;
    cout << "Enter the total number of choices on the game card and\n"
        "the number of picks allowed;\n";
    while (cin >> choices && choices <= total)
    {
        cout << "You have one chance in "
            << probability(choices)
            << " of winning.\n"
            "Next one numbers (q to quit):";
    }
    cout << "Bye!\n";
    return 0;
}

long double probability(unsigned picks)
{
    int i = total;
    int j = picks;
    long double result = 1;
    for (; j > 0; i--, j--)
        result *= i / j;
    result *= special;
    return result;
}