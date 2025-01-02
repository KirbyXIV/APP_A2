#include "Savings.h"
#include <cmath>
#include <iostream>

Savings::Savings(float openingBalance, bool isa) : Account(openingBalance) {
	if (openingBalance >= 1000 && isa) {
		isa = true;
		balance = openingBalance;
		interestRate = 1.15;
	}
	else if (openingBalance >= 0 && !isa) {
		isa = false;
		balance = openingBalance;
		interestRate = 0.85;
	}
	else {
		std::cout << "An error has occured. Opening balance must be greater than 1000 for an ISA account." << std::endl;
	}
}
float Savings::computeInterest(int years) {
	float rate = interestRate / 100;
	float interest = balance * pow((1 + (rate / 12)), 12 * years);
}