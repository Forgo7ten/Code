#include "sales.h"
#include <iostream>

namespace SALES
{
    void Sales::setSales(const double ar[], int n)
    {
        int i;
        double sum = 0;
        for (i = 0; i < QUARTERS && i < n; ++i)
            sales[i] = ar[i];
        for (; i < QUARTERS; ++i)
            sales[i] = 0;
        for (i = 0,max=sales[0],min=sales[0]; i < QUARTERS; ++i)
        {
            max = max > sales[i] ? max : sales[i];
            min = min < sales[i] ? min : sales[i];
            sum += sales[i];
        }
        average = sum / QUARTERS;
    }
    void Sales::setSales()
    {
        using namespace std;
        int i;
        double sum = 0;
        for (i = 0; i < QUARTERS; ++i)
        {
            cin >> sales[i];
            if (0 == i)
                max = sales[0], min = sales[0];
            sum += sales[i];
            max = max > sales[i] ? max : sales[i];
            min = min < sales[i] ? min : sales[i];
        }
        average = sum / QUARTERS;
    }
    void Sales::showSales() const
    {
        using namespace std;
        cout << "Sales: ";
        for (int i = 0; i < QUARTERS; ++i)
            cout << sales[i] << ' ';
        cout << "\nmax: " << max << "\tmin: " << min;
        cout << "\tavarage: " << average << endl;
    }
}