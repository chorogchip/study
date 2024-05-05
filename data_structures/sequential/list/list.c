#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LOG(x) fwrite((x), sizeof(x), 1, stdout)

#define LINKED_LIST(Data)\
\
struct _Node_##Data {\
    struct _Node_##Data *next;\
    Data data;\
};\
typedef struct _Node_##Data Node_##Data;\
\
typedef struct {\
    Node_##Data *front;\
    Node_##Data *pool;\
    Node_##Data *empty_node;\
    int pool_size;\
    int pool_maxsize;\
} List_##Data;\
\
void list_init_##Data(List_##Data *list);\
void list_clear_##Data(List_##Data *list);\
Data *list_insert_##Data(List_##Data *list, Node_##Data **node);\
Node_##Data *list_remove_##Data(List_##Data *list, Node_##Data **node);\
void list_print_##Data(List_##Data *list);\
Node_##Data *list_malloc_##Data(List_##Data *list);\
void list_free_##Data(List_##Data *list, Node_##Data *node);\
\
void list_init_##Data(List_##Data *list)\
{\
    list->front = NULL;\
    list->pool_size = 0;\
    list->pool_maxsize = 1;\
    list->pool = (Node_##Data*)malloc(list->pool_maxsize * sizeof(Node_##Data));\
    list->empty_node = list->pool;\
    for (int i = 0; i < list->pool_maxsize; ++i)\
    {\
        list->pool[i].next = &list->pool[i + 1];\
    }\
    list->pool[list->pool_maxsize - 1].next = NULL;\
}\
void list_clear_##Data(List_##Data *list)\
{\
    list->front = NULL;\
    list->pool = NULL;\
    list->empty_node = NULL;\
    list->pool_size = 0;\
    list->pool_maxsize = 0;\
}\
Data *list_insert_##Data(List_##Data *list, Node_##Data **node)\
{\
    Node_##Data *const new_node = list_malloc_##Data(list);\
    new_node->next = *node;\
    *node = new_node;\
    return &new_node->data;\
}\
Node_##Data *list_remove_##Data(List_##Data *list, Node_##Data **node)\
{\
    Node_##Data *const next = (*node)->next;\
    list_free_##Data(list, *node);\
    *node = next;\
    return next;\
}\
void list_print_##Data(List_##Data *list)\
{\
    fwrite("list "#Data" data: ", 1, sizeof("list "#Data" data: "), stdout);\
    Node_##Data *next = list->front;\
    while (next != NULL)\
    {\
        print_##Data(&next->data);\
        next = next->next;\
    }\
    putchar('\n');\
}\
Node_##Data *list_malloc_##Data(List_##Data *list)\
{\
    if (list->empty_node == NULL)\
    {\
        int prev_size = list->pool_maxsize;\
        list->pool_maxsize <<= 1;\
        Node_##Data *new_pool = (Node_##Data*)realloc(list->pool, list->pool_maxsize * sizeof(Node_##Data));\
        if (new_pool != list->pool)\
        {\
            size_t mem_gap = (char*)new_pool - (char*)list->pool;\
            list->front = (Node_##Data*)((char*)list->front + mem_gap);\
            for (int i = 0; i < prev_size; ++i)\
                if (new_pool[i].next != NULL)\
                {\
                    new_pool[i].next = (Node_##Data*)((char*)new_pool[i].next + mem_gap);\
                }\
            list->pool = new_pool;\
        }\
        list->empty_node = &new_pool[prev_size];\
        for (int i = prev_size; i < list->pool_maxsize; ++i)\
        {\
            new_pool[i].next = &new_pool[i + 1];\
        }\
        new_pool[list->pool_maxsize - 1].next = NULL;\
    }\
    Node_##Data *ret = list->empty_node;\
    list->empty_node = list->empty_node->next;\
    ++list->pool_size;\
    return ret;\
}\
void list_free_##Data(List_##Data *list, Node_##Data *node)\
{\
    node->next = list->empty_node;\
    list->empty_node = node;\
    --list->pool_size;\
}

typedef struct {
    int num;
} Data;
void print_Data(Data *data)
{
    printf("%d ", data->num);
}
void print_int(int *data)
{
    printf("%d ", *data);
}

LINKED_LIST(Data)
LINKED_LIST(int)

int main(void)
{   
    List_Data list1;
    list_init_Data(&list1);
    list_insert_Data(&list1, &list1.front)->num = 1; 
    list_insert_Data(&list1, &list1.front)->num = 2; 
    list_insert_Data(&list1, &list1.front)->num = 3; 
    list_insert_Data(&list1, &list1.front)->num = 4; 
    list_insert_Data(&list1, &list1.front)->num = 5; 
    list_insert_Data(&list1, &list1.front->next)->num = 3; 
    list_print_Data(&list1); 
    list_remove_Data(&list1, &list1.front->next->next); 
    list_print_Data(&list1); 
    for (int i = 0; i < list1.pool_size; ++i)
        list1.pool[i].data.num += 10;
    list_print_Data(&list1); 
    list_clear_Data(&list1); 
    
    List_int list2;
    list_init_int(&list2);
    *list_insert_int(&list2, &list2.front) = 1;
    *list_insert_int(&list2, &list2.front) = 2;
    *list_insert_int(&list2, &list2.front->next) = 3;
    list_print_int(&list2);
    list_remove_int(&list2, &list2.front->next->next);
    list_print_int(&list2);
    list_remove_int(&list2, &list2.front);
    list_print_int(&list2);
    list_clear_int(&list2);
}
