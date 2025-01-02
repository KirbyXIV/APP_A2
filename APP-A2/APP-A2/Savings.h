#pragma once
#include "Account.h"
#include "InterestEarnings.h"
// Savings Account - is interest, rates dependant on savings or ISA
class Savings : public Account, public InterestEarnings {
	public:
		explicit Savings(float openingBalance, bool isa);

		void deposit(float amount) override;
		void toString() override;
		void withdraw(float amount) override;

		float computeInterest(int years) override;

	private:
		bool isa;
		float interestRate = 0.85;
};

