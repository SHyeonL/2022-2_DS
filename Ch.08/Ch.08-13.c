#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

#define SIZE 100
int top = -1;
TreeNode *stack[SIZE];

void push(TreeNode *p) {
    if (top < SIZE - 1)
        stack[++top] = p;
}

TreeNode *pop() {
    TreeNode *p = NULL;
    if (top >= 0)
        p = stack[top--];
    return p;
}

void inorder_iter(TreeNode *root) {
    while (1) {
        for (; root; root = root->left)
            push(root);
        root = pop();
        if (!root) break;
        printf("[%d] ", root->data);
        root = root->right;
    }
}

TreeNode test = {12, NULL, NULL};
TreeNode n0 = {33, &test, NULL};
TreeNode n1 = {1, &n0, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode *root = &n6;

int max(int a, int b) {
    if (a >= b)
        return a;
    else
        return b;
}

int balanced_tree(TreeNode *node) {
    int height_a = 0;
    int height_b = 0;
    int answer;
    TreeNode *temp;
    temp = node;
    if (node == NULL)
        return 1;
    else {
        while (node != NULL) {
            node = node->left;
            height_a++;
        }
        while (temp != NULL) {
            temp = temp->right;
            height_b++;
        }
    }

    if ((height_a - height_b) >= -1 && (height_a - height_b) <= 1) {
        answer = 1;
    } else {
        answer = 0;
    }
    return answer;
}

int main(void) {
    printf("중위 순회=");
    inorder_iter(root);
    printf("\n");
    int answer = 0;
    answer = balanced_tree(root);
    if (answer == 1)
        printf("균형 트리입니다.\n");
    else
        printf("균형 트리가 아닙니다.\n");
    return 0;
}