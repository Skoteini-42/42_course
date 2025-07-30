#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook() : contactCount(0) {}

void	PhoneBook::addContact()
{
	if (contactCount < MAX_CONTACTS)
	{
		contacts[contactCount] = Contact::createContact(contactCount);
		contactCount++;
	}
	else
	{
		for (int i = 0; i < MAX_CONTACTS - 1; i++)
		{
			contacts[i] = contacts[i + 1];
			contacts[i].setIndex(i);
		}
		contacts[MAX_CONTACTS - 1] = Contact::createContact(MAX_CONTACTS - 1);
	}
}

void	PhoneBook::searchContact() const
{
	if (contactCount == 0)
	{
		std::cout << "Phonebook is empty.\n";
		return ;
	}
	displayContactList();
	while (true)
	{
		std::ostringstream oss;
		oss << contactCount;
		std::string countStr = oss.str();
		int index = getContactIndex("Enter contact index (1-" + countStr + "): ");
		if (index >= 0)
		{
			contacts[index].printContact();
			break ;
		}
		else
			continue ;
	}
}

void	PhoneBook::displayContactList() const
{
	std::cout << std::setw(10) << "Index" << "|"
				<< std::setw(10) << "First Name" << "|"
				<< std::setw(10) << "Last Name" << "|"
				<< std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < contactCount; i++)
		contacts[i].printSearchLine();
}
//TODO : fix empty prompt + ctrl+D
int PhoneBook::getContactIndex(const std::string &prompt) const
{
	std::string input;
	int index;

	while (true)
	{
		std::cout << prompt;
    	if (!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			exit (0);
		}
		if (input.empty())
		{
			std::cerr << "Error: Input cannot be empty.\n";
			continue ;
		}
    	std::stringstream(input) >> index;
    	if (index < 1 || index > contactCount)
		{
			std::cerr << "Error: Invalid index.\n";
			continue ;
		}
	return (index - 1);
	}
}
