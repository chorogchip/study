#include <stdio.h>
#include <stdlib.h>

typedef int item_t;

typedef struct Qu_N
{
    item_t data;
    struct Qu_N* next;
} Queue_Linked_IM;


Queue_Linked_IM* create_queue() {
    Queue_Linked_IM* entrypoint = (Queue_Linked_IM*)malloc(sizeof(Queue_Linked_IM));
    Queue_Linked_IM* placeholder = (Queue_Linked_IM*)malloc(sizeof(Queue_Linked_IM));
    entrypoint->next = placeholder;
    placeholder->next = placeholder;
    return entrypoint;
}

int empty(Queue_Linked_IM* qu) {
    return qu->next == qu->next->next;
}

int push(Queue_Linked_IM* qu, item_t x) {
    Queue_Linked_IM* new_node = (Queue_Linked_IM*)malloc(sizeof(Queue_Linked_IM));
    new_node->data = x;
    Queue_Linked_IM* back = qu->next;
    qu->next = new_node;
    new_node->next = back->next;
    back->next = new_node;
}

item_t pop(Queue_Linked_IM* qu) {
    Queue_Linked_IM* front = qu->next->next->next;
    item_t ret = front->data;
    qu->next->next->next = front->next;
    if (front == qu->next) {
        qu->next = front->next;
    }
    free(front);
    return ret;
}

item_t front(Queue_Linked_IM* qu) {
    return qu->next->next->next->data;
}

void remove_queue(Queue_Linked_IM* qu) {
    Queue_Linked_IM* placeholder = qu->next->next;
    while (placeholder != qu->next) {
        qu->next->next = placeholder->next;
        free(placeholder);
        placeholder = qu->next->next;
    }
    free(placeholder);
    free(qu);
}

int main(void) {
    Queue_Linked_IM* qu = create_queue();
    for (int i = 1; i <= 20; ++i) push(qu, i);
    for (int i = 1; i <= 10; ++i) printf("%d ", pop(qu));
    for (int i = 201; i <= 230; ++i) push(qu, i);
    for (int i = 1; i <= 20; ++i) printf("%d ", pop(qu));
    remove_queue(qu);
}