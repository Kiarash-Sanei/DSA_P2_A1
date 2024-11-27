#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_HEAP 100000
#define MIN_HEAP 100000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapPush(int *heap, int *size, int value) {
    heap[(*size)++] = value;
    int i = *size - 1;

    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}

int maxHeapPop(int *heap, int *size) {
    int root = heap[0];
    heap[0] = heap[--(*size)];
    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < *size && heap[left] > heap[largest])
            largest = left;
        if (right < *size && heap[right] > heap[largest])
            largest = right;

        if (largest == i) break;

        swap(&heap[i], &heap[largest]);
        i = largest;
    }

    return root;
}

void minHeapPush(int *heap, int *size, int value) {
    heap[(*size)++] = value;
    int i = *size - 1;

    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}

int minHeapPop(int *heap, int *size) {
    int root = heap[0];
    heap[0] = heap[--(*size)];
    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < *size && heap[left] < heap[smallest])
            smallest = left;
        if (right < *size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i) break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int maxHeap[MAX_HEAP], minHeap[MIN_HEAP];
    int maxSize = 0, minSize = 0;
    long long c = 0;

    for (int i = 0; i < n; i++) {
        int command;
        scanf("%d", &command);

        if (command == 1) {
            int a, b;
            scanf("%d %d", &a, &b);

            if (maxSize == 0 || a <= maxHeap[0]) {
                maxHeapPush(maxHeap, &maxSize, a);
            } else {
                minHeapPush(minHeap, &minSize, a);
            }

            if (maxSize > minSize + 1) {
                minHeapPush(minHeap, &minSize, maxHeapPop(maxHeap, &maxSize));
            } else if (minSize > maxSize) {
                maxHeapPush(maxHeap, &maxSize, minHeapPop(minHeap, &minSize));
            }

            c += b;

        } else {
            int median = (maxSize >= minSize) ? maxHeap[0] : minHeap[0];

            long long sum = 0;
            for (int j = 0; j < maxSize; j++) {
                sum += llabs(maxHeap[j] - median);
            }
            for (int j = 0; j < minSize; j++) {
                sum += llabs(minHeap[j] - median);
            }

            printf("%d %lld\n", median, sum + c);
        }
    }

    return 0;
}
