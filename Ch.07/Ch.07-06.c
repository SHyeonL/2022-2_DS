#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
    element data;
    struct DListNode *llink;
    struct DListNode *rlink;
} DListNode;

void init(DListNode *phead) {
    phead->llink = phead;
    phead->rlink = phead;
}

void print_dlist_rev(DListNode *phead) {
    DListNode *p;
    printf("데이터를 역순으로 출력 : ");
    for (p = phead->llink; p != phead; p = p->llink) {
        printf("%d ", p->data);
    }
}
// ���ο� �����͸� ��� before�� �����ʿ� �����Ѵ�.
void dinsert(DListNode *before, element data) {
    DListNode *newnode = (DListNode *) malloc(sizeof(DListNode));
    newnode->data = data;
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

int main(void) {
    int count, insert_num;
    DListNode *head = (DListNode *) malloc(sizeof(DListNode));
    DListNode *temp;
    init(head);
    temp = head;
    printf("데이터의 개수를 입력하세요 : ");
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        printf("노드 #%d의 데이터를 입력하시오 : ", (i + 1));
        scanf("%d", &insert_num);
        dinsert(head, insert_num);
        head = head->rlink;
    }
    head = temp;
    print_dlist_rev(head);
    free(head);
    return 0;
}