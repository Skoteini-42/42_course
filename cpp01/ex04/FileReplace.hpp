#ifndef FILEREPLACE_HPP
# define FILEREPLACE_HPP

# include <string>

class FileReplace
{
	private:

	std::string replaceOccurrences(const std::string& content,
								const std::string& s1,
								const std::string& s2);
};

#endif
