#include "Account.h"
#include <iostream>


Account::Account(float openingBalance)
{
	balance = openingBalance;
}

void Account::deposit(float amount)
{
	balance += amount;
}

void Account::toString()
{
	std::cout << "Account Balance: " << balance << std::endl;
}	

void Account::withdraw(float amount)
{
	balance -= amount;
}