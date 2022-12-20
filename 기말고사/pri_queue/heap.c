#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
typedef struct {
    int key;
} element;
typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;


HeapType* create()
{
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h)
{
    h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item)
{
    int i;
    i = ++(h->heap_size); // 힙 사이즈 증가 +1

    // 번호순으로 가장 마지막 위치에 이어서 새로운 요소 삽입
    // 부모 노드와 비교하여 크기가 더 큰 경우 교환 진행
    // 크기가 더 크지 않다면 교환 중단
    while ((i != 1) && (item.key > h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}

// 히프 삭제 연산
element delete_max_heap(HeapType* h)
{
    int parent, child;
    element item, temp;

    item = h->heap[1]; // 가장 상단에 존재하는 큰 값의 노드를 return 하기 위해 저장
    temp = h->heap[(h->heap_size)--]; // 가장 말단에 존재하는 노드를 가져옴
    parent = 1;
    child = 2;
    while (child <= h->heap_size) { // 힙 사이즈가 child 보다 클 때 까지 진행
        if ((child < h->heap_size) &&
            (h->heap[child].key) < h->heap[child + 1].key) // 힙 사이즈가 child보다 크고, 자식 노드의 크기를 비교
            child++;
        if (temp.key >= h->heap[child].key) break; // 말단에 존재하는 노드가 자식 노드보다 크다면 break
        h->heap[parent] = h->heap[child]; // 삭제된 부모 노드를 대체하여 자식 노드 중 큰 값으로 대체
        parent = child; // 부모 노드 인덱스에 child를 대입하고, child * 2 실행
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

void heap_sort(element a[], int n)
{
    int i;
    HeapType *h;
    h = create();
    init(h);
    for (i = 0; i < n; i++) {
        insert_max_heap(h, a[i]);
    }
    for (i = (n - 1); i >= 0; i--) {
        a[i] = delete_max_heap(h);
    }
    free(h);
}

void print_max_heap(HeapType* h) {

}
int main(void)
{
    element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
    element e4, e5, e6;
    HeapType* heap;

    heap = create();
    init(heap);

    insert_max_heap(heap, e1);
    insert_max_heap(heap, e2);
    insert_max_heap(heap, e3);

    e4 = delete_max_heap(heap);
    printf("< %d > ", e4.key);
    e5 = delete_max_heap(heap);
    printf("< %d > ", e5.key);
    e6 = delete_max_heap(heap);
    printf("< %d > \n", e6.key);

    free(heap);
    return 0;
}