#!/usr/bin/perl
use strict; use warnings;

  # 읽기용 파일을, 이진 모드로 열기
  open(FH, $ARGV[0]);
  printf($ARGV[0]);
  binmode FH;

  my($ss);
  my($print_retval);

  # 쓰기용 파일을, 텍스트 모드로 열기
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
