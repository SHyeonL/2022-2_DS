#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
    element key;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode *root = NULL;

TreeNode *new_node(int item) {
    TreeNode *temp = (TreeNode *) malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode *insert_node(TreeNode *node, int key) {
    if (node == NULL) return new_node(key);

    if (key < node->key)
        node->left = insert_node(node->left, key);
    else if (key > node->key)
        node->right = insert_node(node->right, key);

    return node;
}

void inorder(TreeNode *root) {
    if (root) {
        inorder(root->left);
        printf("[%d] ", root->key);
        inorder(root->right);
    }
}

void insert_array(int* key) {
    for(int i = 0; i < 11; i++) {
        root = insert_node(root, key[i]);
    }
}

int main(void) {

    int array[11] = {11, 3, 4, 1, 56, 5, 6, 2, 98, 32, 23};
    insert_array(array);
    printf("이진 탐색 트리 중위 순회 결과\n");
    inorder(root);
    free(root);
    return 0;
}