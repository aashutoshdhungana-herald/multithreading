#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    // total time elapsed for the entire program
    time_t start, end;
    time(&start);

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

    time(&end);
    double total_time_ellapsed = difftime(end, start);
    printf("Total Time Elapsed: %f seconds\n", total_time_ellapsed);

    return 0;
}