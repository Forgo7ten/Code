#include <iostream>
using namespace std;

long long func(int n);

int main()
{
    int num;
    while (cin >> num && num >= 0)
        cout << num << "! is: " << func(num) << endl;
    cout << "Bye!\n";
    return 0;
}

long long func(int n)
{
    if (!n)
        return 1;
    else
        return n * func(n - 1);
}