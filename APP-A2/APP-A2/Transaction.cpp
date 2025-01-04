#include "Transaction.h"
#include <iostream>


Transaction::Transaction(std::string description, float value, std::string timestamp) : description(description), value(value), timestamp(timestamp)
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
	std::cout << "\"" << description << "\" | £" <<  value << " | Time: " << timestamp << std::endl;
}