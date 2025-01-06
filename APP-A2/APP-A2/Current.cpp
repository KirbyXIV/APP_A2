#include "Current.h"
#include <iostream>

Current::Current(float openingBalance) : Account(openingBalance)
{
	// Set the overdraft limit
	overdraft = 500;
	if (openingBalance >= 0)
	{ // Set the opening balance
		balance = openingBalance;
		Account::newTransaction("Opening Balance (Current)", openingBalance);
	}
	else { // Error
		std::cout << "Opening Balance cannot be negative" << std::endl;
	}
}

void Current::deposit(std::string message, float amount)
{ // Deposit
	if (amount < 0)
	{
		// Error
		std::cout << "Cannot deposit a negative amount" << std::endl;
	}
	else
	{
		// Deposit
		balance += amount;
		newTransaction(message + " (Current)", amount);
	}
}

void Current::toString()
{
	std::cout << "Current Account Balance: " << balance << std::endl;
}

void Current::withdraw(std::string message, float amount)
{
	if (amount < 0)
	{ // Error
		std::cout << "Cannot withdraw a negative amount" << std::endl;
	}
	else if (balance - amount < -overdraft)
	{ // Error
		std::cout << "Cannot withdraw more than the overdraft limit" << std::endl;
	}
	else
	{ // Withdraw
		balance -= amount;
		newTransaction(message + " (Current)", -amount);
	}
}

std::string Current::accountType()
{
	return "Current";
}