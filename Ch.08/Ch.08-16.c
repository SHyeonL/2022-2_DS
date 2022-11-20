#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode test = {2, NULL, NULL};
TreeNode n1 = { 1,  &test, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode *root = &n6;

void inorder(TreeNode *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("[%d] ", root->data);
        inorder(root->right);
    }
}

int count = 0;
void one_child_node(TreeNode *p) {
    if (p != NULL) {
        if (p->left == NULL && p->right != NULL) count++;
        else if (p->left != NULL && p->right == NULL) count ++;
        one_child_node(p->left);
        one_child_node(p->right);
    }
}

int main(void) {
    printf("중위 순회=");
    inorder(root);
    printf("\n");
    one_child_node(root);
    printf("자식 노드가 하나만 있는 노드의 개수는 %d개입니다.", count);
    return 0;
}