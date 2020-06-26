#include "golf.h"
#include <iostream>
#include <string>

void setgolf(golf& g, const char* name, int hc)
{
    strcpy(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf& g)
{
    if (std::cin.get(g.fullname,Len))
    {
		while ((std::cin.get()) != '\n');
        (std::cin >> g.handicap).get();
        return 1;
    }
	g.handicap = 0;
	std::cin.clear();
    while ((std::cin.get()) != '\n');
    return 0;
}


void handicap(golf& g, int hc)
{
    g.handicap = hc;
}
// function displays contents of golf structure
void showgolf(const golf& g)
{
    std::cout << "=========================\n""fullname: " << g.fullname
        << "\nhandicap: " << g.handicap << std::endl << "=========================\n";
}