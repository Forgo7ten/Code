#include <iostream>

using namespace std;

int main()
{
    int num;
    cout << "Enter number of rows: ";
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int j = i + 1;
        int k = num - i - 1;
        while (k--)
            cout << ".";
        while (j--)
            cout << "*";
        cout << endl;
    }
    return 0;
}