/* ------------------------------------------------------
CMP2811: Applied Programming Paradigms
Driver program for "LincBank" Assessment Item 2
Semester A 2024

During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.

You should avoid removing parts of this driver program, but
add to it the necessary code to produce your implementation.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

#include "Account.h"
#include "Current.h"
#include "Savings.h"



#ifdef _WIN32
#include <windows.h>
#endif

Account* openAccount(int type, float initial_deposit) {
	// opens a new account
	if (type == 1) { // current
		return new Current(initial_deposit);
	}
	else if (type == 2) { // savings
		return new Savings(initial_deposit, false);
	}
	else if (type == 3) { // isa
		return new Savings(initial_deposit, true);
	}
	else { // returns invalid account type
		std::cout << "Invalid account type" << std::endl;
	}
	return nullptr;
}

bool checkForAccount(const std::vector<Account*>& accountList, const std::string& type) {
	// gets the account type to see if certain accounts already exist
	for (const auto account : accountList) {
		if (account->accountType() == type) {
			return true;
		}
	}
	return false;
}

void tryComputeInterest(Account* Account, int years) {
	// checks if the account is a savings/isa account
	if (auto savings = dynamic_cast<Savings*>(Account)) {
		// if it is, compute the interest
		float postInterestBalance = savings->computeInterest(years);
		std::string accountType = savings->accountType();
		std::cout << "Projected balance (" << accountType<<  ") in " << years << " years: " << postInterestBalance << std::endl;
	}
	else {
		// if it isnt, let them know they need it to be a savings account
		std::cout << "Account is not a savings account" << std::endl;
	}
}

int main()
{
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
	std::vector <std::string> parameters;
	std::string userCommand;
	// you may also want to store a collection of opened accounts here

	std::vector<Account*> accountList;
	Account* mostRecent = nullptr;

	std::cout << "~~~ Welcome to LincBank! ~~~\n"
				 "Enter \"options\" to see all available commands\n";


	while (userCommand != "exit")
	{
		parameters.clear(); // clear ready for next command
		std::cout << std::endl << ">>>";

		std::getline(std::cin, userCommand);
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		// Define all commands as per the brief
		std::string command = parameters[0];
		

		if (command.compare("options") == 0)
		{
			// display the various commands to the user
			std::cout << 
				"open type initial_deposit: open a current (1), savings (2) or ISA (3) account\n"
				"view[index]: view balance and recent transactions\n"
				"withdraw sum : withdraw funds from most recently viewed account\n"
				"deposit sum : deposit funds into most recently viewed account\n"
				"transfer source destination sum : transfer funds between accounts\n"
				"project years : project balance forward in time\n"
				"exit : close this application\n"
				"options : view these options again\n";
		}
		else if (command.compare("open") == 0)
		{
			// allow a user to open an account
			// e.g., Account* a = new Savings(...);
			float initialBalance;

			if (parameters.size() == 2) {
				initialBalance = 0;
			}
			else {
				initialBalance = std::stof(parameters[2]);
			}
			switch (std::stoi(parameters[1])) {
				case 1: // current account
					if (checkForAccount(accountList, "Current")) {
						// sees if there is a current account, if so you cant make another
						std::cout << "Current account already exists" << std::endl;
						break;
					}

					if (initialBalance < 0) {
						// checks if inital balance is greater than 0
						std::cout << "Initial balance must be greater than 0" << std::endl;
						break;
					}
					else {
						// if conditions are met, make a new account and append it to the accountList vector
						accountList.push_back(openAccount(1, initialBalance));
						std::cout << "Current account opened with balance: " << initialBalance << std::endl;
						break;
					}
					
				case 2: // savings account
					if (initialBalance < 0) { // cannot open account with < 0
						std::cout << "Initial balance must be greater than 0" << std::endl;
						break;
					}
					else { // creates account and appends to list
						accountList.push_back(openAccount(2, initialBalance));
						std::cout << "Savings account opened with balance: " << initialBalance << std::endl;
						break;
					}
					
				case 3: // isa account
					if (checkForAccount(accountList, "ISA")) {
						std::cout << "ISA account already exists" << std::endl;
						break;
					}
					if (initialBalance < 1000) { // cannot open account with < 1000
						std::cout << "ISA account must be opened with a minimum balance of 1000" << std::endl;
						break;
					}
					else { // creates account and appends to list
						accountList.push_back(openAccount(3, initialBalance));
						std::cout << "ISA account opened with balance: " << initialBalance << std::endl;
						break;
					}
			}
			
		}
		else if (command.compare("view") == 0)
		{
			// display an account according to an index (starting from 1)
			// alternatively, display all accounts if no index is provided
			if (parameters.size() == 1) {
				// shows full account list if specific account isnt specified
				std::cout << "\n Full Account List:\n" << std::endl;
				for (int i = 0; i < accountList.size(); i++) {
					std::cout << "Account " << i + 1 << ":" << std::endl;
					accountList[i]->toString();

				}
			}
			else {
				// shows specific account if specified
				accountList[std::stoi(parameters[1]) - 1]->toString();
				mostRecent = accountList[std::stoi(parameters[1]) - 1];
				// shows transaction history for said account
				std::vector<Transaction> history = mostRecent->history;
				std::cout << "Transaction History: " << std::endl;
				for (auto& transaction : history) {
					transaction.toString();
				}
			}

		}
		else if (command.compare("withdraw") == 0)
		{
			// allow user to withdraw funds from an account
			if (parameters.size() == 2) {
				// withdraws from most recently viewed account
				std::cout << "Withdrawing money from most recently view account" << std::endl;
				if (mostRecent == nullptr) { // checks if account has been viewed
					// if not, let them know
					std::cout << "No account has been viewed yet" << std::endl;
				}
				else { // if it has, withdraw from it
					mostRecent->withdraw("Withdraw", std::stof(parameters[1]));
					mostRecent->toString();
				}
				
			}
			else if (parameters.size() == 3) { // withdraws from specified account
				accountList[std::stoi(parameters[1]) - 1]->withdraw("Withdraw", std::stof(parameters[2]));
				accountList[std::stoi(parameters[1]) - 1]->toString();
			}

		}
		else if (command.compare("deposit") == 0)
		{
			// allow user to deposit funds into an account
			if (parameters.size() == 2) { // deposits into most recently viewed account
				std::cout << "Depositing money into most recently view account" << std::endl;
				if (mostRecent == nullptr) { // checks if account has been viewed
					// if not, let them know
					std::cout << "No account has been viewed yet" << std::endl;
				}
				else if (accountList.size() == 1){ // if there is only one account, deposit into that
					mostRecent->deposit("Deposit", std::stof(parameters[1]));
					mostRecent->toString();
				}
			}
			else if (parameters.size() == 3) { // deposits into specified account
				accountList[std::stoi(parameters[1]) - 1]->deposit("Deposit" , std::stof(parameters[2]));
				accountList[std::stoi(parameters[1]) - 1]->toString();
			}
		}
		else if (command.compare("transfer") == 0)
		{
			// allow user to transfer funds between accounts
			// i.e., a withdrawal followed by a deposit!
			if (parameters.size() == 4) { // transfers from source to destination
				const int sourceIndex = std::stoi(parameters[1]) - 1;
				const int destinationIndex = std::stoi(parameters[2]) - 1;
				const float amount = std::stof(parameters[3]);
				// checks if source and destination are valid
				if (sourceIndex >= 0 && sourceIndex <= accountList.size() && destinationIndex >= 0 && destinationIndex <= accountList.size()) {
					accountList[sourceIndex]->withdraw("Transfer Out", amount); // withdraws from source
					accountList[destinationIndex]->deposit("Transfer in", amount); // deposits into destination
					accountList[sourceIndex]->toString();
					accountList[destinationIndex]->toString();
				}
				else { // if not, let them know
					std::cout << "Invalid account index" << std::endl;
				}
			}
			

		}
		else if (command.compare("project") == 0)
		{
			// compute compound interest t years into the future

			// interest equation =
			// output = input(1 + (rate/number of times interest is applied per unit time))^(number of times interest is applied per unit time*time)
			if (parameters.size() == 2 ) { // projects most recently viewed account
				std::cout << "Projecting most recently viewed account " << parameters[1] << " years" <<std::endl;
				if (mostRecent == nullptr) { // checks if account has been viewed
					// if not, let them know
					std::cout << "No account has been viewed yet" << std::endl;
				}
				else { // if it has, project the interest
					tryComputeInterest(mostRecent, std::stoi(parameters[1]));
				}
			}
			else if (parameters.size() == 3) { // projects specified account
				tryComputeInterest(accountList[std::stoi(parameters[1]) - 1], std::stoi(parameters[2]));
			}
		}
		else if (command.compare("search") == 0)
		{ // searches for a transaction
			std::cout << "Searching for transaction" << std::endl;
			if (parameters.size() == 2) { // searches for transaction in most recently viewed account
				std::vector<Transaction> result = mostRecent->searchForTransaction(std::stof(parameters[1]));
				std::cout << "Transactions found: " << std::endl;
				if (result.size() == 0) { // if no transactions are found, let them know
					std::cout << "No transactions found" << std::endl;
				}
				else { // if transactions are found, display them
					for (auto& transaction : result) {
						transaction.toString();
					}
				}
			}
		}

	}

	std::cout << "Press any key to quit...";
	std::getchar();
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
