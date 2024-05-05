#include <stdio.h>
#include <stdlib.h>

typedef int item_t;

typedef struct Qu_N
{
    item_t data;
    struct Qu_N* next;
    struct Qu_N* prev;
} Queue_Linked_D;


Queue_Linked_D* create_queue() {
    Queue_Linked_D* entrypoint = (Queue_Linked_D*)malloc(sizeof(Queue_Linked_D));
    entrypoint->next = entrypoint;
    entrypoint->prev = entrypoint;
    return entrypoint;
}

int empty(Queue_Linked_D* qu) {
    return qu->next == qu;
}

int push(Queue_Linked_D* qu, item_t x) {
    Queue_Linked_D* new_node = (Queue_Linked_D*)malloc(sizeof(Queue_Linked_D));
    new_node->data = x;
    new_node->next = qu->next;
    new_node->prev = qu;
    new_node->next->prev = new_node;
    qu->next = new_node;
}

item_t pop(Queue_Linked_D* qu) {
    Queue_Linked_D* back = qu->prev;
    item_t ret = back->data;
    back->prev->next = qu;
    qu->prev = back->prev;
    free(back);
    return ret;
}

item_t front(Queue_Linked_D* qu) {
    return qu->prev->data;
}

void remove_queue(Queue_Linked_D* qu) {
    Queue_Linked_D* tmp;
    qu->prev->next = NULL;
    do {
        tmp = qu->next;
        free(qu);
        qu = tmp;
    } while (qu != NULL);
}

int main(void) {
    Queue_Linked_D* qu = create_queue();
    for (int i = 1; i <= 20; ++i) push(qu, i);
    for (int i = 1; i <= 10; ++i) printf("%d ", pop(qu));
    for (int i = 201; i <= 230; ++i) push(qu, i);
    for (int i = 1; i <= 20; ++i) printf("%d ", pop(qu));
    remove_queue(qu);
}