#include <iostream>

using namespace std;

void func(const char* p);
void func(const char* p, int num);

int main()
{
    char str[20] = "Yes,you success!";
    func(str);
    cout << "================================\n";
    func(str, 5);
	return 0;
}

void func(const char* p)
{
    cout << p << endl;
}
void func(const char* p, int num)
{
    cout << p << endl;
    if (1 != num)
        func(p, num - 1);
}