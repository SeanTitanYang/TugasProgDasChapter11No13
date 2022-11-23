#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
using namespace std;

class bankAccount
{
    private:
    int accountNumber;
    double balance;

    public:
    void setAccountNumber(int);
    int retrieveAccountNumber();
    void setBalance(double);
    double retrieveBalance();
    void deposit(double);
    void withdrawMoney(double);
    void printAccountInformation();

    bankAccount (int, double);
};

void bankAccount::setAccountNumber(int inputAccountNumber)
{
    this->accountNumber = inputAccountNumber;
}

int bankAccount::retrieveAccountNumber()
{
    return this->accountNumber;
}

void bankAccount::setBalance(double inputBalance)
{
    this->balance = inputBalance;
}

double bankAccount::retrieveBalance()
{
    return this->balance;
}

void bankAccount::deposit(double inputDeposit)
{
    setBalance(retrieveBalance() + inputDeposit);
}

void bankAccount::withdrawMoney(double inputWithdraw)
{
    setBalance(retrieveBalance() - inputWithdraw);
}

void bankAccount::printAccountInformation()
{
    cout << "account number is :\n" << retrieveAccountNumber () << endl;
    cout << "current balance is :\n" << retrieveBalance() << endl;
}

bankAccount::bankAccount (int InputNumber, double InputBalance)
{
    setAccountNumber(InputNumber);
    setBalance(InputBalance);
}
#endif