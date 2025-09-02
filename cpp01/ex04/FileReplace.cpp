#include "FileReplace.hpp"
#include <fstream>
#include <iostream>
#include <string>

bool FileReplace::replaceInFile(const std::string& filename,
							const std::string& s1,
							const std::string& s2)
{
	if (s1.empty())
	{
		std::cerr << "Error : s1 cannot be empty" << std::endl;
		return (false);
	}
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error : could not open file" << std::endl;
		return (false);
	}
	char testChar;
    inputFile.get(testChar);
    if (inputFile.fail() && !inputFile.eof())
	{
        std::cerr << "Error: " << filename << " appears to be a directory" << std::endl;
        inputFile.close();
        return false;
    }
	inputFile.close();
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: could not open file " << filename << std::endl;
		return (false);
	}
	std::ifstream inputFile(filename.c_str());
	std::string content;
	std::string line;
	while (std::getline(inputFile, line))
		content = content + line + "\n";
	inputFile.close();
	if (!content.empty())
		content.erase(content.length() -1);
	std::string newContent = replaceOccurrences(content, s1, s2);
	std::ofstream outputFile((filename + ".replace").c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Error : could not create output file" << std::endl;
		return (false);
	}
	outputFile << newContent;
	outputFile.close();
	return (true);
}

std::string	FileReplace::replaceOccurrences(const std::string& content,
										const std::string& s1,
										const std::string& s2)
{
	std::string result;
	size_t pos = 0;
	size_t prevPos = 0;

	while ((pos = content.find(s1, prevPos)) != std::string::npos)
	{
		result.append(content, prevPos, pos - prevPos);
		result = result + s2;
		prevPos = pos + s1.length();
	}
	result = result + content.substr(prevPos);
	return (result);
}
