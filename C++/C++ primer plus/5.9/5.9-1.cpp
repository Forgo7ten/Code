#include <iostream>

using namespace std;

int main()
{
    int min, max, sum;
    cin >> min >> max;
    sum = 0;
    while (min <= max)
        sum += min++;
    cout << "sum = " << sum << endl;
    return 0;
}