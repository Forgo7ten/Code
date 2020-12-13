#include <iostream>
using namespace std;
#define MAXSIZE 10
int input(int* p);
void show(int* p,int len);
double average(int* p, int len);
int main()
{
    int arr[10];
    int len = input(arr);
    double ava;
    show(arr, len);
    ava = average(arr, len);
    cout << "average: " << ava << endl;
    return 0;
}

int input(int* p)
{
    int score, i = 0;
    while (i < MAXSIZE && cin>>score && score >= 0 )
    {
        p[i++] = score;
    }
    return i;
}
void show(int* p, int len)
{
    int i;
    cout << "Here are your input: ";
    for (i = 0; i < len; i++)
        if (i == len - 1)
            cout << p[i] << endl;
        else
            cout << p[i] << ' ';
}
double average(int* p, int len)
{
    double avarage, sum=0;
    for (int i = 0; i < len; i++)
        sum += p[i];
    avarage = sum / len;
    return avarage;
}