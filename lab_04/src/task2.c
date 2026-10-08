#include "tasks.h"
#include "utils.h"

#include <stdio.h>

void run_task2(void) {
    long a[MAX_ARRAY_SIZE];
    long n = 0;

    puts("\n=== Task 2: sum of even elements with even ordinal numbers ===\n");

    if (!read_sequence("a", a, &n)) {
        return;
    }

    long sum = 0;

    for (long i = 0; i < n; i += 2) {
        if (a[i] % 2 == 0) {
            sum += a[i];
        }
    }

    puts("");
    print_sequence("a", a, n);
    printf("\nSum: %ld\n", sum);
}
