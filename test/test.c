#include <stdio.h>
#include "./../src/doubly_linked_list.h"

void print_current_node(doubly_linked_node *doubly_linked_node);

int main() {
    doubly_linked_node *found_node;

    doubly_linked_list city_list;

    city_list.first_node_ptr = NULL;
    city_list.last_node_ptr = NULL;

    printf("\n //////// insert begining");
    doubly_linked_list_insert_begining(&city_list, "4 - Berlin");
    doubly_linked_list_insert_begining(&city_list, "3 - Zurich");
    doubly_linked_list_insert_begining(&city_list, "2 - Istanbul");
    doubly_linked_list_insert_begining(&city_list, "1 - Ankara");

    printf("\n          traverse forward");
    doubly_linked_list_traverse_forward(&city_list, print_current_node);
    printf("\n");

    printf("\n          traverse backward");
    doubly_linked_list_traverse_backward(&city_list, print_current_node);
    printf("\n");

    printf("\n //////// insert end");

    doubly_linked_list_insert_end(&city_list, "5 - Paris");
    doubly_linked_list_insert_end(&city_list, "6 - Bucharest");
    doubly_linked_list_insert_end(&city_list, "7 - London");
    doubly_linked_list_insert_end(&city_list, "8 - Nowhere");

    printf("\n          traverse forward");
    doubly_linked_list_traverse_forward(&city_list, print_current_node);
    printf("\n");

    printf("\n          traverse backward");
    doubly_linked_list_traverse_backward(&city_list, print_current_node);
    printf("\n");

    printf("\n          find: 5 - Paris");
    found_node = doubly_linked_list_find(&city_list, "5 - Paris");
    if (found_node != NULL) {
        printf("\n          found value: %s", found_node->value);

        if (found_node->prev_node_ptr != NULL) {
            printf("\n          prev node value: %s", found_node->prev_node_ptr->value);
        }

        if (found_node->next_node_ptr != NULL) {
            printf("\n          next node value: %s", found_node->next_node_ptr->value);
        }
    }

    printf("\n\n          delete: 5 - Paris");
    found_node = doubly_linked_list_find(&city_list, "5 - Paris");
    doubly_linked_list_delete(&city_list, "5 - Paris");

    printf("\n");
    doubly_linked_list_traverse_forward(&city_list, print_current_node);

    printf("\n");
    doubly_linked_list_traverse_backward(&city_list, print_current_node);

    return 0;
}

void print_current_node(doubly_linked_node *doubly_linked_node) {
    printf("\n %s ", doubly_linked_node->value);
}
