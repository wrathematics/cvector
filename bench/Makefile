CC = gcc
CXX = g++
CFLAGS = -O3 -Wall -pedantic
CXXFLAGS = -O3 -Wall -pedantic

all: cbench cxxbench

c:
	$(CC) $(CFLAGS) cbench.c -o cbench

cxx:
	$(CXX) $(CXXFLAGS) cxxbench.c -o cxxbench

clean:
	rm -f cbench cxxbench
