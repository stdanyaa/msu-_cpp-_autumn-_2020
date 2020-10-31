CXX=g++
FLAGS=-std=c++17 -Wall -pedantic

all: tests

tests: tests.o TokenParser.o
	$(CXX) $(FLAGS) -o tests tests.o TokenParser.o

tests.o: tests.cpp
	$(CXX) $(FLAGS) -c tests.cpp

TokenParser.o: TokenParser.cpp TokenParser.h
	$(CXX) $(FLAGS) -c TokenParser.cpp

clean:
	rm -rf test *.o

run:
	./tests

test: run