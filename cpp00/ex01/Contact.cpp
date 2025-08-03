#include "Contact.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>

Contact::Contact() : index(-1) {}

Contact	Contact::createContact(int index)
{
	Contact c;
	c.index = index;
	c.firstName = getInput("First name: ");
	c.lastName = getInput("Last name: ");
	c.nickname = getInput("Nickname: ");
	c.phoneNumber = getInput("Phone number: ");
	c.darkestSecret = getInput("Darkest secret: ");
	return (c);
}

void	Contact::setIndex(int idx)
{
	index = idx;
}

void	Contact::printSearchLine() const
{
	std::cout << std::setw(10) << index + 1 << "|"
			<< std::setw(10) << truncateField(firstName) << "|"
			<< std::setw(10) << truncateField(lastName) << "|"
			<< std::setw(10) << truncateField(nickname) << std::endl;
}

void	Contact::printContact() const
{
	std::cout << "First name: " << firstName << "\n"
			<< "Last name: " << lastName << "\n"
			<< "Nickname: " << nickname << "\n"
			<< "Phone number: " << phoneNumber << "\n"
			<< "Darkest secret: " << darkestSecret << std::endl;
}

std::string Contact::getInput(const std::string& prompt)
{
	std::string input;
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			exit (0);
		}
		if (!input.empty())
			return (input);
		std::cerr << "Error: Field cannot be empty!\n";
	}
}

std::string	Contact::truncateField(const std::string& field)
{
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	return (std::string(10 - field.length(), ' ') + field);
}
