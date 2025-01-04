#include "Savings.h"
#include <cmath>
#include <iostream>

Savings::Savings(float openingBalance, bool isIsa) : Account(openingBalance) {
	if (openingBalance >= 1000 && isIsa) {
		isa = true;
		balance = openingBalance;
		interestRate = 1.15;
		Account::newTransaction("Opening Balance (ISA)", openingBalance);
	}
	else if (openingBalance >= 0 && !isIsa) {
		isa = false;
		balance = openingBalance;
		interestRate = 0.85;
		newTransaction("Opening Balance (Savings)", openingBalance);
	}
	else {
		std::cout << "An error has occured. Opening balance must be greater than 1000 for an ISA account." << std::endl;
	}
}

void Savings::deposit(std::string message, float amount) {
	if (amount < 0) {
		std::cout << "Cannot deposit a negative amount" << std::endl;
	}
	else {
		balance += amount;
		if (isa) {
			newTransaction(message + " (ISA)", amount);
		}
		else {
			newTransaction(message + " (Savings)", amount);
		}
	}
}

void Savings::toString() {
	if (isa) {
		std::cout << "ISA Account Balance: " << balance << std::endl;
	}
	else {
		std::cout << "Savings Account Balance: " << balance << std::endl;
	}
}

void Savings::withdraw(std::string message, float amount) {
	if (amount < 0) {
		std::cout << "Cannot withdraw a negative amount" << std::endl;
	}
	else if (balance - amount < 0) {
		std::cout << "Cannot withdraw more than the account balance" << std::endl;
	}
	else {
		balance -= amount;
		if (isa) {
			newTransaction(message + " (ISA)", -amount);
		}
		else {
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
	float rate = interestRate / 100;

	return balance * pow((1 + (rate / 12)), 12 * years);;
}