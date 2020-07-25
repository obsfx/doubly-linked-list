CC=gcc
CFLAGS=-Wall \
	   -Wextra \
	   -std=c89 \
	   -pedantic \
	   -O3 \

output: main.o doubly_linked_list.o
	gcc ./src/main.o ./src/doubly_linked_list.o -o main $(CFLAGS)

main.o: ./src/main.c
	gcc -c ./src/main.c -o ./src/main.o

doubly_linked_list.o: ./src/doubly_linked_list.c ./src/doubly_linked_list.h
	gcc -c ./src/doubly_linked_list.c -o ./src/doubly_linked_list.o
