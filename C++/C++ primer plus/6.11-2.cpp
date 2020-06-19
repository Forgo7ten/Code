#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    double don[10], avarage;
    int i, n, num = 0;
    n = 0;
    while (n < 10 && cin >> don[n])
        n++;
    avarage = 0;
    for (i = 0; i < n; i++)
        avarage += don[i];
    avarage /= n;
    cout << "avarage: " << avarage;
    for (i = 0; i < n; i++)
        if (don[i] > avarage)
            num++;
    cout << "\nHave: " << num << " bigger than avarage\n";
    return 0;
}