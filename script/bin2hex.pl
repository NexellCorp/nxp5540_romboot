#!/usr/bin/perl -w
use strict;

# test
my $inputfile =  shift( @ARGV );
my $outputfile = $inputfile.".out";

open( IN,  "<$inputfile") or die "Error: *E, $!: $inputfile\n";
open( OUT, ">$outputfile") or die "Error: *E, $!: $outputfile\n";
binmode( IN );
binmode (OUT );

while (my $line = <IN>)
{
	$line =~ s/\r//;
	$line =~ s/\n//;
	printf OUT ( "%s\n" , uc( unpack("H*", pack("B*", $line))) );
}

close (IN);
close (OUT);

