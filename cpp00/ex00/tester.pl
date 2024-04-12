#!/usr/bin/perl
use strict;
use warnings;
use Term::ANSIColor;
use Time::HiRes;

# Define the test strings
my @test_strings = (
	['shhhhh... I think the students are asleep...'],
	['Damnit', ' ! ', 'Sorry students, I thought this thing was off.'],
	['']
);

# Function to test the megaphone executable
sub test_megaphone
{
	my $test_string = shift;
	if (-x 'megaphone')
	{
		system('./megaphone', @$test_string);
	}
	else
	{
		# Try to compile the program
		system('make re');
		# Check if the megaphone executable exists now
		if (-x 'megaphone')
		{
			system('./megaphone', @$test_string);
		}
		else
		{
			die "Could not find or create the megaphone executable";
		}
	}
}

# Run the tests
for my $test_string (@test_strings)
{
	test_megaphone($test_string);
	# Add a small delay after each line
	sleep(1);  # 100 milliseconds
}

