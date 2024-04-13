/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedLoser.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:39:56 by atucci            #+#    #+#             */
/*   Updated: 2024/04/13 11:43:00 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDLOSER_HPP
#define SEDLOSER_HPP

#include <string>
#include <fstream>

class SedLoser {
public:
	SedLoser(const std::string& filename, const std::string& target, const std::string& replacement);
	void replace();

private:
	std::string _filename;
	std::string _target;
	std::string _replacement;
};

#endif // SEDLOSER_HPP

