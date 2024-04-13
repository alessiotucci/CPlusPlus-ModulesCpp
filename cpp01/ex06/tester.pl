#!/usr/bin/perl
use strict;
use warnings;
use Term::ANSIColor;

# Define the program and the arguments
my $program = "./harlFilter";
my @param = ("DEBUG", "INFO", "WARNING", "ERROR");

# Test with different files
for my $i (0..$#param)
{
	print color('bold blue'), "🔍 Testing with $param[$i]...\n", color('reset');
	print ("$program $param[$i]\n");
	system("$program $param[$i]");
	sleep(1);
	print ("-----------------------------------------------------------\n");
}

print ("$program 'I am not sure how tired I am today...'\n");
system("$program 'I am not sure how tired I am today...'");

print color('bold green'), "✅ Done.\n", color('reset');

