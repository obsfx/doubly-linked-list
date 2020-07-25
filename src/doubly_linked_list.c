#include "doubly_linked_list.h"

struct doubly_linked_node {
    doubly_linked_node *prev_node_ptr;
    doubly_linked_node *next_node_ptr;
    char *value;
};

struct doubly_linked_list {
    doubly_linked_node *first_node_ptr;
    doubly_linked_node *last_node_ptr;
};

void doubly_linked_list_insert_begining(doubly_linked_list *doubly_linked_list, char *value) {
    doubly_linked_node new_node;

    new_node.next_node_ptr = doubly_linked_list->first_node_ptr;
    new_node.prev_node_ptr = NULL;
    memcpy(new_node.value, value, strlen(value));

    doubly_linked_list->first_node_ptr = &new_node;
}

void doubly_linked_list_insert_end(doubly_linked_list *doubly_linked_list, char *value) {
    doubly_linked_node new_node;

    new_node.next_node_ptr = NULL;
    new_node.prev_node_ptr = doubly_linked_list->last_node_ptr;
    memcpy(new_node.value, value, strlen(value));

    doubly_linked_list->last_node_ptr = &new_node;
}

void doubly_linked_list_delete(doubly_linked_list *doubly_linked_list, char *value)  {
    doubly_linked_node *current_node_ptr = doubly_linked_list->first_node_ptr;

    while (current_node_ptr != NULL) {
        if (strcmp(current_node_ptr->value, value) == 0) {
            current_node_ptr->prev_node_ptr->next_node_ptr = current_node_ptr->next_node_ptr;
            current_node_ptr->next_node_ptr->prev_node_ptr = current_node_ptr->prev_node_ptr;

            free(current_node_ptr);
            current_node_ptr = NULL;
            return;
        }

        current_node_ptr = current_node_ptr->next_node_ptr;
    }
}

doubly_linked_node* doubly_linked_list_find(doubly_linked_list *doubly_linked_list, char *value) {
    doubly_linked_node *current_node_ptr = doubly_linked_list->first_node_ptr;

    while (current_node_ptr != NULL) {
        if (strcmp(current_node_ptr->value, value) == 0) {
            return current_node_ptr;
        }

        current_node_ptr = current_node_ptr->next_node_ptr;
    }

    return NULL;
}

void doubly_linked_list_traverse(doubly_linked_list *doubly_linked_list, void (*f) (doubly_linked_node *doubly_linked_node)) {
    doubly_linked_node *current_node_ptr = doubly_linked_list->first_node_ptr;

    while (current_node_ptr != NULL) {
        (*f) (current_node_ptr);

        current_node_ptr = current_node_ptr->next_node_ptr;
    }
}
