#include <stdio.h>
#include <stdlib.h>

typedef int item_t;

typedef struct Qu_N
{
    item_t data;
    struct Qu_N* next;
} Queue_Node;

typedef struct
{
    Queue_Node* rear;
    Queue_Node* front;
} Queue_List;

void init_queue(Queue_List* qu) {
    qu->front = NULL;
    qu->rear = NULL;
}

int empty(Queue_List* qu) {
    return qu->front == NULL;
}

int push(Queue_List* qu, item_t x) {
    Queue_Node* new_node = (Queue_Node*)malloc(sizeof(Queue_Node));
    new_node->data = x;
    new_node->next = NULL;
    if (qu->rear != NULL) {
        qu->rear->next = new_node;
        qu->rear = new_node;
    } else {
        qu->front = new_node;
        qu->rear = new_node;
    }
}

item_t pop(Queue_List* qu) {
    Queue_Node* tmp = qu->front;
    qu->front = tmp->next;
    if (qu->front == NULL) {
        qu->rear = NULL;
    }
    item_t ret = tmp->data;
    free(tmp);
    return ret;
}

void remove_queue(Queue_List* qu) {
    Queue_Node* cur = qu->front;
    Queue_Node* tmp;
    while (cur != NULL) {
        tmp = cur->next;
        free(cur);
        cur = tmp;
    }
}

int main(void) {
    Queue_List qu;
    init_queue(&qu);
    for (int i = 1; i <= 20; ++i) push(&qu, i);
    for (int i = 1; i <= 10; ++i) printf("%d ", pop(&qu));
    for (int i = 201; i <= 230; ++i) push(&qu, i);
    for (int i = 1; i <= 20; ++i) printf("%d ", pop(&qu));
    remove_queue(&qu);
}