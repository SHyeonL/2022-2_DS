#include <stdio.h>

#define SIZE 8

void insert_sort(int data[]) {
    int key, j;
    for (int i = 1; i < SIZE; i++) {
        key = data[i];
        for (j = i - 1; j >= 0 && data[j] > key; j--) {
            data[j + 1] = data[j];
        }
        data[j + 1] = key;
    }
}

int main() {
    int data[8] = {25, 49, 35, 32, 13, 58, 94, 13};
    for (int i = 0; i < 8; i++) {
        printf("[%d] ", data[i]);
    }
    printf("\n");
    insert_sort(data);
    for (int i = 0; i < 8; i++) {
        printf("[%d] ", data[i]);
    }
}