#include <iostream>
using namespace std;

int main()
{
    const int rate = 12;
    const double rata = 0.0254;
    const double ratb = 2.2;
    int inch, foot, pound;
    double kg, m, bmi;
    cout << "Input foot: __\b\b";
    cin >> foot;
    cout << "Input inch: _\b";
    cin >> inch;
    m = rata * (foot * 12 + inch);
    cout << "Input pound: __\b\b";
    cin >> pound;
    kg = ratb * pound;
    bmi = kg / (m * m);
    cout << "BMI is " << bmi << endl;
    return 0;
}