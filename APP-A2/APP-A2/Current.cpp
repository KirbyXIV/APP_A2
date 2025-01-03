#include "Current.h"
#include <iostream>

Current::Current(float openingBalance) : Account(openingBalance)
{
	overdraft = 500;
	if (openingBalance >= 0)
	{
		balance = openingBalance;
		Account::newTransaction("Opening Balance (Current)", openingBalance);
	}
	else {
		std::cout << "Opening Balance cannot be negative" << std::endl;
	}
}

void Current::deposit(float amount)
{
	if (amount < 0)
	{
		std::cout << "Cannot deposit a negative amount" << std::endl;
	}
	else
	{
		balance += amount;
		newTransaction("Deposit (Current)", amount);
	}
}

void Current::toString()
{
	std::cout << "Current Account Balance: " << balance << std::endl;
}

void Current::withdraw(float amount)
{
	if (amount < 0)
	{
		std::cout << "Cannot withdraw a negative amount" << std::endl;
	}
	else if (balance - amount < -overdraft)
	{
		std::cout << "Cannot withdraw more than the overdraft limit" << std::endl;
	}
	else
	{
		balance -= amount;
		newTransaction("Withdrawal (Current)", amount);
	}
}

std::string Current::accountType()
{
	return "Current";
}