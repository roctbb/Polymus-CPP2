#include <iostream>
#include <fstream>
#include <string>
#include "Account.h"
using namespace std;


int main()
{
    string command;
    while (true)
    {
        cin>>command;
        if (command=="exit")
        {
            return 0;
        }
        else if (command=="change" || command=="balance")
        {
            int id, amount;
            cin>>id>>amount;

            try{
                Account account(id);
                if (command=="balance")
                {
                    cout<<account.GetBalance()<<endl;
                }
                else
                {
                    if(account.ChangeBalance(amount))
                    {
                        cout<<"success"<<endl;
                    }
                    else
                    {
                        cout<<"low funds"<<endl;
                    }
                }
            }
            catch (...)
            {
                cout<<"Not found"<<endl;
            }
        }
        else if (command=="register")
        {
            string name;
            int overdraft;
            cin>>name>>overdraft;
            int id = Account::Register(name, overdraft);
            cout<<"Success, id: "<<id<<endl;
        }
        else
        {
            cout<<"Not a command"<<endl;
        }
    }
}