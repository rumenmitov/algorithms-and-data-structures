CC=g++
OBJ=src/*
FLAGS=-Wall

all: using_lists using_deques another_deque reversing_vector lotto using_maps

using_lists:
	mkdir -p build
	$(CC) -o build/p1 p1/$(OBJ) $(FLAGS)
	./build/p1

using_deques:
	mkdir -p build
	$(CC) -o build/p2 p2/$(OBJ) $(FLAGS)
	./build/p2

another_deque:
	mkdir -p build
	$(CC) -o build/p3 p3/$(OBJ) $(FLAGS)
	./build/p3

reversing_vector:
	mkdir -p build
	$(CC) -o build/p4 p4/$(OBJ) $(FLAGS)
	./build/p4

lotto:
	mkdir -p build
	$(CC) -o build/p5 p5/$(OBJ) $(FLAGS)
	./build/p5

using_maps:
	mkdir -p build
	$(CC) -o build/p6 p6/$(OBJ) $(FLAGS)
	./build/p6


clean:
	rm -rf build/
