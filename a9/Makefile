CC=g++
OBJ=src/*
FLAGS=-Wall

all: StackQueue BST clean

StackQueue:
	mkdir -p stack_and_queue/bin
	$(CC) stack_and_queue/$(OBJ) -o stack_and_queue/bin/main $(FLAGS) -O3
	./stack_and_queue/bin/main

BST:
	mkdir -p bst/bin
	$(CC) bst/$(OBJ) -o bst/bin/main $(FLAGS) -O3
	./bst/bin/main

clean:
	rm -rf stack_and_queue/bin bst/bin *.aux *.log
