#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    long long start;
    long long end;
    long long sum;
} ThreadData;

void *sum_to_n(void *arg)
{
    ThreadData *data = (ThreadData *)arg;
    data->sum = 0;

    for (long long i = data->start; i < data->end; i++)
    {
        data->sum += i;
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    clock_t start, end;
    time(&start);

    if (argc < 2)
    {
        printf("Pass the total number to sum\n");
        return 1;
    }
    long long n = atoll(argv[1]);

    pthread_t thread1, thread2, thread3;
    ThreadData data1, data2, data3;

    // Divide the task to three threads
    data1.start = 0;
    data1.end = n / 3;

    data2.start = n / 3;
    data2.end = 2 * n / 3;

    data3.start = 2 * n / 3;
    data3.end = n;

    pthread_create(&thread1, NULL, sum_to_n, &data1);
    pthread_create(&thread2, NULL, sum_to_n, &data2);
    pthread_create(&thread3, NULL, sum_to_n, &data3);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    long long total_sum = data1.sum + data2.sum + data3.sum;
    printf("Total Sum: %lld\n", total_sum);
    time(&end);
    double total_time_ellapsed = difftime(end, start);
    printf("Total Time Elapsed: %f seconds\n", total_time_ellapsed);
    return 0;
}