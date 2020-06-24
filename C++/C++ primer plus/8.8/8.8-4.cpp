#include <iostream>
#include <cstring>

using namespace std;

struct stringy {
    char* str;
    int ct;
};

void set(stringy& beany, const char* test);
void show(const stringy& beany, int num = 1);
void show(const char* test, int num = 1);
int main()
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";
    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");
    return 0;

}

void set(stringy& beany, const char* test)
{
    beany.ct = strlen(test);
    beany.str = new char [beany.ct];
    strcpy(beany.str, test);
}
void show(const stringy& beany, int num)
{
    while (num--)
        cout << beany.str << endl;
}
void show(const char* test, int num)
{
    while (num--)
        cout << test << endl;
}