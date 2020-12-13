#include <iostream>
#include "golf.h"


int main()
{
    const int GolfSize = 5;
    Golf arr[GolfSize];
    int n = 0, i;
    while (n < GolfSize && arr[n].setgolf())
        n++;
    for (i = 0; i < n; i++)
        arr[i].showgolf();
    arr[0].setgolf("myset", 24);
    arr[0].showgolf();
    arr[0].Handicap(99);
    arr[0].showgolf();
    std::cout << "=====================\n";
    Golf* p = new Golf;
    p->setgolf();
    p->showgolf();
    p->Handicap(999);
    p->showgolf();
    return 0;
}