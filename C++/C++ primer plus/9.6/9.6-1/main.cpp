#include <iostream>
#include "golf.h"


int main()
{
    const int GolfSize = 5;
    golf arr[GolfSize];
    int n = 0, i;
    while (n < GolfSize && setgolf(arr[n]))
        n++;
    for (i = 0; i < n; i++)
        showgolf(arr[i]);
    setgolf(arr[0], "myset", 24);
    showgolf(arr[0]);
    handicap(arr[0], 99);
    showgolf(arr[0]);
    return 0;
}