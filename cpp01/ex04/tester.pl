#!/usr/bin/perl
use strict;
use warnings;
use Term::ANSIColor;

# Define the program and the arguments
my $program = "./Sed_is_for_losers";
my @filenames = ("file.txt", "non_existent_file.txt", "practice.txt", "empty.txt");
my @targets = ("lorem", "target2", "practice", "x");
my @replacements = ("HELLO", "replacement2", "PRACTICE", "not");

# Test with different files
for my $i (0..$#filenames)
{
	print color('bold blue'), "🔍 Testing with file $filenames[$i]...\n", color('reset');
	print ("$program $filenames[$i] $targets[$i] $replacements[$i]...\n");
	system("$program $filenames[$i] $targets[$i] $replacements[$i]");
}
print color('bold green'), "✅ Done.\n", color('reset');
system("cat *.txt");
print ("-----------------------------------------------------\n");
system("cat *.replace");
