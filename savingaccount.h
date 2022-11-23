#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

#include <iostream>
#include "bankaccount.h"
using namespace std;

class savingAccount : public bankAccount
{
    private:
    double interestRate;

    public:
    void setInterestRate (double);
    double retrieveInterestRate ();
    void postInterest (int);
    void withdrawMoney (double);
    void printAccountInformation ();

    savingAccount (int,double,double);
};

void savingAccount::setInterestRate (double inputInterestRate)
{
    this->interestRate = inputInterestRate;
}

double savingAccount::retrieveInterestRate ()
{
    return this->interestRate;
}

void savingAccount::postInterest (int inputMonth)
{
    setBalance(retrieveBalance() * (1 + (retrieveInterestRate() * inputMonth)));
}

void savingAccount::withdrawMoney (double inputwithdrawMoney)
{
    setBalance(retrieveBalance() - inputwithdrawMoney);
}

void savingAccount::printAccountInformation()
{
    cout << "status:\n" << "Saving Account" << endl;
    cout << "account number is :\n" << retrieveAccountNumber() << endl;
    cout << "current balance is :\n" << retrieveBalance() << endl;
    cout << "interest rate is :\n" << retrieveInterestRate() << endl << endl;
}

savingAccount::savingAccount(int num, double balance, double rate) : bankAccount (num, balance)
{
    setAccountNumber (num);
    setBalance (balance);
	setInterestRate(rate);
}
#endif