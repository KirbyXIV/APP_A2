#pragma once
#include "Account.h"
#include <string>
// Current Account - no interest, £500 overdraft
class Current : public Account {
	public:
		explicit Current(float openingBalance);

		void deposit(std::string message, float amount) override;
		void toString() override;
		void withdraw(std::string message, float amount) override;

		std::string accountType() override;

		float overdraft;
};

