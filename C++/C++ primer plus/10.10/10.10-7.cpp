#include <iostream>
using namespace std;

class Plorg {
private:
    char name[20];
    int ci;
public:
    Plorg(const char* str = "Plorga");
    void show() const;
    void change(int num);
};

Plorg::Plorg(const char* str) {
    strcpy(name, str);
    ci = 50;
}
void Plorg::show() const
{
    cout << "Name: " << name << "    CI: " << ci << endl;
}
void Plorg::change(int num)
{
    ci = num;
}
int main()
{
    Plorg test0;
    test0.show();
    Plorg test1("abc");
    test1.show();
    test1.change(999);
    test1.show();
    return 0;

}