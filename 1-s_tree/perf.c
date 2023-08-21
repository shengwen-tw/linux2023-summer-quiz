#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "stree_int.h"
#include "rbtree_int.h"

long long run_stree(int size, unsigned int seed)
{
    srand(seed);

    streeint_init();

    struct timespec start_time, end_time;
    long long start_ns, end_ns, elapsed_ns;

    // Get the start time
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    start_ns = start_time.tv_sec * 1000000000LL + start_time.tv_nsec;

    for (int i = 0; i < size; ++i)
        streeint_insert(rand() % 99);

    for (int i = 0; i < size; ++i) {
        int v = rand() % 99;
        streeint_remove(v);
    }

    // Get the end time
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    end_ns = end_time.tv_sec * 1000000000LL + end_time.tv_nsec;

    // Calculate the elapsed time in nanoseconds
    elapsed_ns = end_ns - start_ns;

    streeint_destroy();

    return elapsed_ns;
}


long long run_rbtree(int size, unsigned int seed)
{
    srand(seed);

    rbtreeint_init();

    struct timespec start_time, end_time;
    long long start_ns, end_ns, elapsed_ns;

    // Get the start time
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    start_ns = start_time.tv_sec * 1000000000LL + start_time.tv_nsec;

    for (int i = 0; i < size; ++i)
        rbtreeint_insert(rand() % 99);

    for (int i = 0; i < size; ++i) {
        int v = rand() % 99;
        rbtreeint_remove(v);
    }

    // Get the end time
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    end_ns = end_time.tv_sec * 1000000000LL + end_time.tv_nsec;

    // Calculate the elapsed time in nanoseconds
    elapsed_ns = end_ns - start_ns;

    rbtreeint_destroy();

    return elapsed_ns;
}

int main(void)
{
    printf("Start time statistics...\n");

    /* Open CSV file to write */
    FILE *file;
    char *csv_file = "perf.csv";
    file = fopen(csv_file, "w");
    if (file == NULL) {
        perror("Error opening file\n");
        return 1;
    }

    unsigned int seed;

    /* Time statistics loop */
    long long st_time, rb_time;
    for(int size = 100; size <= 100000; size += 100) {
        seed = time(0);

        /* Run S-Tree and Red Black Tree with different data size */
        st_time = run_stree(size, seed);
        rb_time = run_rbtree(size, seed);

        /* Record statistics result with CSV format */
        fprintf(file, "%d,%lld,%lld\n", size, st_time, rb_time);
    }

    printf("Complete.\n");

    fclose(file);

    return 0;
}
