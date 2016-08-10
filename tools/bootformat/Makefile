TARGET = bootformat
OBJS = $(TARGET).o
SRCS = $(OBJS:.o=.c)
CC = -g -c

$(TARGET) : $(OBJS)
	gcc -o $@ $^
.c.o:
	gcc $(CC) $< 
dep:
	gccmakedep $(SRCS)
clean:
	rm -f *.o
