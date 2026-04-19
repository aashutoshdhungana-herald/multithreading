#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

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
    clock_t start = clock();

    if (argc < 2)
    {
        printf("Pass the total number to sum\n");
        return 1;
    }
    long long n = atoll(argv[1]);

    int num_threads = 8;
    pthread_t threads[num_threads];
    ThreadData thread_data[num_threads];

    // Divide the task among the threads
    for (int i = 0; i < num_threads; i++)
    {
        thread_data[i].start = i * (n / num_threads);
        thread_data[i].end = (i + 1) * (n / num_threads);
        if (i == num_threads - 1)
        {
            thread_data[i].end = n;
        }
        pthread_create(&threads[i], NULL, sum_to_n, &thread_data[i]);
    }

    long long total_sum = 0;
    for (int i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], NULL);
        total_sum += thread_data[i].sum;
    }

    printf("Total Sum: %lld\n", total_sum);
    clock_t end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("CPU Time Used: %f seconds\n", cpu_time_used);
    return 0;
}