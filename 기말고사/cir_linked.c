#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

void print_list(ListNode* head)
{
    ListNode* p;

    if (head == NULL) return;
    p = head->link;
    do {
        printf("%d->", p->data);
        p = p->link;
    } while (p != head);
    printf("%d->", p->data);
}

// 원형 리스트의 앞부분에 노드 삽입
// 1. head(마지막 연결 리스트를 가리킴), head가 NULL인 경우에는 head = node로, node.link를 head로 설정
// 2. node.link를 head.link로 설정하고, head.link를 node로 설정
ListNode* insert_first(ListNode* head, element data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
    }
    return head;
}

// 원형 리스트의 마지막 부분에 노드 삽입
// 1. head가 NULL인 경우 앞부분 삽입과 동일함
// 2. node.link를 head.link, head.link를 node로 설정하고 head = node
ListNode* insert_last(ListNode* head, element data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

// 원형 링크드 리스트의 크기를 구하는 함수 head.link를 통해 넘어가고 temp가 L일 때 까지 반복문 실행
int get_size(ListNode *L)
{
    ListNode *temp;
    int count = 0;
    if (L == NULL)
        return 0;
    else {
        temp = L->link;
        while(temp != L) {
            count ++;
            temp = temp->link;
        }
        count++;
    }
    return count;
}

int main(void)
{
    ListNode *head = NULL;
    int count = 0;

    head = insert_last(head, 20);
    head = insert_last(head, 30);
    head = insert_last(head, 40);
    head = insert_first(head, 10);
    print_list(head);
    count = get_size(head);
    printf("\n");
    printf("원형 리스트의 개수 : %d", count);
    return 0;
}