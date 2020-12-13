#include "golf.h"
#include <iostream>
#include <string>

void Golf::setgolf(const char* name, int hc)
{
    strcpy(fullname, name);
    handicap = hc;
}

int Golf::setgolf()
{
    if (std::cin.get(fullname,Len))
    {
        while ((std::cin.get()) != '\n');
        (std::cin >> handicap).get();
        return 1;
    }
    handicap = 0;
    std::cin.clear();
    while ((std::cin.get()) != '\n');
    return 0;
}


void Golf::Handicap(int hc)
{
    handicap = hc;
}
// function displays contents of golf structure
void Golf::showgolf()const
{
    std::cout << "=========================\n""fullname: " << fullname
        << "\nhandicap: " << handicap << std::endl << "=========================\n";
}