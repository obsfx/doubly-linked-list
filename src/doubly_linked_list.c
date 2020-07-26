#include "doubly_linked_list.h"

/**
 * get_strlen;
 * custom strlen function to find
 * char* len without pain
 */
int get_strlen(char *value) {
    int len = 0;

    while (*(value + len) != '\0') {
        len++;
    }

    /**
     * +1 for null terminator;
     */
    return ++len;
}

/*
 * doubly_linked_list_insert_begining;
 * inserting new node at the begining of the list;
 */
void doubly_linked_list_insert_begining(doubly_linked_list *doubly_linked_list, char *value) {
    /**
     * allocating memory for our new node
     */
    doubly_linked_node *new_node = malloc(sizeof(doubly_linked_node));

    /**
     * when we insert the new node at the begining of list,
     * current first node of list will become the next element of our new node.
     * so we are assigning that value as next_node_ptr of our new node before
     * changing the firs_node_ptr of our list
     */
    new_node->next_node_ptr = doubly_linked_list->first_node_ptr;

    /**
     * our new node will become the first node of our list. there is
     * no other element before our node so we are assigning the prev_node_ptr
     * to a NULL ptr.
     */
    new_node->prev_node_ptr = NULL;

    /**
     * allocating proper memory space for our value section by using
     * our get_strlen helper method.
     */
    new_node->value = malloc(sizeof(char) * get_strlen(value));

    /**
     * our value section is an char ptr. char pointers actually just points to
     * the first charecter of the whole string. so we cant directly assign
     * the value argument to the value section of our node. 
     *
     * memcpy copies the memory section where every char sequentially ordered to our
     * new node's value section.
     */
    memcpy(new_node->value, value, sizeof(char) * get_strlen(value));

    /**
     * if there already exists first node, we are just 
     * assigning its prev_node_ptr to our new node.
     * Because it is not anymore the first node of the list.
     * It will come after out new node.
     */
    if (doubly_linked_list->first_node_ptr != NULL) {
        doubly_linked_list->first_node_ptr->prev_node_ptr = new_node;
    }

    /**
     * replacing the first node with our new node
     */
    doubly_linked_list->first_node_ptr = new_node;

    /**
     * if there is no last node that have not already assigned, this means our new node
     * is the first appended element of our list and at the same time it is the last element 
     * of our list.
     */
    if (doubly_linked_list->last_node_ptr == NULL) {
        doubly_linked_list->last_node_ptr = new_node;
    }
}

void doubly_linked_list_insert_end(doubly_linked_list *doubly_linked_list, char *value) {
    /**
     * same things as like doubly_linked_list_insert_begining
     */
    doubly_linked_node *new_node = malloc(sizeof(doubly_linked_node));

    new_node->next_node_ptr = NULL;
    new_node->prev_node_ptr = doubly_linked_list->last_node_ptr;

    new_node->value = malloc(sizeof(char) * get_strlen(value));
    memcpy(new_node->value, value, sizeof(char) * get_strlen(value));

    if (doubly_linked_list->last_node_ptr != NULL) {
        doubly_linked_list->last_node_ptr->next_node_ptr = new_node;
    }

    doubly_linked_list->last_node_ptr = new_node;

    if (doubly_linked_list->first_node_ptr == NULL) {
        doubly_linked_list->first_node_ptr = new_node;
    }
}

/**
 * if current_node_ptr is not a null pointer, just keep the iterating.
 * at the end of the loop replace our current_node_ptr with the next_node_ptr || prev_node_ptr;
 */

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

void doubly_linked_list_traverse_forward(doubly_linked_list *doubly_linked_list, void (*f) (doubly_linked_node *doubly_linked_node)) {
    doubly_linked_node *current_node_ptr = doubly_linked_list->first_node_ptr;

    while (current_node_ptr != NULL) {
        (*f) (current_node_ptr);

        current_node_ptr = current_node_ptr->next_node_ptr;
    }
}

void doubly_linked_list_traverse_backward(doubly_linked_list *doubly_linked_list, void (*f) (doubly_linked_node *doubly_linked_node)) {
    doubly_linked_node *current_node_ptr = doubly_linked_list->last_node_ptr;

    while (current_node_ptr != NULL) {
        (*f) (current_node_ptr);

        current_node_ptr = current_node_ptr->prev_node_ptr;
    }
}
