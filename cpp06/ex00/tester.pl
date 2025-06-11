#!/usr/bin/perl

use strict;
use warnings;
use Term::ANSIColor;

# Define test cases
my @error_cases = ("", "abc", "123 abc", "?", "ciao", "🦄");

my @valid_cases = ("0", "nan", "inf", "-inf", "42.0f", "3.14", "-3.14", "1.0e6", "-1.0e6",
                   "255", "-255", "128", "-128", "32767", "-32768");

my @additional_cases = ("127", "-128", "2147483647", "-2147483648", "9223372036854775807",
                        "-123", "3.4028235E+38", "-3.4028235E+38",
                        "-99.999999f", "9999.999f", "-9999.999f");

# Run the conversion program with test cases
sub run_test
{
	system("make");
    my ($input) = @_;
    print color('cyan'), "\nRunning ./convert '$input'\n", color('reset');
    system("./convert $input");
	sleep(1);
}

# Test error cases
print color('yellow'), "Testing error cases...\n", color('reset');
run_test($_) for @error_cases;

# Test valid cases
print color('green'), "Testing valid cases...\n", color('reset');
run_test($_) for @valid_cases;

# Test additional cases
 print color('blue'), "Testing additional cases...\n", color('reset');
 run_test($_) for @additional_cases;

# Cleanup
print color('magenta'), "\nCleaning up...\n", color('reset');
system("make fclean") == 0 or die "Failed to clean up\n";

print color('bright_green'), "All tests executed successfully!\n", color('reset');

