/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedLoser.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:43:17 by atucci            #+#    #+#             */
/*   Updated: 2024/04/13 17:11:45 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedLoser.hpp"
#include <iostream>

SedLoser::SedLoser(const std::string& filename, const std::string& target, const std::string& replacement)
{
// this goes the code
	_filename = filename;
	_target = target;
	_replacement = replacement;
}

// Define the replace method for the SedLoser class
void SedLoser::replace()
{
	// Create an input file stream (ifstream) object named inFile
	// The c_str() function is used to return a pointer to an array that contains a null-terminated sequence of characters representing the current value of the string object
	std::ifstream inFile(_filename.c_str());
	// Check if the file was opened successfully
	if (!inFile)
	{
		std::cerr << RED << "Error opening file: " << _filename << RESET << std::endl;
		return;
	}
	// Create an output file stream (ofstream) object named outFile
	std::ofstream outFile((_filename + ".replace").c_str());

	// Check if the output file was created successfully
	if (!outFile)
	{
		std::cerr << RED << "Error creating output file."<< RESET << std::endl;
		return;
	}

	// Declare a string to hold each line from the file
	std::string line;

	// Use a while loop to get each line from the file
	while (std::getline(inFile, line))
	{
		// Declare a variable to hold the position of the target string in the line
		size_t pos = 0;

		// Use a while loop to find and replace all occurrences of the target string in the line
		while ((pos = line.find(_target, pos)) != std::string::npos)
		{
			line.erase(pos, _target.length());
			line.insert(pos, _replacement);
			pos += _replacement.length();
		}
		// Write the modified line to the output file
		outFile << line << '\n';
	}
}

