#!/usr/bin/perl
use strict;
use warnings;
use Term::ANSIColor;
use Time::HiRes;

print
"\n
  _____                  _     _                  _                 
 |  __ \                | |   | |                | |                
 | |__) |   ___   _ __  | |   | |_    ___   ___  | |_    ___   _ __ 
 |  ___/   / _ \ | '__| | |   | __|  / _ \ / __| | __|  / _ \ | '__|
 | |      |  __/ | |    | |   | |_  |  __/ \__ \ | |_  |  __/ | |   
 |_|       \___| |_|    |_|    \__|  \___| |___/  \__|  \___| |_|   
                                                                    
                                                                    \n";

print "\n\n";

# Define the command to run your program
my $command = './MyAwesomePhoneBook';

# Open a pipe to the command
open(my $pipe, '|-', $command)
or die color('bold red'), "Could not start $command: $!\n", color('reset');

# Define the contacts
my @contacts = (
	['Alessio', 'Tucci', 'tuccio', '123-456-7890', 'Loves Perl'],
	['Dario', 'abi-rachets', 'lebanese', '098-765-4321', 'Loves C#'],
	['Venelin', 'Zashef', 'venny', '098-765-4321', 'Loves Bulgaria'],
	['Flavio', 'Biondo', 'flavietto', '098-765-4321', 'Loves PIng pong'],
	['Ruggero', '        Dolzi', 'ruggy', '098-765-4321', 'Loves_IBM'],
	['Daniel', 'Ugzebu', 'youngbull', '098-765-4321', 'Loves womens'],
	['Osema', 'Fadhel', 'oscena', '398-765-4321', 'Loves sicily'],
	['Lorenzo', 'Nicotera', 'jadodfe', '098-765-4321', 'Loves Python'],
);

# Send the ADD commands
for my $i (0..$#contacts)
{
	my $contact = $contacts[$i];
	print color('bold green'), "🕺 Adding contact $i...\n", color('reset');
	print $pipe "ADD\n";
	for my $field (@$contact)
	{
		print $pipe "$field\n";
		sleep(0.9);
	}
}

# Send the SEARCH command for each index
for my $i (1..9)
{
	print color('bold green'), "🕺 Checking the SEARCH function for index $i...\n", color('reset');
	print $pipe "SEARCH\n";
	print $pipe "$i\n";
	sleep(1);
}

# Send the EXIT command
print color('bold green'), "🕺 Checking the EXIT function...\n", color('reset');
print $pipe "EXIT\n";

# Close the pipe
close($pipe) or warn color('bold red'), "Program exited with status $?\n", color('reset');

