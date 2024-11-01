CC=g++
OBJ=src/*.cpp
FLAGS=-Wall

all: __longest_subarray triangle_sum clean

__longest_subarray_debug:
	mkdir -p longest_subarray/bin/debug
	$(CC) $(FLAGS) longest_subarray/$(OBJ) -o longest_subarray/bin/debug/main -g
	./longest_subarray/bin/debug/main

__longest_subarray:
	mkdir -p longest_subarray/bin/release
	$(CC) $(FLAGS) longest_subarray/$(OBJ) -o longest_subarray/bin/release/main -O3
	./longest_subarray/bin/release/main

__triangle_sum_debug:
	mkdir -p triangle_sum/bin/debug
	$(CC) $(FLAGS) triangle_sum/$(OBJ) -o triangle_sum/bin/debug/main -g
	./triangle_sum/bin/debug/main

__triangle_sum:
	mkdir -p triangle_sum/bin/release
	$(CC) $(FLAGS) triangle_sum/$(OBJ) -o triangle_sum/bin/release/main -O3
	./triangle_sum/bin/release/main

clean:
	rm -rf longest_subarray/bin
	rm -rf triangle_sum/bin
