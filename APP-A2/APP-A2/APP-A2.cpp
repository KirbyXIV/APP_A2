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

int main()
{
	std::vector <std::string> parameters;
	std::string userCommand;
	// you may also want to store a collection of opened accounts here

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
		std::string option = parameters[1];

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
			if (option.compare("1") == 0) {
				std::cout << "Current";
			}
			else if (option.compare("2") == 0) {
				std::cout << "Savings";
			}
			else if (option.compare("3") == 0) {
				std::cout << "ISA";
			}
		}
		else if (command.compare("view") == 0)
		{
			// display an account according to an index (starting from 1)
			// alternatively, display all accounts if no index is provided
		}
		else if (command.compare("withdraw") == 0)
		{
			// allow user to withdraw funds from an account
		}
		else if (command.compare("deposit") == 0)
		{
			// allow user to deposit funds into an account
		}
		else if (command.compare("transfer") == 0)
		{
			// allow user to transfer funds between accounts
			// i.e., a withdrawal followed by a deposit!
		}
		else if (command.compare("project") == 0)
		{
			// compute compound interest t years into the future

			// interest equation =
			// output = input(1 + (rate/number of times interest is applied per unit time))^(number of times interest is applied per unit time*time)
		}
		//else if (command.compare("search"))
		//{
		//	allow users to search their account history for a transaction
		//  (this is a stretch task)
		//}

	}

	std::cout << "Press any key to quit...";
	std::getchar();
}


// CLASS STRUCTURES
// Account - abstract, implements basic account func
class Account { // Abstract
	protected:
		float balance;
	public:

};
// Current Account - no interest, £500 overdraft
class Current : public Account {

};
// Savings Account - is interest, rates dependant on savings or ISA
class Savings : public Account {
	public:
};

class ISA : public Account {
	public:
		int years;
		void projectedInterest() {
			float interest = balance * pow((1 + (0.0115 / 12)), 12 * years);
		}

};
// InterestEarning Interface - implemented by savings account to project interests
// Transaction - stores transactions details (value, description, timestamp)
// History - data structure, stores list of transactions



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
