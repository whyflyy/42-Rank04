/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:54:47 by jcavadas          #+#    #+#             */
/*   Updated: 2025/06/04 16:25:15 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// COLOURS ///
#define RESET		"\033[0m"
#define RED			"\033[38;5;160m"
#define GREEN		"\033[38;5;76m"
#define BLUE		"\033[38;5;111m"
#define YELLOW		"\033[38;5;220m"
#define MAGENTA		"\033[38;5;183m"
#define CYAN		"\033[38;5;87m"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

std::string	getContent(std::ifstream *inFile)
{
	std::stringstream buffer;

	buffer << inFile->rdbuf();
	return (buffer.str());
}

std::string	replaceWords(std::string fileContent, std::string str1, std::string str2)
{
	std::string	buffer = fileContent;

	std::size_t	index = buffer.find(str1);
	if (index == std::string::npos)
	{
		std::cout << RED << "No string to be replaced found :(" << RESET << std::endl;
		return ("");
	}
	while (index != std::string::npos)
	{
		buffer.erase(index, str1.size());
		buffer.insert(index, str2);
		index = buffer.find(str1, index + str2.size());
	}
	return (buffer);
}

int getInput(std::string& input)
{
	while (true)
	{
		std::getline(std::cin, input);

		if (std::cin.fail())
		{
			std::cout << RED << "Input fail" << RESET << std::endl;
			return (0);
		}
		else if (std::cin.eof())
		{
			std::cout << RED << "EOF detected" << RESET << std::endl;
			return (0);
		}
		else if (input.empty())
		{
			std::cout << RED << "Input can't be empty, please try again: " << RESET;
			continue; // Prompt again
		}

		std::cout << std::endl;
		return (1); // Valid input received
	}
}

void	createOutFile(std::string fileContent, std::string fileName)
{
	std::ofstream	outFile;
	std::string		replaceFileName = fileName + "_replace";
	
	outFile.open(replaceFileName.c_str());
	if (outFile.fail())
	{
		std::cout << RED << "Failed to open outFile!" << RESET << std::endl;
		return ;
	}

	outFile << fileContent;
	outFile.close();
	std::cout << GREEN << replaceFileName << " has been created!" << RESET << std::endl;
	return ;
}

int main(void)
{
	std::string fileName, str1, str2, fileContent;
	std::ifstream inFile;

	std::cout << BLUE << "Please insert the file name: " << RESET;
	if(!getInput(fileName))
		return (1);

	std::cout << BLUE << "Please insert the string to be replaced: " << RESET;
	if(!getInput(str1))
		return (1);

	std::cout << BLUE << "Please insert the string that will replace: " << RESET;
	if(!getInput(str2))
		return (1);

	inFile.open(fileName.c_str());
	if (inFile.fail())
	{
		std::cout << RED << "Failed to open " << fileName << RESET << std::endl;
		return (1);
	}
	
	fileContent = getContent(&inFile);
	if (fileContent.empty())
	{
		std::cout << RED << fileName << " is empty!" << std::endl;
		return (1);
	}

	fileContent = replaceWords(fileContent, str1, str2);

	if (fileContent.empty())
		return (1);

	createOutFile(fileContent, fileName);
	inFile.close();
	return (0);
}


