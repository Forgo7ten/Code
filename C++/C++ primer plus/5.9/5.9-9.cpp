#include <iostream>
#include <string>
using namespace std;

int main()
{
    string word;
    const string done = "done";
    int num = 0;
    cout << "Enter words (to stop, type the word done):\n";
    cin >> word;
    while (word != done)
    {
        num++;
        cin >> word;
    }
    cout << "You entered a total of " << num << " words.\n";
    return 0;
}