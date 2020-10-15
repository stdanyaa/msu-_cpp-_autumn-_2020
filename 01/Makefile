C=g++
FLAGS=-std=c++17 -Wall -pedantic
all: test

test: tests.o Allocator.o
	$(C) $(FLAGS) -o test tests.o Allocator.o

tests.o: tests.cpp Allocator.cpp
	$(C) $(FLAGS) -c tests.cpp

Allocator.o: Allocator.cpp
	$(C) $(FLAGS) -c Allocator.cpp

clean:
	rm -rf test *.o