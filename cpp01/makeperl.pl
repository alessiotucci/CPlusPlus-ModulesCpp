#!/usr/bin/perl
use warnings;
use strict;
use Cwd;

# Get the current dir
my $dir = getcwd;

# Open the current dir 
opendir(DIR, $dir) or die "couldn't open dir $dir\n";

while (my $file = readdir(DIR))
{
	# Skip '.' and '..'
	next if ($file =~ m/^\./);
	
	# Construct full path
	my $full_path = "$dir/$file";
	
	if (-d $full_path)
	{
		chdir $full_path;
		system("make");
		system("make fclean");
		chdir $dir;
	}
}

closedir(DIR);

