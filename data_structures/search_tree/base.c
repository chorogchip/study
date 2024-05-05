
#include <stdio.h>

typedef long long key_t;
typedef long long object_t;

typedef struct tr_n_t {
    key_t key;
    struct tr_n_t* left;
    struct tr_n_t* right;
} tree_node_t;

tree_node_t* create_tree(void) {
    tree_node_t* tmp_node;
    tmp_node = (tree_node_t*)malloc(sizeof(tree_node_t));
    tmp_node->left = NULL;
    return tmp_node;
}

void left_rotation(tree_node_t *n) {
    tree_node_t* tmp_node = n->left;
    key_t tmp_key = n->key;
    n->left = n->right;
    n->key = n->right->key;
    n->right = n->left->right;
    n->left->right = n->left->left;
    n->left->left = tmp_node;
    n->left->key = tmp_key;
}

void right_rotation(tree_node_t *n) {
    tree_node_t* tmp_node = n->right;
    key_t tmp_key = n->key;
    n->right = n->left;
    n->key = n->left->key;
    n->left = n->right->left;
    n->right->left = n->right->right;
    n->right->right = tmp_node;
    n->right->key = tmp_key;
}

object_t* fine(tree_node_t* tree, key_t query_key) {
    if (tree->left == NULL)
        return NULL;

    tree_node_t* tmp_node = tree;
    while (tmp_node->right != NULL) {
        if (query_key < tmp_node->key)
            tmp_node = tmp_node->left;
        else
            tmp_node = tmp_node->right;
    }
    if (tmp_node->key == query_key)
        return (object_t*)tmp_node->left;
    else
        return NULL;
}

int main(void) {

}