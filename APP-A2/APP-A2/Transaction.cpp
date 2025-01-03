#include "Transaction.h"
#include <iostream>


Transaction::Transaction(std::string description, float value, std::string timestamp)
{
	
}

float Transaction::getValue() const
{
	return value;
}

std::string Transaction::getDescription() const
{
	return description;
}

std::string Transaction::getTimestamp() const
{
	return timestamp;
}

void Transaction::toString()
{

	std::cout << "Transaction Description: " << description << std::endl;
	std::cout << "Transaction Value: " << value << std::endl;
	std::cout << "Transaction Timestamp: " << timestamp << std::endl;
}