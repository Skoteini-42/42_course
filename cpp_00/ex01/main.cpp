#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phonebook;
	std::string	input;

	while (true)
	{
		std::cout << "Please type ADD, SEARCH or EXIT: ";
		std::getline(std::cin, input);
		if (std::cin.eof() || input == "EXIT")
			break ;
		else if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.searchContact();
		else
			std::cout << "Invalid command.\n";
	}
	return (0);
}
