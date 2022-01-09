CC=gcc
FLAGS = -Wall -g

all: graph library


graph: main.o graph.h lib.a
	$(CC) $(FLAGS) -o graph main.o lib.a

library: lib.a

main.o: main.c graph.h
	$(CC) $(FLAGS) -c main.c

GRAPH.o: GRAPH.c Queue.c
	$(CC) $(FLAGS) -c GRAPH.c

Queue.o: Queue.c
	$(CC) $(FLAGS) -c Qeueu.c

lib.a: GRAPH.o
	ar -rcs lib.a GRAPH.o

.PHONY: clean all
#make clean
clean:
	rm -f *.o *.a graph
