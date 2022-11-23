#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include <iostream>
#include "bankaccount.h"
using namespace std;

class checkingAccount : public bankAccount
{
    private:
    double interestRate;
    double minimumBalance;
    double serviceCharge;

    public:
    void setInterestRate (double);
    double retrieveInterestRate ();
    void setMinimumBalance (double);
    double retrieveMinimumBalance ();
    void setServiceCharge (double);
    double retrieveServiceCharge ();
    void postInterest (int);
    bool lessThanMinimum ();
    void writeACheck (double);
    void withdrawMoney (double);
    void printAccountInformation ();

    checkingAccount (int,double,double,double,double);
};

void checkingAccount::setInterestRate (double inputInterestRate)
{
    this->interestRate = inputInterestRate;
}

double checkingAccount::retrieveInterestRate ()
{
    return this->interestRate;
}

void checkingAccount::setMinimumBalance (double inputMinimumBalance)
{
    this->minimumBalance = inputMinimumBalance;
}

double checkingAccount::retrieveMinimumBalance () 
{
    return this->minimumBalance;
}

void checkingAccount::setServiceCharge (double inputServiceCharge)
{
    this->serviceCharge = inputServiceCharge;
} 

double checkingAccount::retrieveServiceCharge ()
{
    return this-> serviceCharge;
}

void checkingAccount::postInterest (int inputMonth)
{
    setBalance(retrieveBalance() * (1 + (retrieveInterestRate() * inputMonth)));
}

bool checkingAccount::lessThanMinimum ()
{
    return retrieveBalance() < retrieveMinimumBalance();
} 

void checkingAccount::writeACheck (double inputCheck)
{
    setBalance( retrieveBalance() - inputCheck);
}

void checkingAccount::withdrawMoney (double inputwithdrawMoney)
{
    setBalance (retrieveBalance() - inputwithdrawMoney);
    if (lessThanMinimum())
        setBalance(retrieveBalance() - retrieveServiceCharge());
}

void checkingAccount::printAccountInformation()
{
    cout << "status :\n" << "Checking Account" << endl;
    cout << "account number is :\n" << retrieveAccountNumber() << endl;
    cout << "current balance is :\n" << retrieveBalance() << endl;
    cout << "interest rate is :\n" << retrieveInterestRate() << endl;
    cout << "minimum balance is :\n" << retrieveMinimumBalance() << endl;
    cout << "service charge is :\n" << retrieveServiceCharge() << endl << endl;
}

checkingAccount::checkingAccount(int num, double balance, double rate, double min, double service) : bankAccount(num, balance)
{
    setAccountNumber (num);
    setBalance (balance);
	setInterestRate (rate);
	setMinimumBalance (min);
	setServiceCharge (service);
}
#endif