//
// Created by Бородин Ростислав on 29.01.17.
//

#include "Account.h"

using namespace std;

Account::Account(int userId)
{
    id = userId;
    string filename = "../../data/"+to_string(userId)+".txt";
    ifstream fin(filename);
    if(!fin.is_open())
    {
        throw "file not found";
    }
    fin>>name>>balance>>overdraft;
    fin.close();

}
Account::~Account()
{
    if (id>0)
    {
        string filename = "../../data/"+to_string(id)+".txt";
        ofstream fout(filename);
        fout<<name<<" "<<balance<<" "<<overdraft;
        fout.close();
    }
}

string Account::GetName()
{
    return name;
}
int Account::GetBalance()
{
    return balance;
}
bool Account::ChangeBalance(int amount)
{
    if (balance+amount+overdraft>=0)
    {
        balance+=amount;
        return true;
    }
    return false;
}
int Account::Register(string userName, int overdraft)
{
    int last_id = 1;

    string setup_filename = "../../data/last_id.txt";
    ifstream fin_setup(setup_filename);
    fin_setup>>last_id;
    fin_setup.close();

    last_id++;

    string filename = "../../data/"+std::to_string(last_id)+".txt";
    ofstream fout(filename);
    fout<<userName<<" "<<0<<" "<<overdraft;
    fout.close();

    ofstream fout_setup(setup_filename);
    fout_setup<<last_id;
    fout_setup.close();

    return last_id;
}