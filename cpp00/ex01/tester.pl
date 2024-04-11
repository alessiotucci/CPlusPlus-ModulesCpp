#!/usr/bin/perl
use strict;
use warnings;

# Define the command to run your program
my $command = './MyAwesomePhoneBook';

# Open a pipe to the command
open(my $pipe, '|-', $command) or die "Could not start $command: $!";

# Define the contacts
my @contacts = (
	['Alessio', 'Tucci', 'tuccio', '123-456-7890', 'Loves Perl'],
	['Alfred', 'Sines', 'afly', '098-765-4321', 'Loves C#'],
	['Venelin', 'Zashef', 'venny', '098-765-4321', 'Loves Bulgaria'],
	['Flavio', 'Biondo', 'flavietto', '098-765-4321', 'Loves PIng pong'],
	['Ruggero', 'Dolzi', 'ruggy', '098-765-4321', 'Loves IBM'],
	['Daniel', 'Ugzebu', 'young bull', '098-765-4321', 'Loves womens'],
	['Osema', 'Fadhesl', 'osena', '098-765-4321', 'Loves sicily'],
	['Fadhtes', 'Ciccio', 'jadodfe', '098-765-4321', 'Loves Python'],
	# Add more contacts here...
);

# Send the ADD commands
for my $contact (@contacts) {
    print $pipe "ADD\n";
    for my $field (@$contact) {
        print $pipe "$field\n";
    }
}

# Send the SEARCH command
print $pipe "SEARCH\n";

# Send the EXIT command
print $pipe "EXIT\n";

# Close the pipe
close($pipe) or warn "Program exited with status $?";

