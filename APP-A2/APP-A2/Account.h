#pragma once
// Account - abstract, implements basic account func
class Account
{		
	public:
		explicit Account(float openingBalance);
		virtual ~Account();

		virtual void deposit(float amount);
		virtual void toString();
		virtual void withdraw(float amount);

		float balance;
};

