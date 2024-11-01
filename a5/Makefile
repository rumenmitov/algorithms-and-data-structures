CC=g++
OBJ=src/*
FLAGS=-Wall

all: build plot

build:
	mkdir -p build/bin
	$(CC) fib/$(OBJ) -o build/bin/main $(FLAGS) -O3
	./build/bin/main

plot:
	gnuplot -p fib/results.plt

debug:
	mkdir -p build/debug
	$(CC) fib/$(OBJ) -o build/debug/main $(FLAGS) -DDEBUG -g
	./build/debug/main

clean:
	rm -rf build *.log *.aux
