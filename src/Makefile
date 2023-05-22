CC=g++
CFLAGS=-Wall -Werror -Wextra
BIN=../bin/

all: build

build: main.o funcs.o
	$(CC) $(CFLAGS) -o app main.o funcs.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

funcs.o: funcs.cpp
	$(CC) $(CFLAGS) -c funcs.cpp

lint:
	clang-format -n -style=Google --verbose *.cpp *.h

clean:
	rm -rf app *.o

run:
	./app

rebuild:
	make clean
	make all