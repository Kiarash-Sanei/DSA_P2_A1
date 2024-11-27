#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int sortMinHeap(int *x, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (2 * i + 1 < size && x[2 * i + 1] < x[i])
        {
            swap(x + 2 * i + 1, x + i);
        }
        if (2 * i + 2 < size && x[2 * i + 2] < x[i])
        {
            swap(x + 2 * i + 2, x + i);
        }
    }
}

int sortMaxHeap(int *x, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (2 * i + 1 < size && x[2 * i + 1] > x[i])
        {
            swap(x + 2 * i + 1, x + i);
        }
        if (2 * i + 2 < size && x[2 * i + 2] > x[i])
        {
            swap(x + 2 * i + 2, x + i);
        }
    }
}

void printHeap(int *x, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d", x[i]);
        if (2 * i + 1 < size)
        {
            printf(" %d", x[2 * i + 1]);
        }
        if (2 * i + 2 < size)
        {
            printf(" %d", x[2 * i + 2]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d\n", &n);
    int minHeap[100000];
    minHeap[0] = -1000000001;
    int maxHeap[100000];
    maxHeap[0] = 1000000001;
    int minIndex = 0;
    int maxIndex = 0;
    long long c = 0;

    for (int i = 0; i < n; i++)
    {
        int command;
        scanf("%d", &command);

        if (command == 1)
        {
            int a, b;
            scanf(" %d %d\n", &a, &b);

            if (a <= maxHeap[0])
            {
                maxHeap[maxIndex] = a;
                maxIndex++;
                sortMaxHeap(maxHeap, maxIndex);
                printf("max\n");
                printHeap(maxHeap, maxIndex);
            }
            else
            {
                minHeap[minIndex] = a;
                minIndex++;
                sortMinHeap(minHeap, minIndex);
                printf("min\n");
                printHeap(minHeap, minIndex);
            }

            c += b;
        }
        else
        {
            int median = maxIndex >= minIndex ? maxHeap[0] : minHeap[0];
            long long sum = 0;

            for (int j = 0; j < minIndex; j++)
            {
                sum += llabs(median - minHeap[j]);
            }
            for (int j = 0; j < maxIndex; j++)
            {
                sum += llabs(median - maxHeap[j]);
            }

            printf("%d %lld\n", median, sum + c);
        }
    }

    return 0;
}