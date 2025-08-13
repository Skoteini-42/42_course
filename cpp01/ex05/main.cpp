#include "Harl.hpp"
#include <iostream>

int	main()
{
	Harl harl;

	std::cout << "------ DEBUG------" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl << "------ INFO------" << std::endl;
	harl.complain("INFO");
	std::cout << std::endl << "------ WARNING------" << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl << "------ ERROR------" << std::endl;
	harl.complain("ERROR");
	return (0);
}
