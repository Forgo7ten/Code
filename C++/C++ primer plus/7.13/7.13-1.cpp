#include <iostream>
using namespace std;
double func(double, double);
int main()
{
    double m, n, result;
    cin >> m >> n;
    while (m != 0 && n != 0)
    {
        result = func(m, n);
        cout << result << endl;
        cin >> m >> n;
    }
    return 0;
}
double func(double x, double y)
{
    return 2.0 * x * y / (x + y);
}