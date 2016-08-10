TARGET = nandboot_bingen
OBJS = $(TARGET).o
SRCS = $(OBJS:.o=.c)
CC = -I/home/ubuntu/usr/include	-g -c

$(TARGET) : $(OBJS)
	gcc -o $@ $^
.c.o:
	gcc $(CC) $< 
dep:
	gccmakedep $(SRCS)
clean:
	rm -f *.o
