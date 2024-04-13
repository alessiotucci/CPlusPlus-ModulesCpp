/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedLoser.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:43:17 by atucci            #+#    #+#             */
/*   Updated: 2024/04/13 12:09:31 by atucci           ###   ########.fr       */
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

void SedLoser::replace()
{
	std::ifstream inFile(_filename.c_str());
	if (!inFile)
	{
		std::cerr << "Error opening file: " << _filename << std::endl;
		return;
	}

	std::ofstream outFile((_filename + ".replace").c_str());
	if (!outFile)
	{
		std::cerr << "Error creating output file." << std::endl;
		return;
	}

	std::string line;
	while (std::getline(inFile, line))
	{
		size_t pos = 0;
		while ((pos = line.find(_target, pos)) != std::string::npos)
		{
			line.erase(pos, _target.length());
			line.insert(pos, _replacement);
			pos += _replacement.length();
		}
		outFile << line << '\n';
	}
}
