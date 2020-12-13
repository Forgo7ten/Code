#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    cout << "Enter words (q to quit):\n";
    string word;
    int flag[3] = { 0 };
    while (cin >> word && !(word.length() == 1 && word[0] == 'q'))
    {
        if (isalpha(word[0]))
        {
            if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u')
                flag[0]++;
            else
                flag[1]++;
        }
        else
            flag[2]++;
    }
    cout << flag[0] << " words beginning with vowels\n"
        << flag[1] << " words beginning with consonants\n"
        << flag[2] << " others\n";
    return 0;
}