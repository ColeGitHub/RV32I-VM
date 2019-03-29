CC=gcc
CFLAGS=-I.
SOURCES = $(wildcard *.c)
DEPS = $(wildcard *.h)
OBJ = $(SOURCES:.c=.o) 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f ./*.o main

