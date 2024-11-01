CC=g++
OBJ=src/*.cpp
FLAGS=-Wall

all: __hash_map __greedy clean

__hash_map__debug:
	mkdir -p hash_map/bin/debug 
	$(CC) hash_map/$(OBJ) -o hash_map/bin/debug/main -DDEBUG -g
	./hash_map/bin/debug/main

__hash_map:
	mkdir -p hash_map/bin/release 
	$(CC) hash_map/$(OBJ) -o hash_map/bin/release/main -O3
	./hash_map/bin/release/main


__greedy__debug:
	mkdir -p greedy/bin/debug 
	$(CC) greedy/$(OBJ) -o greedy/bin/debug/main -DDEBUG -g
	./greedy/bin/debug/main

__greedy:
	mkdir -p greedy/bin/release 
	$(CC) greedy/$(OBJ) -o greedy/bin/release/main -O3
	./greedy/bin/release/main


clean:
	rm -rf hash_map/bin/* greedy/bin/*
