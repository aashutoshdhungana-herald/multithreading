#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    // time measurement
    clock_t start = clock();

    if (argc < 2)
    {
        printf("Pass the total number to sum\n");
        return 1;
    }
    long long n = atoll(argv[1]);
    long long total_sum = 0;

    for (long long i = 0; i < n; i++)
    {
        total_sum += i;
    }

    printf("Total Sum: %lld\n", total_sum);

    clock_t end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("CPU Time Used: %f seconds\n", cpu_time_used);

    return 0;
}