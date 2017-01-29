//
// Created by Бородин Ростислав on 29.01.17.
//

#ifndef ACCOUNTAUTOSAVE_ACCOUNT_H
#define ACCOUNTAUTOSAVE_ACCOUNT_H

#include <string>
#include <fstream>

using namespace std;

class Account
{
private:
    int id;
    string name;
    int balance;
    int overdraft;
public:
    Account(int userId);
    ~Account();

    string GetName();
    int GetBalance();
    bool ChangeBalance(int amount);

    static int Register(string userName, int overdraft);

};



#endif //ACCOUNTAUTOSAVE_ACCOUNT_H
