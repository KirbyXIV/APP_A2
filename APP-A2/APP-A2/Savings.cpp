#include "Savings.h"
#include <cmath>
#include <iostream>

Savings::Savings(float openingBalance, bool isIsa) : Account(openingBalance) {
	if (openingBalance >= 1000 && isIsa) { // ISA account
		isa = true;
		balance = openingBalance;
		interestRate = 1.15; // 1.15% interest rate
		Account::newTransaction("Opening Balance (ISA)", openingBalance);
	}
	else if (openingBalance >= 0 && !isIsa) { // Savings account
		isa = false;
		balance = openingBalance;
		interestRate = 0.85; // 0.85% interest rate
		newTransaction("Opening Balance (Savings)", openingBalance);
	}
	else { // Error
		std::cout << "An error has occured. Opening balance must be greater than 1000 for an ISA account." << std::endl;
	}
}

void Savings::deposit(std::string message, float amount) {
	if (amount < 0) { // Error
		std::cout << "Cannot deposit a negative amount" << std::endl;
	}
	else { // Deposit
		balance += amount;
		if (isa) { // ISA account
			newTransaction(message + " (ISA)", amount);
		}
		else { // Savings account
			newTransaction(message + " (Savings)", amount);
		}
	}
}

void Savings::toString() { // Print the account balance
	if (isa) { // ISA account
		std::cout << "ISA Account Balance: " << balance << std::endl;
	}
	else { // Savings account
		std::cout << "Savings Account Balance: " << balance << std::endl;
	}
}

void Savings::withdraw(std::string message, float amount) {
	if (amount < 0) { // Error
		std::cout << "Cannot withdraw a negative amount" << std::endl;
	}
	else if (balance - amount < 0) { // Error
		std::cout << "Cannot withdraw more than the account balance" << std::endl;
	}
	else { // Withdraw
		balance -= amount;
		if (isa) { // ISA account
			newTransaction(message + " (ISA)", -amount);
		}
		else { // Savings account
			newTransaction(message + " (Savings)", -amount);
		}
	}
}

std::string Savings::accountType() {
	if (isa) {
		return "ISA";
	}
	else {
		return "Savings";
	}
}

float Savings::computeInterest(int years) {
	// Calculate the interest
	float rate = interestRate / 100;

	return balance * pow((1 + (rate / 12)), 12 * years);;
}