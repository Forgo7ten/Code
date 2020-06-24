#include <iostream>

using namespace std;

template <typename T>
T max5(T* p)
{
    T max;
    max = p[0];
    for (int i = 1; i < 5; i++)
        max = max > p[i] ? max : p[i];
    return max;
}

int main()
{
    int arr[5] = { 1,3,9,5,7 };
    double brr[5] = { 2.2,4.4,9.9,6.6,1.1 };
    int m = max5(arr);
    double n = max5(brr);
    cout << "m = " << m << endl;
    cout << "n = " << n << endl;
    return 0;
}
