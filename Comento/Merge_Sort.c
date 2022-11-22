#include <stdio.h>
#include <stdlib.h>

int sort[8];

void merge_recursive(int data[], int left, int right, int mid) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while(i <= mid && j <= right) {
        if (data[i] < data[j]) {
            sort[k++] = data[i++];
        } else {
            sort[k++] = data[j++];
        }
    }

    if (i > mid) {
        for(; j <= right; j++) {
            sort[k++] = data[j];
        }
    } else {
        for(; i <= mid; i++) {
            sort[k++] = data[i];
        }
    }
    for(i = left; i <= right; i++) {
        data[i] = sort[i];
    }

}
void sort_recursive(int data[], int start, int end) {
    int mid = (start + end) / 2;
    if (start < end) {
        sort_recursive(data, start, mid);
        sort_recursive(data, mid + 1, end);
        merge_recursive(data, start, end, mid);
    }
}

int main() {
    int data[8] = { 25, 49, 35, 32, 13, 58, 94, 13};
    printf("정렬 전 배열 \n");
    for(int i = 0; i < 8; i++) {
        printf("[%d]  ", data[i]);
    }
    sort_recursive(data, 0, 7);
    printf("\n정렬 후 배열 \n");
    for(int i = 0; i < 8; i++) {
        printf("[%d]  ", data[i]);
    }
}