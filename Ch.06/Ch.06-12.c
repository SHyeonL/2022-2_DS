#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode *insert_first(ListNode *head, int value) {
    ListNode *p = (ListNode *) malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

ListNode *insert(ListNode *head, ListNode *pre, element value) {
    ListNode *p = (ListNode *) malloc(sizeof(ListNode));
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}

ListNode *delete_first(ListNode *head) {
    ListNode *removed;
    if (head == NULL) return NULL;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

ListNode *delete(ListNode *head, ListNode *pre) {
    ListNode *removed;
    removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

void print_list(ListNode *head) {
    for (ListNode *p = head; p != NULL; p = p->link)
        printf("%d->", p->data);
    printf("NULL \n");
}

void search(ListNode *head, element data) {
    if(head ==NULL)
        return;
    ListNode *p = head->link;
    int count = 0;
    do {
        if(p->data == data) {
            count++;
        }
        p = p->link;
    } while(p != NULL);
    printf("%d는 연결 리스트에서 %d번 나타납니다.", data, count);
}

int main(void) {
    ListNode *head = NULL;
    int num, data, node;
    printf("노드의 개수 : ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        printf("노드 #%d 데이터 : ", (i + 1));
        scanf("%d", &data);
        head = insert_first(head, data);
    }
    printf("탐색할 값을 입력하시오 : ");
    scanf("%d", &node);
    search(head, node);
    return 0;
}
