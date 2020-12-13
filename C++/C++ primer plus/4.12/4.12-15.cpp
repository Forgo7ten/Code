#include <iostream>
#include <vector>
using namespace std;
struct fish {
    string variety;
    int weight;
    double length;
};
int main()
{
    int i;
    int* p;
    // vector<struct fish> arr(3); 方法一
    fish* arr = new fish[3]; // 方法二
    for (i = 0; i < 3; i++)
    {
        cin >> arr[i].variety >> arr[i].weight >> arr[i].length;
    }
    for (i = 0; i < 3; i++)
    {
        cout << arr[i].variety << arr[i].weight << arr[i].length << endl;
    }
    delete[] arr;  // 方法二
    return 0;
}