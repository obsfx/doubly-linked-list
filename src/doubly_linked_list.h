#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <stdlib.h>
#include <string.h>

typedef struct doubly_linked_node doubly_linked_node;
typedef struct doubly_linked_list doubly_linked_list;

struct doubly_linked_node {
    doubly_linked_node *prev_node_ptr;
    doubly_linked_node *next_node_ptr;
    char *value;
};

struct doubly_linked_list {
    doubly_linked_node *first_node_ptr;
    doubly_linked_node *last_node_ptr;
};

int get_strlen(char *value);

void doubly_linked_list_insert_begining(doubly_linked_list *doubly_linked_list, char *value);
void doubly_linked_list_insert_end(doubly_linked_list *doubly_linked_list, char *value);
void doubly_linked_list_delete(doubly_linked_list *doubly_linked_list, char *value);
doubly_linked_node* doubly_linked_list_find(doubly_linked_list *doubly_linked_list, char *value);
void doubly_linked_list_traverse_forward(doubly_linked_list *doubly_linked_list, void (*f) (doubly_linked_node *doubly_linked_node));
void doubly_linked_list_traverse_backward(doubly_linked_list *doubly_linked_list, void (*f) (doubly_linked_node *doubly_linked_node));

#endif
