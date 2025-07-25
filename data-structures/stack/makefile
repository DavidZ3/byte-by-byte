# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Targets
all: test

test: test.o stack.o
	$(CC) test.o stack.o -o test

test.o: test.c stack.h
	$(CC) $(CFLAGS) -c test.c -o test.o

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c -o stack.o

clean:
	rm -f *.o
