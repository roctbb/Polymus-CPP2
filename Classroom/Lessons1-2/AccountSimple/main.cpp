#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Account
{
private:
    int id;
    string name;
    int balance;
    int overdraft;
public:
    Account(int userId, string userName, int userBalance, int userOverdraft) {
        id = userId;
        name = userName;
        overdraft = userOverdraft;
        balance = userBalance;
    }
    ~Account() {
    }
    string GetName() {
        return name;
    }
    int GetBalance() {
        return balance;
    }
    bool ChangeBalance(int amount) {
        if (balance+amount+overdraft>=0) {
            balance+=amount;
            return true;
        }
        return false;
    }
};

int main()
{
    Account account(1, "Vasya Pupkin", 100, 200);
    while(true)
    {
        int amount;
        cin>>amount;
        if (account.ChangeBalance(amount))
        {
            cout<<"OK, balance: "<<account.GetBalance()<<endl;
        }
        else
        {
            cout<<"ERROR, balance: "<<account.GetBalance()<<endl;
        }
    }

}
