#!/usr/bin/perl -w
use strict;

# test
my $inputfile =  shift( @ARGV );
my $outputfile0 = $inputfile.".out0";
my $outputfile1 = $inputfile.".out1";
my $outputfile2 = $inputfile.".out2";
my $outputfile3 = $inputfile.".out3";

open( IN,   "<$inputfile")   or die "Error: *E, $!: $inputfile\n";
open( OUT0, ">$outputfile0") or die "Error: *E, $!: $outputfile0\n";
open( OUT1, ">$outputfile1") or die "Error: *E, $!: $outputfile1\n";
open( OUT2, ">$outputfile2") or die "Error: *E, $!: $outputfile2\n";
open( OUT3, ">$outputfile3") or die "Error: *E, $!: $outputfile3\n";

binmode ( IN   );
binmode ( OUT0 );
binmode ( OUT1 );
binmode ( OUT2 );
binmode ( OUT3 );

my $byteCnt = 0;

for( my $i=0; $i<128; $i++ )
{
    printf OUT0 ( "%2d\n", 0 );
    printf OUT1 ( "%2d\n", 0 );
    printf OUT2 ( "%2d\n", 0 );
    printf OUT3 ( "%2d\n", 0 );
}

while (my $line = <IN>)
{
	$line =~ s/\r//;
	$line =~ s/\n//;

    my $strLen = length($line);
    #printf "length : %d\n", $strLen;

    my @array = split(//, $line );

    printf OUT0 ( "%s", $array[3] );
    printf OUT1 ( "%s", $array[2] );
    printf OUT2 ( "%s", $array[1] );
    printf OUT3 ( "%s", $array[0] );

    printf OUT0 ( "%s", $array[7] );
    printf OUT1 ( "%s", $array[6] );
    printf OUT2 ( "%s", $array[5] );
    printf OUT3 ( "%s", $array[4] );

    if( $byteCnt == 3 )
    {
        $byteCnt = 0;
        printf OUT0 ( "\n" );
        printf OUT1 ( "\n" );
        printf OUT2 ( "\n" );
        printf OUT3 ( "\n" );
    }
    else
    {
        $byteCnt++;
    }

	#printf OUT ( "%s\n" , unpack("H*", pack("B*", $line)) );
}

close ( IN   );
close ( OUT0 );
close ( OUT1 );
close ( OUT2 );
close ( OUT3 );

