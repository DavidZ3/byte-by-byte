CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror
TARGET = test_circular_buffer
SRC = circular_buffer.c test_circular_buffer.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $(SRC)

clean:
	rm -f $(TARGET) 