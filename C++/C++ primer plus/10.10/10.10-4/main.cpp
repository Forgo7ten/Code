#include <iostream>
#include "sales.h"

int main()
{
    using namespace SALES;
    Sales test[4];
    test[0].setSales();
    test[0].showSales();
    const double arr[QUARTERS] = { 1.11,2.22,3.33,4.44 };
    test[1].setSales(arr, 3);
    test[1].showSales();
    test[2].setSales(arr, 5);
    test[2].showSales();
    test[3].setSales(arr, 4);
    test[3].showSales();
    return 0;
}