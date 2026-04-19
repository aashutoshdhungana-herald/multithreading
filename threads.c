#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *array;
    int start;
    int end;
    int sum;
} ThreadData;

void *sum_array(void *arg)
{
    ThreadData *data = (ThreadData *)arg;
    data->sum = 0;

    for (int i = data->start; i < data->end; i++)
    {
        data->sum += data->array[i];
    }

    pthread_exit(NULL);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int sum = 0;
    pthread_t thread1, thread2, thread3;
    ThreadData data1, data2, data3;

    data1.array = arr;
    data1.start = 0;
    data1.end = 7;

    data2.array = arr;
    data2.start = 7;
    data2.end = 14;

    data3.array = arr;
    data3.start = 14;
    data3.end = 20;

    pthread_create(&thread1, NULL, sum_array, &data1);
    pthread_create(&thread2, NULL, sum_array, &data2);
    pthread_create(&thread3, NULL, sum_array, &data3);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    int total_sum = data1.sum + data2.sum + data3.sum;
    printf("Total Sum: %d\n", total_sum);

    return 0;
}