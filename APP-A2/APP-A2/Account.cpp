#define _CRT_SECURE_NO_WARNINGS

#include "Account.h"
#include <iostream>
#include <ctime>

Account::Account(float openingBalance)
{
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
	time_t now = time(0);
	char* dt = ctime(&now);
	history.emplace_back(type, amount, std::string(dt));

}

std::vector<Transaction> Account::searchForTransaction(float value) const {
	std::vector<Transaction> result;
	for (const auto& transaction : history) {
		if (transaction.getValue() == value) {
			result.push_back(transaction);
		}
	}
	return result;
}