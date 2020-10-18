CXX=g++
FLAGS=-std=c++17 -Wall -pedantic
# all: test


test: tests.o Allocator.o
	$(CXX) $(FLAGS) -o test tests.o Allocator.o
	./test

tests.o: tests.cpp
	$(CXX) $(FLAGS) -c tests.cpp

Allocator.o: Allocator.cpp
	$(CXX) $(FLAGS) -c Allocator.cpp

clean:
	rm -rf test *.o