#!/usr/bin/perl
use strict;
use warnings;
use Term::ANSIColor;
use Time::HiRes qw(usleep);

# The name of the second file
my $file2 = 'my_test.log';

# Check if the second file exists
if (!-e $file2)
{
	# Try to run the Account executable
	if (-x 'Account')
	{
		system('./Account > ' . $file2);
	}
	else
	{
		# Try to compile the program
		system('make re');
		# Check if the Account executable exists now
		if (-x 'Account')
		{
			system('./Account > ' . $file2);
		}
		else
		{
			die "Could not find or create the Account executable";
		}
	}
}

# Open the two files
open my $fh1, '<', '19920104_091532.log' or die "Could not open file1.txt: $!";
open my $fh2, '<', $file2 or die "Could not open file2.txt: $!";

while (my $line1 = <$fh1>)
{
	my $line2 = <$fh2>;

	# Remove the timestamp from the lines
	$line1 =~ s/\[\d{8}_\d{6}\] //;
	$line2 =~ s/\[\d{8}_\d{6}\] //;

	# Compare the lines and print a green check emoji if they match
	if ($line1 eq $line2)
	{
		print color('green'), "✔ ", color('reset'), "$line1";
	}
	else
	{
		print color('red'), "✘ ", color('reset'), "$line1";
	}
	# Add a small delay after each line
	usleep(100000);  # 100 milliseconds
}

# Close the files
close $fh1;
close $fh2;

# Clean up
system('make fclean');
unlink $file2;

