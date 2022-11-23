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

HeapType *create() {
    return (HeapType *) malloc(sizeof(HeapType));
}

void init(HeapType *h) {
    h->heap_size = 0;
}

void insert_max_heap(HeapType *h, element item) {
    int i;
    i = ++(h->heap_size);

    while ((i != 1) && (item.key > h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
}

element delete_max_heap(HeapType *h) {
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size) {

        if ((child < h->heap_size) &&
            (h->heap[child].key) < h->heap[child + 1].key)
            child++;
        if (temp.key >= h->heap[child].key) break;

        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

void print_Heap(HeapType *h) {
    int size = h->heap_size;
    element temp = h->heap[0];
    for (int i = 1; i < size; i *= 2) {
        temp = h->heap[i];
        for (int j = i; j < (i * 2); j++) {
            if(j == h->heap_size)
                break;
            temp = h->heap[j];
            printf("< %d >  ", temp);
        }
        printf("\n");
    }
}

int main(void) {
    element e1 = {12}, e2 = {10}, e3 = {8}, e4 = {4}, e5 = {6}, e6 = {2}, e7 = {5}, e8 = {3};
    HeapType *heap;

    heap = create();
    init(heap);

    insert_max_heap(heap, e1);
    insert_max_heap(heap, e2);
    insert_max_heap(heap, e3);
    insert_max_heap(heap, e4);
    insert_max_heap(heap, e5);
    insert_max_heap(heap, e6);
    insert_max_heap(heap, e7);
    insert_max_heap(heap, e8);
    print_Heap(heap);

    element e11 = {11};
    printf("\n\n 11을 삽입 후\n");
    insert_max_heap(heap, e11);
    print_Heap(heap);

    free(heap);
    return 0;
}