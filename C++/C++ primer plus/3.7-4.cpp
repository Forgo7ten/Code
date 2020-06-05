#include <iostream>
using namespace std;

int main()
{
    long long seconds;
    int day, hour, minute, second, temp;
    const int rate1 = 60, rate2 = 24;
    cout << "enter the number of seconds: ";
    cin >> seconds;
    day = seconds / (rate1 * rate1 * rate2);
    temp = seconds % (rate1 * rate1 * rate2);
    hour = temp / (rate1 * rate1);
    temp %= rate1 * rate1;
    minute = temp / rate1;
    second = temp % rate1;
    cout << seconds << " seconds = "
        << day << " days, "
        << hour << " hours, "
        << minute << " minutes, "
        << second << " seconds\n";
    return 0;
}