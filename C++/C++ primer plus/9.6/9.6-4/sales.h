#pragma once
#ifndef _Sales

#define _Sales

namespace SALES
{
    const int QUARTERS = 4;
    struct Sales {

        double sales[QUARTERS];
        double average;
        double max;
        double min;
    };
    // copies the lesser of 4 or n items from the array ar
    // to the sales member of s and computes and stores the
    // average, maximum, and minimum values of the entered items;
    // remaining eFements of sales, if any, set to 0
    void setSales(Sales& S, const double ar[], int n);
    // gathers sales for 4 quarters interactively, stores them
    // in the sales member of s and computes and stores the
    // average, maximum£¬ and minimum values
    void setSales(Sales& s);
    // display all information in structure s
    void showSales(const Sales& s);
}
#endif // !_Sales
