#include <iostream>
#include "bankaccount.h"
#include "checkingaccount.h"
#include "savingaccount.h"
using namespace std;

int main ()
{
    savingAccount a1(123456789, 50000, 0.07);
	checkingAccount a2(987654321, 10000, 0.07, 20000, 10);

    a1.postInterest (5);
    a1.withdrawMoney (100);
    a1.deposit (100);
    a1.printAccountInformation ();

    a2.postInterest (5);
    a2.withdrawMoney (100);
    a2.deposit (25);
    a2.writeACheck (100);
    a2.printAccountInformation ();
}