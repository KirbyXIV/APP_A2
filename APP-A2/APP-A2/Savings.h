#pragma once
#include "Account.h"
#include "InterestEarnings.h"
#include <string>
// Savings Account - is interest, rates dependant on savings or ISA
class Savings : public Account, public InterestEarnings {
	public:
		explicit Savings(float openingBalance, bool isa);

		void deposit(std::string message, float amount) override;
		void toString() override;
		void withdraw(std::string message, float amount) override;

		std::string accountType() override;

		float computeInterest(int years) override;

	private:
		bool isa;
		float interestRate = 0.85;
};

