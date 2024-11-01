CC=g++
OBJ=src/*
FLAGS=-Wall

all: prod graph

prod:
	mkdir -p build/prod
	$(CC) heap_sort/$(OBJ) -o build/prod/main $(FLAGS) -O3
	./build/prod/main 1000

graph:
	gnuplot -p heap_sort/results.plt

debug:
	mkdir -p build/debug
	$(CC) heap_sort/$(OBJ) -o build/debug/main $(FLAGS) -g -DDEBUG
	./build/debug/main

clean:
	rm -rf build/ *.aux *.log

