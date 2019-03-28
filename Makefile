CC=gcc
CFLAGS=-I.
DEPS = riscv.h
OBJ = main.o riscv.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f ./*.o main

