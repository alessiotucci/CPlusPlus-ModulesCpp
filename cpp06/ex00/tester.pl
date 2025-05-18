#!/usr/bin/perl

use strict;
use warnings;
use Term::ANSIColor;

# Define test cases
my @error_cases = ("", "abc", "123 abc", " ", "1.2.3", "NULL", "NaN", "Infinity", "--42", "++42",
                   "0x1F", " 42", "42 ", "42 42", "hello", "42a", "a42", "9999999999999999999999",
                   "%^&*", "🦄");

my @valid_cases = ("0", "nan", "inf", "-inf", "42.0f", "3.14", "-3.14", "1.0e6", "-1.0e6",
                   "255", "-255", "128", "-128", "32767", "-32768", "2147483647", "-2147483648",
                   "1.7976931348623157E+308", "-1.7976931348623157E+308", "0.0");

my @additional_cases = ("127", "-128", "2147483647", "-2147483648", "9223372036854775807",
                        "-9223372036854775808", "3.4028235E+38", "-3.4028235E+38",
                        "0.00000001", "-0.00000001", "1e-10", "-1e-10", "2.2250738585072014E-308",
                        "-2.2250738585072014E-308", "256.256f", "-256.256f", "99.999999f",
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

