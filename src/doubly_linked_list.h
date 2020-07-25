#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <stdlib.h>
#include <string.h>

typedef struct doubly_linked_node doubly_linked_node;
typedef struct doubly_linked_list doubly_linked_list;

void doubly_linked_list_insert_begining(doubly_linked_list *doubly_linked_list, char *value);
void doubly_linked_list_insert_end(doubly_linked_list *doubly_linked_list, char *value);
void doubly_linked_list_delete(doubly_linked_list *doubly_linked_list, char *value);
doubly_linked_node* doubly_linked_list_find(doubly_linked_list *doubly_linked_list, char *value);
void doubly_linked_list_traverse(doubly_linked_list *doubly_linked_list, void (*f) (doubly_linked_node *doubly_linked_node));

#endif
