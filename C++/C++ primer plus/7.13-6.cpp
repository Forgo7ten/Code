#include <iostream>

#define ARRLEN 10
using namespace std;

int Fill_array(double*, int len);
void Show_array(double*, int len);
void Reverse_array(double*, int len);

int main()
{
    double arr[ARRLEN];
    int len;
    len = Fill_array(arr, ARRLEN);
    Show_array(arr, len);
    Reverse_array(arr, len);
    Show_array(arr, len);
    return 0;
}

int Fill_array(double* p, int len)
{
    cout << "Please input double values:\n";
    int n = 0;
    for (n = 0; n<len && cin >> p[n]; n++);
    return n;
}
void Show_array(double* p, int len)
{
    cout << "Here are array's value: ";
    for (int i = 0; i < len; i++)
        if (len - 1 == i)
            cout << p[i] << endl;
        else
            cout << p[i] << " ";
}
void Reverse_array(double*p, int len)
{
    int i, j;
    double temp;
    for (i = 1, j = len - 2; i < j; ++i, --j)
    {
        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
    }
}