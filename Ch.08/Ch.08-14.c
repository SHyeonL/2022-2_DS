#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;
//		  15
//	   4	 20
//    1	   16  25
TreeNode n1 = { 1,  NULL, NULL };
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

void preorder(TreeNode *root) {
    if (root != NULL) {
        printf("[%d] ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TreeNode *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("[%d] ", root->data);
    }
}

int sum_of_tree(TreeNode *p) {
    if (p == NULL) return 0;
    if (p->left == NULL && p->right == NULL) return p->data;
    else {
        return (p->data + sum_of_tree(p->left) + sum_of_tree(p->right));
    }
}

int main(void) {
    printf("중위 순회=");
    inorder(root);
    printf("\n");
    int sum = sum_of_tree(root);
    printf("노드의 합은 %d입니다.", sum);
    return 0;
}