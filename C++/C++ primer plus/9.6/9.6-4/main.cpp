#include <iostream>
#include "sales.h"

int main()
{
    SALES::Sales test[4];
    SALES::setSales(test[0]);
    SALES::showSales(test[0]);
    const double arr[SALES::QUARTERS] = { 1.11,2.22,3.33,4.44 };
    SALES::setSales(test[1], arr, 3);
    SALES::showSales(test[1]);
    SALES::setSales(test[2], arr, 5);
    SALES::showSales(test[2]);
    SALES::setSales(test[3], arr, 4);
    SALES::showSales(test[3]);
    return 0;
}