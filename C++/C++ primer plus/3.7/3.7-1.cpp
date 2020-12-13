#include <iostream>
using namespace std;

int main()
{
    const int constant = 12;
    int incha, inchb, foot;
    cout << "inch: ___\b\b\b";
    cin >> incha;
    foot = incha / constant;
    inchb = incha % constant;
    cout << "Has " << foot
        << " foot and " << inchb << " inch\n";
    return 0;
}