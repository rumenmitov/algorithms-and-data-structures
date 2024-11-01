CC=g++
OBJ=src/*
FLAGS=-Wall

all: release clean

debug:
	mkdir -p build/debug
	$(CC) -o build/debug/main quick_sort/$(OBJ) $(FLAGS) -g -DDEBUG
	./build/debug/main

release:
	mkdir -p build/release
	$(CC) -o build/release/main quick_sort/$(OBJ) $(FLAGS) -O3
	./build/release/main

clean:
	rm -rf build/ *.aux *.log


