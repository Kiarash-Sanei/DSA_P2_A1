#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int findMedian(int* x, int size)
{
    while (1)
    {
        srand(time(NULL));
        int place = rand() % size;
        int random = x[place];
        int left = 0;
        int right = 0;
        int equal = 0;

        for (int i = 0; i < size; i++)
        {
            if (x[i] == random)
            {
                equal++;
            }
            else if (x[i] < random)
            {
                left++;
            }
            else
            {
                right++;
            }
        }

        for (int i = 0; i <= equal; i++)
        {
            if (left + i == right + equal - i ||
            left + i + 1 == right + equal - i ||
            left + i == right + equal - i + 1)
            {
                return place;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d\n", &n);
    int x[200000];
    int index = 0;
    long long c = 0;

    for (int i = 0; i < n; i++)
    {
        int command;
        scanf("%d", &command);

        if (command == 1)
        {
            int a, b;
            scanf(" %d %d\n", &a, &b);
            x[index] = a;
            index++;
            c += b;
        }
        else 
        {
            int median = x[findMedian(x, index)];
            long long sum = 0;

            for (int j = 0; j < index; j++)
            {
                sum += llabs(median - x[j]);
            }
            
            printf("%d %lld\n", median, sum + c);
        }
    }
    
    return 0;
}