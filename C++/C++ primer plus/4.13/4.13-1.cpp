#include <iostream>
#include <vector>
#include <array>
using namespace std;
struct infor {
    char first[40];
    char last[40];
    char letter;
    int age;
}stu;
int main()
{
    cout << "What is your first name? ";
    cin.getline(stu.first, 40);
    cout << "What is your last name? ";
    cin.getline(stu.last, 30);
    cout << "What letter grade do you deserve? ";
    cin >> stu.letter;
    stu.letter++;
    cout << "What is your age? ";
    cin >> stu.age;
    cout << "Name: " << stu.last << ", " << stu.first << endl;
    cout << "Grade: " << stu.letter << endl << "Age: " << stu.age << endl;
    return 0;
}