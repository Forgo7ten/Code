#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct People {
    string name;
    double money;
    int flag;
};

int main()
{
    ifstream infile;
    string filename;
    int pnum, i, flag[2] = { 0 };
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
    (infile >> pnum).get();
    People* p = new People[pnum];
    for (i = 0; i < pnum; i++)
    {
        getline(infile, p[i].name);
        (infile >> p[i].money).get();
        if (p[i].money > 10000)
        {
            p[i].flag = 1;
            flag[0] = 1;
        }
        else
        {
            p[i].flag = 0;
            flag[1] = 1;
        }
    }
    cout << "*********************************\nGrand Patrons\n";
    if (flag[0])
    {
        for (i = 0; i < pnum; i++)
            if (p[i].flag)
                cout << p[i].name << "\t" << p[i].money << endl;
    }
    else
        cout << "none.\n";
    cout << "*********************************\nPatrons\n";
    if (flag[1])
    {
        for (i = 0; i < pnum; i++)
            if (!p[i].flag)
                cout << p[i].name << "\t" << p[i].money << endl;
    }
    else
        cout << "none.\n";
    cout << "\nDone!\n";
    return 0;
    return 0;
}

/*
文件测试内容

9
Sam Stone
2000
Freida Flass
100500
Tammy Tubbs
5000
Rich Raptor
55000
abc
210001
abd
100
abe
101
abf
10401
abg ss
9999


*/