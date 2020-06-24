#include <iostream>
using namespace std;

int main()
{
    long long world, us;
    double rate;
    cout << "Enter the world's population: ";
    cin >> world;
    cout << "Enter the population of the US: ";
    cin >> us;
    rate = 100.0 * us / world;
    cout << "The population of the US is "
        << rate << "% of the world population.";
    return 0;
}