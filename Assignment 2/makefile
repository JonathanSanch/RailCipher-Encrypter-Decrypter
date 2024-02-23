CC=gcc
CFLAGS=-I. -g -w
DEPS= 
OBJ = main.o
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
railcipher: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)