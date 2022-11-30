#include<stdio.h>
#include<stdlib.h>

#define MAX_ELEMENT 200
#define MINIMUM -100000000 // 최소값

typedef struct {
    int heap[MAX_ELEMENT];
    int heap_size;
}HeapType;

void init(HeapType* h) {
    h->heap_size = 0;
}

void insert_max_heap(HeapType* h, int item) {
    h->heap[h->heap_size] = item;
    h->heap_size++;
}

int delete_max_heap(HeapType* h) {
    int m = MINIMUM, index;
    for (int i = 0; i < h->heap_size; i++) {
        if (h->heap[i] > m) {
            m = h->heap[i];
            index = i;
        }
    }
    for (int i = index; i < h->heap_size; i++)
        h->heap[i] = h->heap[i + 1];
    h->heap_size--;
    return m;
}

int is_empty(HeapType* h) {
    return h->heap_size == 0;
}

int is_full(HeapType* h) {
    return h->heap_size == MAX_ELEMENT;
}

int find_max_heap(HeapType* h) {
    int m = MINIMUM;
    for (int i = 0; i < h->heap_size; i++) {
        if (h->heap[i] > m)
            m = h->heap[i];
    }
    return m;
}

int main() {
    HeapType *h;
    h = (HeapType *) malloc(sizeof (HeapType));
    h = {};
}