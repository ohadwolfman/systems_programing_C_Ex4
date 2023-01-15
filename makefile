CC = gcc
AR = ar -rcs
CFLAGS = -Wall -g

.PHONY: clean all

# Making the the Objects files
main.o: main.c graph.h
	$(CC) $(CFLAGS) -c main.c

graph.o: graph.c graph.h
	$(CC) $(CFLAGS) -c graph.c

# Making the main file
graph: main.o graph.o
	$(CC) $(CFLAGS) main.o  -o graph -lm

all: graph

clean:
	rm -f *.o *.a graph