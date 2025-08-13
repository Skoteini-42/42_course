#include "Harl.hpp"
#include <iostream>

void Harl::debug()
{
	std::cout << "[ DEBUG ]\n"
			<< "I love having extra bacon for my "
			<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
			<< "I really do!\n";
}

void Harl::info()
{
	std::cout << "[ INFO ]\n"
			<< "I cannot believe adding extra bacon costs more money. "
			<< "You didn't put enough bacon in my burger! "
			<< "If you did, I wouldn't be asking for more!\n";
}

void Harl::warning()
{
	std::cout << "[ WARNING ]\n"
			<< "I think I deserve to have some extra bacon for free. "
			<< "I've been coming for years whereas you started working "
			<< "here just last month.\n";
}

void Harl::error()
{
	std::cout << "[ ERROR ]\n"
			<< "This is unacceptable! I want to speak to the manager now.\n";
}

int	Harl::getLevelIndex(std::string level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			return (i);
	}
	return (-1);
}

void	Harl::complain(std::string level)
{
	switch(getLevelIndex(level))
	{
		case 0:
			debug();
			std::cout << std::endl;
			info();
			std::cout << std::endl;
			warning();
			std::cout << std::endl;
			error();
			break ;
		case 1:
			info();
			std::cout << std::endl;
			warning();
			std::cout << std::endl;
			error();
			break ;
		case 2:
			warning();
			std::cout << std::endl;
			error();
			break ;
		case 3:
			error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
