#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<double, 3> score;
    double average;
    cin >> score[0] >> score[1] >> score[2];
    average = (score[0] + score[1] + score[2]) / 3;
    cout << "First: " << score[0] << endl;
    cout << "Second: " << score[1] << endl;
    cout << "Third: " << score[2] << endl;
    cout << "Average: " << average << endl;
    return 0;
}