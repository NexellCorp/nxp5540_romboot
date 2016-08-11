#!/usr/bin/perl -w
use strict;

# test
# maxLineCount : romcode 의 size 를 지정하면 input size 보다 큰 rom code 에 대해서 0을 채운다.
my $inputfile =  shift( @ARGV );
my $outputfile = shift( @ARGV );
my $maxLineCount =  shift( @ARGV );
#my $outputfile = $inputfile.".out";

open( IN,  "<$inputfile") or die "Error: *E, $!: $inputfile\n";
open( OUT, ">$outputfile") or die "Error: *E, $!: $outputfile\n";
binmode( IN );
binmode (OUT );

my $lineCount = 1;
while (my $line = <IN>)
{
	# DOS 개행문자 제거
	$line =~ s/\r//;
	$line =~ s/\n//;
	printf OUT ( "%08b\n" , hex($line) );
	$lineCount = $lineCount + 1;
}

while ( $lineCount <= $maxLineCount )
{
	if ( $lineCount == $maxLineCount ) { 
        printf OUT ( "%08b" , 0 ); 
    }
	else {
        printf OUT ( "%08b\n" , 0 );
    } 

	$lineCount = $lineCount+1;
}

close (IN);
close (OUT);

