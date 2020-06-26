#include <iostream>
using namespace std;
class Account {
    string name;
    string AccountNumber;
    int money;
public:
    Account(string na = "DefaultName", string accnum = "DefaultNumber", int num = 0);
    void deposit(int num);
    bool withdraw(int num);
    void show() const;
};

Account::Account(string na, string accnum, int num)
{
    name = na;
    AccountNumber = accnum;
    money = num;
}
void Account::deposit(int num)
{
    money += num;
}
bool Account::withdraw(int num) {
    if (money < num)
        return 0;
    money -= num;
    return 1;
}
void Account::show() const
{
    cout << "Name: " << name << "\tAccount: " << AccountNumber << "\tMoney: " << money << endl;
}

int main()
{
    Account player;
    player.show();
    player.deposit(1000);
    player.show();
    player.withdraw(500);
    player.show();
    player.withdraw(1000);
    player.show();
    return 0;
}