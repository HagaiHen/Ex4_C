CC=gcc
FLAGS= -Wall -g

#make all
all: graph

.PHONY: clean
#make clean
clean:
	rm -f *.o *.a *.so

graph: graph.o main.o
	$(CC) $(FLAGS) -o Edge.c Node.c Queue.c main.c

main.o: main.c
	$(CC) $(FLAGS) -c main.c

Node.o: Node.c
	$(CC) $(FLAGS) -c Node.c

Edge.o: Edge.c
	$(CC) $(FLAGS) -c Edge.o

Queue.o: Queue.c
	$(CC) $(FLAGS) -c Queue.c

Algo.o: Algo.c
	$(CC) $(FLAGS) -c Algo.c

graph.o: graph.h Edge.o Node.o Queue.o Algo.o
	$(CC) $(FLAGS) -c Algo.c
