#include <iostream>

using namespace std;

int main()
{
    const double start = 100;
    const double Drate = 0.1, Crate = 0.05;
    double Dprofit, Cprofit = 0, Csum, Cspfit;
    Csum = start;
    int i = 0;
    do {
        i++;
        Dprofit = i * Drate * start;
        Cspfit = Crate * Csum;
        Csum += Cspfit;
        Cprofit += Cspfit;
    } while (Cprofit <= Dprofit);
    cout << "When " << i << " years\nDaphne: ";
    cout << Dprofit + start << endl << "Cleo: " << Cprofit + start << endl;
    return 0;
}