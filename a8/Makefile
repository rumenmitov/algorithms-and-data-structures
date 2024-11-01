CC=g++
OBJ=src/*
FLAGS=-Wall

all: prod clean

debug:
	mkdir -p bin/debug
	$(CC) -o bin/debug/main sort/$(OBJ) $(FLAGS) -g -DDEBUG
	./bin/debug/main


prod:
	mkdir -p bin/prod
	$(CC) -o bin/prod/main sort/$(OBJ) $(FLAGS) -O3
	./bin/prod/main

clean:
	rm -rf bin *.aux *.log

