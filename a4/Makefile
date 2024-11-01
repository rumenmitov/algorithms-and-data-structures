CC=g++
OBJ=src/*
FLAGS=-Wall

all: merge_sort plot

merge_sort:
	mkdir -p build/release
	$(CC) -o build/release/p1 p1/$(OBJ) $(FLAGS) -O3
	./build/release/p1 2000

debug:
	mkdir -p build/debug
	$(CC) -o build/debug/p1 p1/$(OBJ) $(FLAGS) -DDEBUG -g
	./build/debug/p1 1000

plot:
	gnuplot -p p1/result.plt

clean:
	rm -rf build hw.log hw.aux
