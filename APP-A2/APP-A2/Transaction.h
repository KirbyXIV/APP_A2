#pragma once
#include <string>
class Transaction
{
	public:
		Transaction(std::string description, float value, std::string timestamp);

		float getValue() const;
		std::string getDescription() const;
		std::string getTimestamp() const;

		void toString();

	private:
		float value;
		std::string description;
		std::string timestamp;
};

