#include <iostream>

using namespace std;
typedef double hs(double, double);

double add(double, double);
double sub(double, double);
double mul(double, double);
double calculate(double, double, hs);

int main()
{
    double m, n;
    hs* pf[3] = {
        &add,
        &sub,
        &mul
    };
    while (cin >> m >> n)
    {
        for (int i = 0; i < 3; ++i)
        {
            double temp;
            temp = calculate(m, n, pf[i]);
            cout << i + 1 << " :  " << temp << endl;
        }
    }
    cout << "Bye!\n";
    return 0;
}

double add(double x, double y)
{
    return x + y;
}
double sub(double x, double y)
{
    return x - y;
}
double mul(double x, double y)
{
    return x * y;
}
double calculate(double x, double y, hs* p)
{
    return p(x, y);
}