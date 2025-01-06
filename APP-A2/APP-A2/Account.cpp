#define _CRT_SECURE_NO_WARNINGS

#include "Account.h"
#include <iostream>
#include <ctime>

Account::Account(float openingBalance)
{
	// Set the opening balance
	balance = openingBalance;
}

void Account::deposit(std::string message, float amount)
{
	balance += amount;
}

void Account::toString()
{
	std::cout << "Account Balance: " << balance << std::endl;
}	

void Account::withdraw(std::string message, float amount)
{
	balance -= amount;
}

void Account::newTransaction(std::string type, float amount)
{
	// Get the current time
	// Add the transaction to the history
	time_t now = time(0);
	char* dt = ctime(&now);
	history.emplace_back(type, amount, std::string(dt));

}

std::vector<Transaction> Account::searchForTransaction(float value) const {
	// Search for a transaction with a specific value
	std::vector<Transaction> result;
	for (const auto& transaction : history) {
		if (transaction.getValue() == value) {
			// Add the transaction to the result if found
			result.push_back(transaction);
		}
	}
	return result;
}