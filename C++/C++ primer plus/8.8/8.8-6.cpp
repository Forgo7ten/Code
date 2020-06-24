#include <iostream>

using namespace std;

template <typename T>
T maxn(T* p, int n) {
    T max;
    max = p[0];
    for (int i = 1; i < n; i++)
        max = max > p[i] ? max : p[i];
    return max;
}
template <> char* maxn<char *>(char** p, int n)
{
    char* max = p[0];
    int maxlen = strlen(max);
    int  i = 0;
    int ilen;
    while (++i < n)
    {
        ilen = strlen(p[i]);
        if (maxlen < ilen)
        {
            max = p[i];
            maxlen = ilen;
        }
    }
    return max;
}


int main()
{
    int arr[5] = { 1,3,9,5,7 };
    double brr[5] = { 2.2,4.4,9.9,6.6,1.1 };
    int m = maxn(arr,6);
    double n = maxn(brr,4);
    cout << "m = " << m << endl;
    cout << "n = " << n << endl;
    char* str[5] = {
        new char[10],
        new char[10],
        new char[10],
        new char[10],
        new char[10]
    };
    strcpy(str[0], "abcd");
    strcpy(str[1], "abcdeff");
    strcpy(str[2], "abcdfes");
    strcpy(str[3], "abcde");
    strcpy(str[4], "abc");
    cout << maxn<char *>((char **)str, 5);
    return 0;
}