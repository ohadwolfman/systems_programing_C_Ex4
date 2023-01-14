CC = gcc
AR = ar -rcs
CFLAGS = -Wall -g

.PHONY: clean all

# Making the the Objects files
main.o: main.c graph.h
	$(CC) $(CFLAGS) -c main.c

# Making the main file
main: main.o
	$(CC) $(CFLAGS) main.o -o main -lm

all: main

clean:
	rm -f *.o *.a connections