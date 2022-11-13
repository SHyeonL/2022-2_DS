#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

void print_list(ListNode *head) {
    ListNode *p;

    if (head == NULL) return;
    p = head->link;
    do {
        printf("%d->", p->data);
        p = p->link;
    } while (p != head);
    printf("%d->", p->data);
    printf("\n");
}

ListNode *insert_first(ListNode *head, element data) {
    ListNode *node = (ListNode *) malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    } else {
        node->link = head->link;
        head->link = node;
    }
    return head;
}

ListNode *insert_last(ListNode *head, element data) {
    ListNode *node = (ListNode *) malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    } else {
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

ListNode *delete_first(ListNode *head)
{
    if (head == NULL) {
        printf("삭제 오류");
        return 0;
    } else {
        ListNode *node = (ListNode *) malloc(sizeof(ListNode));
        node = head->link;
        head->link = node->link;
        free(node);
    }
    return head;
}

ListNode *delete_last(ListNode *head)
{
    if (head == NULL) {
        printf("삭제 오류");
        return 0;
    } else {
        ListNode *temp = head->link;
        while(temp->link != head)
        {
            temp = temp->link;
        }
        temp->link = head->link;
        head = temp;
    }
    return head;
}
int main(void)
{
    ListNode *head = NULL;

    head = insert_last(head, 20);
    head = insert_last(head, 30);
    head = insert_last(head, 40);
    head = insert_first(head, 10);
    print_list(head);
    head = delete_first(head);
    print_list(head);
    head = insert_last(head, 25);
    print_list(head);
    head = delete_last(head);
    print_list(head);
    return 0;
}
