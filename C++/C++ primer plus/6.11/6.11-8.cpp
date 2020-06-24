#include <iostream>
#include <cctype>
#include <fstream>
using namespace std;

int main()
{
    ifstream infile;
    string filename;
    char ch;
    long double num = 0;
    cout << "Please input filename: ";
    cin >> filename;
    infile.open(filename);
    while (!infile.is_open())
    {
        cout << "file open failed.\n";
        cout << "Please input filename again: ";
        cin >> filename;
        infile.open(filename);
    }
    while ((ch = infile.get()) != EOF)
    {
        if (isprint(ch)) //只检测了可打印字符，，没懂题目说的字符包括什么
            num++;
    }
    cout << "num: " << num << endl;
    infile.close();
    return 0;
}