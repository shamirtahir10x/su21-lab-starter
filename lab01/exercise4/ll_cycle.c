#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    /* TODO: Implement ll_has_cycle */
    node *slow_ptr = head;
    node *fast_ptr = head;

    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;

        // cyclic
        if (fast_ptr == slow_ptr) {
            return 1;
        }
    }

    // acyclic
    return 0;
}
