CXX = g++-8

CXXFLAGS = -g -Wall -std=c++17

LDLIBS = -lstdc++fs -pthread

tree-main: person.o

person.o:

.PHONY: clean
clean:
	rm -f *.o a.out tree-main core
