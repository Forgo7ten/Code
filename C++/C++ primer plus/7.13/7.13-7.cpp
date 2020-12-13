#include <iostream>

using namespace std;
const int Max = 5;
double* fill_array(double ar[], double* final);
void show_array(const double ar[], double* final);
void revalue(double r, double ar[], double* final);

int main()
{
    double properties[Max];
    double* finp;
    finp = fill_array(properties, properties + Max - 1);
    show_array(properties, finp);
    if (finp - properties > 0)
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor))
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Bad input! Please enter a number: ";
        }
        revalue(factor, properties, finp);
        show_array(properties, finp);
    }
    cout << "Done.\n";
    //cin.get();
    //cin.get();
    return 0;
}

double* fill_array(double ar[], double* final)
{
    double temp;
    double* p;
    for (p = ar; p <= final; p++)
    {
        cout << "Enter value #" << p - ar + 1 << ": ";
        cin >> temp;
        if (!cin)
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Bad input; input process terminated.\n";
            break;
        }
        else if (temp < 0)
            break;
        *p = temp;
    }
    return p - 1;
}
void show_array(const double ar[], double* final)
{
    for (const double* p = ar; p <= final; ++p)
    {
        cout << "Property #" << p - ar + 1 << ": $"
            << *p << endl;
    }

}
void revalue(double r, double ar[], double* final)
{
    for (double* p = ar; p <= final; ++p)
        *p *= r;
}