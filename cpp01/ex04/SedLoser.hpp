/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedLoser.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 11:39:56 by atucci            #+#    #+#             */
/*   Updated: 2024/04/13 17:11:00 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDLOSER_HPP
#define SEDLOSER_HPP
# define BLUE    "\033[1;34m"
# define PURPLE  "\033[1;35m"
# define GRAY    "\033[1;30m"
# define GREEN   "\033[1;32m"
# define CYAN    "\033[1;36m"
# define YELLOW  "\033[1;33m"
# define RED     "\033[1;31m"
# define RESET   "\033[0m"
# define BG_RESET        "\033[49m"
# define BG_GREEN        "\033[42m"
# define BG_CYAN         "\033[46m"
# define BG_YELLOW       "\033[43m"
# define BG_RED          "\033[41m"


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

