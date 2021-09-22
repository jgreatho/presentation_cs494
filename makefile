EXECUTABLES = bin/pancake

CFLAGS ?= -Wall -Wextra -std=c++98

all: $(EXECUTABLES)

clean:
	rm -f a.out bin/*

bin/pancake: RandomPancakeStack.cpp expectedDeliciousness.cpp
	g++ $(CFLAGS) -o bin/pancake RandomPancakeStack.cpp expectedDeliciousness.cpp
