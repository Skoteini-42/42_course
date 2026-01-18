#include "Bureaucrat.hpp"
#include <iostream>

int	main()
{
	std::cout << "=== EXCEPTIONS TEST ===\n" << std::endl;

	std::cout << "\n1. Valid tests :\n" << std::endl;

	try
	{
		Bureaucrat john("John", 50);
		std::cout << john << std::endl;
		john.incrementGrade();
		std::cout << "After increment: " << john << std::endl;
		john.decrementGrade();
		std::cout << "After decrement: " << john << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n2. Invalid tests :\n" << std::endl;

	try
	{
		Bureaucrat high("High", 1);
		high.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat low("Low", 150);
		low.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat invalid1("Invalid", 0);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat invalid2("Invalid", -1);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat invalid3("Invalid", 151);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== END OF TEST ===\n" << std::endl;

	return 0;
}