#include "FileReplace.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Invalid number of argumnts." << std::endl;
		return (-1);
	}
	FileReplace replacer;
	if (!replacer.replaceInFile(argv[1], argv[2], argv[3]))
		return (-1);
	return (0);
}
