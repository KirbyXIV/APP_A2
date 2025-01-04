#pragma once
// Account - abstract, implements basic account func
#include <string>
#include <vector>
#include "Transaction.h"

class Account
{		
	public:
		explicit Account(float openingBalance);
		virtual ~Account() = default;

		virtual void deposit(std::string message, float amount);
		virtual void toString();
		virtual void withdraw(std::string message, float amount);

		virtual std::string accountType() = 0;

		float balance;

		std::vector<Transaction> history;
		std::vector<Transaction> searchForTransaction(float value) const;
		virtual void newTransaction(std::string type, float amount);
};

