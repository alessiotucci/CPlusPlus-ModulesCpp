#!/usr/bin/perl
use strict;
use warnings;

# Define the command to run your program
my $command = './MyAwesomePhoneBook';

# Open a pipe to the command
open(my $pipe, '|-', $command) or die "Could not start $command: $!";

# Define the contacts
my @contacts = (
	['Alessio', 'Tucci', 'tuccio', '123-456-7890', 'Loves_Perl'],
	['Alfredo', 'Sines', 'af', '098-765-4321', 'Loves_C#'],
	['Venelin', 'Zashef', 'venny', '098-765-4321', 'Loves_Bulgaria'],
	['Flavio', 'Biondo', 'flavietto', '098-765-4321', 'Loves_PIng_pong'],
	['Ruggero', 'Dolzi', 'ruggy', '098-765-4321', 'Loves_IBM'],
	['Daniel', 'Ugzebu', 'youngbull', '098-765-4321', 'Loves womens'],
	['Osema', 'Fadhel', 'oscena', '398-765-4321', 'Loves sicily'],
	['Marco', 'Ciccio', 'jadodfe', '098-765-4321', 'Loves Python'],
	# Add more contacts here...
);

# Send the ADD commands
for my $contact (@contacts)
{
	print $pipe "ADD\n";
	for my $field (@$contact)
	{
		print $pipe "$field\n";
	}
}
# Send the PRINT command for each index
print $pipe "SEARCH\n";
print $pipe "1\n";
print $pipe "SEARCH\n";
print $pipe "2\n";
print $pipe "SEARCH\n";
print $pipe "3\n";
print $pipe "SEARCH\n";
print $pipe "4\n";
print $pipe "SEARCH\n";
print $pipe "5\n";
print $pipe "SEARCH\n";
print $pipe "6\n";
print $pipe "SEARCH\n";
print $pipe "7\n";
print $pipe "SEARCH\n";
print $pipe "8\n";
print $pipe "SEARCH\n";
print $pipe "9\n";

# Send the EXIT command
print $pipe "EXIT\n";

# Close the pipe
close($pipe) or warn "Program exited with status $?";

