CC=gcc
CFLAGS=-I.
DEPS = cfslib.h
OBJ = cfs.o wget.o filter.o help.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cfs: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f ${OBJ}
