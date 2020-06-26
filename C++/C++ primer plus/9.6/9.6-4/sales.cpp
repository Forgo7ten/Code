#include "sales.h"
#include <iostream>

namespace SALES
{
    void setSales(Sales& s, const double ar[], int n)
    {
        int i;
        double sum = 0;
        for (i = 0; i < QUARTERS && i < n; ++i)
            s.sales[i] = ar[i];
        for (; i < QUARTERS; ++i)
            s.sales[i] = 0;
        for (i = 0,s.max=s.sales[0],s.min=s.sales[0]; i < QUARTERS; ++i)
        {
            s.max = s.max > s.sales[i] ? s.max : s.sales[i];
            s.min = s.min < s.sales[i] ? s.min : s.sales[i];
            sum += s.sales[i];
        }
        s.average = sum / QUARTERS;
    }
    void setSales(Sales& s)
    {
        using namespace std;
        int i;
        double sum = 0;
        for (i = 0; i < QUARTERS; ++i)
        {
            cin >> s.sales[i];
            if (0 == i)
                s.max = s.sales[0], s.min = s.sales[0];
            sum += s.sales[i];
            s.max = s.max > s.sales[i] ? s.max : s.sales[i];
            s.min = s.min < s.sales[i] ? s.min : s.sales[i];
        }
        s.average = sum / QUARTERS;
    }
    void showSales(const Sales& s)
    {
        using namespace std;
        cout << "Sales: ";
        for (int i = 0; i < QUARTERS; ++i)
            cout << s.sales[i] << ' ';
        cout << "\nmax: " << s.max << "\tmin: " << s.min;
        cout << "\tavarage: " << s.average << endl;
    }
}