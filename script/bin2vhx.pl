#!/usr/bin/perl
use strict; use warnings;

  # �б�� ������, ���� ���� ����
  open(FH, $ARGV[0]);
  printf($ARGV[0]);
  binmode FH;

  my($ss);
  my($print_retval);

  # ����� ������, �ؽ�Ʈ ���� ����
  open(TEXT, ">$ARGV[1]");
  printf($ARGV[1]);

  while (read FH, $_, 1) {
	  $ss = sprintf("%02X\n", ord($_));
      print TEXT  $ss;

	  $print_retval = $?;
      if($print_retval != 0)
      {
    	print "ERROR on print to FILE..";
    	exit(-1);
      }
  }

  close FH;
  close TEXT;
