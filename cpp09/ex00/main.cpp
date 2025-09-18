/* ************************************************************************** */
/*                                                                            */
/*   Host: atucci-Surface-Laptop-3                                    /_/     */
/*   File: main.cpp                                                ( o.o )    */
/*   Created: 2025/06/21 13:58:48 | By: atucci <marvin@42.fr>      > ^ <      */
/*   Updated: 2025/09/18 17:32:04                                   /         */
/*   OS: Linux 6.8.0-59-generic x86_64 | CPU: Intel(R) Core(TM) i (|_|)_)     */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*
You have to create a program which outputs the value of a certain amount of bitcoin on a certain date.
This program must use a database in csv format which will represent bitcoin price over time.
This database is provided with this subject.
The program will take as input a second database, storing the different prices/dates to evaluate.
*/

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "btc program must take a file as an argument." << std::endl;
		return (-1);
	}
	else
		std::cout << "using the input file: " << av[1]  << std::endl;

	Btc btc;

//TODO: nel database troviamo il valore di conversione (?) o la quantita

    // load the provided DB file (commonly the subject provides "data.csv" in the repo)
    // change the path/name if your DB file is named differently
   if (!btc.loadDatabase("data.csv"))
    {
        // If you don't have a local data.csv, create one or change the name above.
        return 1;
    }
	else
		std::cout << "Correctly loaded the database: data.csv" << std::endl;

	if (!btc.processInputFile(av[1]))
		return (1);

//	std::cout << btc << std::endl;
	std::cout << "date => exchange value = value in usd $\t amout of btc is in the database" << std::endl;
	return (0);
}

/*
Your program will use the value in your input file.
Your program should display on the standard output the result of the value multiplied
by the exchange rate according to the date indicated in your database.
*/

