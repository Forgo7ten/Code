#include <iostream>

using namespace std;

int main()
{
    int num, sum = 0;
    cin >> num;
    while (num)
    {
        sum += num;
        cout << "sum = " << sum << endl;
        cin >> num;
    }
    return 0;
}