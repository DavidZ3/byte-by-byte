# Compliler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Targets
all: test

test: test.o queue.o
	$(CC) test.o queue.o -o test

test.o: test.c queue.h
	$(CC) $(CFLAGS) -c test.c -o test.o

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c -o queue.o

clean:
	rm -f *.o
