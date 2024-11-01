CC=g++
OBJ=src/*
FLAGS=-Wall

all: generics stack list vectorI vectorII

generics:
	mkdir -p build
	$(CC) -o build/p1 p1/$(OBJ) $(FLAGS)
	./build/p1

stack:
	mkdir -p build
	$(CC) -o build/p2 p2/$(OBJ) $(FLAGS)
	./build/p2

list:
	mkdir -p build
	$(CC) -o build/p3 p3/$(OBJ) $(FLAGS)
	./build/p3

vectorI:
	mkdir -p build
	$(CC) -o build/p4 p4/$(OBJ) $(FLAGS)
	./build/p4

vectorII:
	mkdir -p build
	$(CC) -o build/p5 p5/$(OBJ) $(FLAGS)
	./build/p5

clean:
	rm -rf build/
