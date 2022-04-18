# constants
CC = gcc # the compiler 
CFLAGS = -ansi -pedantic -Wall #compiler flags for exercises

lists_ab: lists_ab.o  
	$(CC) $(CFLAGS) lists_ab.o -o lists_ab
	

lists_ab.o: lists_ab.c
	$(CC) $(CFLAGS) -c lists_ab.c

clean:
	rm *.o 
