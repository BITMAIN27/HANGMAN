CC = gcc
CFLAGS = -g -Wall --std=c99
OBJECTS = main.o

hello:$(OBJECTS)
	$(CC) $(CFLAGS) -o hello $(OBJECTS)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o
clean:
	rm hello $(OBJECTS)
