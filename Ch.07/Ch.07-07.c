#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;
typedef struct DListNode {
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
} DListNode;

void init(DListNode* phead)
{
    phead->llink = phead;
    phead->rlink = phead;
}

void print_dlist(DListNode* phead)
{
    DListNode* p;
    for (p = phead->rlink; p != phead; p = p->rlink) {
        printf("<-| |%d| |-> ", p->data);
    }
    printf("\n");
}

void dinsert(DListNode *before, element data)
{
    DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
    newnode->data = data;
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

void ddelete(DListNode* head, DListNode* removed)
{
    if (removed == head) return;
    removed->llink->rlink = removed->rlink;
    removed->rlink->llink = removed->llink;
    free(removed);
}

DListNode *search(DListNode *L, element data) {
    if(L->llink == L && L->rlink == L)
        return NULL;
    int count = 1;
    for (DListNode *p = L->rlink; p != L; p = p->rlink) {
        if(p->data == data) {
            printf("%d번 노드에서 데이터 %d를 찾았습니다.\n", count, data);
            return p;
        }
        count ++;
    }
    return NULL;
}

int main(void)
{
    DListNode* head = (DListNode *)malloc(sizeof(DListNode));
    init(head);
    for (int i = 0; i < 5; i++) {
        dinsert(head, i);
        print_dlist(head);
    }
    search(head, 3);
    free(head);
    return 0;
}