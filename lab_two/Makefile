CC = gcc
CFLAGS = -Wall --std=c99
OBJECTS = main.o my_string.o

string_driver: $(OBJECTS)
	$(CC) $(CFLAGS) -o string_driver $^

main.o: main.c string.h
	$(CC) $(CFLAGS) -c $< -o $@

my_string.o: my_string.c string.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f string_driver $(OBJECTS)
