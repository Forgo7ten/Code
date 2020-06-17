#include <iostream>

using namespace std;

int main()
{
    int num[3][12], sum=0, ssum=0;
    for (int i = 0; i < 3; i++)
    {
        sum = 0;
        for (int j = 0; j < 12; ++j)
        {
            cin >> num[i][j];
            sum += num[i][j];
        }
        cout << "di " << i + 1 << " year,book_sum: " << sum << endl;
        ssum += sum;
    }
    cout << "The three years booknum is: " << ssum << endl;
    return 0;
}