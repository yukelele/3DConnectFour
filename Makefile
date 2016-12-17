CXX=g++

CXXFLAGS = -std=c++11 -Wall

all: main

main: main.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f *.o *~