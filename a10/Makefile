CC=g++
OBJ=src/*.cpp
FLAGS=-Wall

all: __rb_trees clean

__rb_trees__debug:
	mkdir -p rb_trees/bin/debug
	$(CC) rb_trees/$(OBJ) -o rb_trees/bin/debug/main $(FLAGS) -g
	./rb_trees/bin/debug/main

__rb_trees:
	mkdir -p rb_trees/bin/release
	$(CC) rb_trees/$(OBJ) -o rb_trees/bin/release/main $(FLAGS) -O3
	./rb_trees/bin/release/main

clean:
	rm -rf rb_trees/bin
