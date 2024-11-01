CC=g++
OBJ=src/*
FLAGS=-Wall

all: sort plot

sort:
	mkdir -p build
	$(CC) -o build/sort selection_sort/$(OBJ) $(FLAGS)
	./build/sort 2500

plot:
	gnuplot -p selection_sort/results.plt

clean:
	rm -rf build
