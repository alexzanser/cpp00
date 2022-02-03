#include "phonebook.hpp"

int main()
{
	std::string command = "add";
	int id = -1;
	PhoneBook Book;

	std::cout << "Hi this is shitty phonebook!" << std::endl;
	while (command != "EXIT")
	{
		std::cout << "Use ADD to add contact, SEARCH for look up, and EXIT to close." << std::endl;
		std::getline(std::cin, command);
		if (command == "ADD")
			Book.add();
		else if (command == "SEARCH")
		{
			Book.display();
			std::cout << "Enter conctact ID (0-8):" << std::endl;
			if (!(std::cin >> id) || id < 0 || id > 7)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Error: Invalid ID" << std::endl;
			}
			else
			{
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				Book.display(id);
			}
		}
	}
}
