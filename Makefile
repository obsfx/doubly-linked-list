CC=gcc
CFLAGS=-Wall \
	   -Wextra \
	   -std=c89 \
	   -pedantic \
	   -O3 \

output: test.o doubly_linked_list.o
	gcc ./test/test.o ./src/doubly_linked_list.o -o test $(CFLAGS)

test.o: ./test/test.c
	gcc -c ./test/test.c -o ./test/test.o

doubly_linked_list.o: ./src/doubly_linked_list.c ./src/doubly_linked_list.h
	gcc -c ./src/doubly_linked_list.c -o ./src/doubly_linked_list.o
