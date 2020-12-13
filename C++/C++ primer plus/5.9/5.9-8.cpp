#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char word[20];
    const char done[5] = "done";
    int num = 0;
    cout << "Enter words (to stop, type the word done):\n";
    cin >> word;
    while (strcmp(word, done))
    {
        num++;
        cin >> word;
    }
    cout << "You entered a total of " << num << " words.\n";
    return 0;
}