CC=gcc
CFLAGS=-g -Wall -Wextra -std=c11
SRCS=main.c bst.c
OBJS=$(SRCS:.c=.o)
TARGET=dic

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c bst.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(TARGET) $(OBJS)
