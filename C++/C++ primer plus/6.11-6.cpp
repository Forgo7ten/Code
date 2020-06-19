#include <iostream>

using namespace std;
struct People {
    string name;
    double money;
    int flag;
};
int main()
{
    int pnum, i, flag[2] = { 0 };
    cout << "Input patrons'num: ";
    cin >> pnum;
    People* p = new People[pnum];
    for (i = 0; i < pnum; i++)
    {
        cin >> p[i].name >> p[i].money;
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
}



/*
测试数据
abc 10001
abd 10001
abe 10001
abf 10001
abg 9999
abh 10001
abs 10001
abg 10001
abl 10001
abk 10001
abj 10001
abn 10001
*/