#include "tasks.h"
#include "utils.h"

#include <math.h>
#include <stdio.h>

void run_task1(void) {
    long a[MAX_ARRAY_SIZE];
    long n = 0;

    puts("\n=== Task 1: extreme elements, mean and even numbers ===\n");

    if (!read_sequence("a", a, &n)) {
        return;
    }

    long max_even_index = 0;
    long min_odd_index = -1;

    long sum = 0;
    long even_count = 0;

    for (long i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            if (a[i] > a[max_even_index]) {
                max_even_index = i;
            }
        } else if (min_odd_index < 0 || a[i] < a[min_odd_index]) {
            min_odd_index = i;
        }

        sum += a[i];

        if (a[i] % 2 == 0) {
            ++even_count;
        }
    }

    const double mean = (double)sum / (double)n;
    long closest_index = 0;

    for (long i = 1; i < n; ++i) {
        if (fabs((double)a[i] - mean) < fabs((double)a[closest_index] - mean)) {
            closest_index = i;
        }
    }

    puts("");
    print_sequence("a", a, n);

    printf(
        "\nLargest element with an even ordinal number: a[%ld] = %ld\n",
        max_even_index,
        a[max_even_index]
    );

    if (min_odd_index < 0) {
        puts("Smallest element with an odd ordinal number: none (N = 1)");
    } else {
        printf(
            "Smallest element with an odd ordinal number: a[%ld] = %ld\n",
            min_odd_index,
            a[min_odd_index]
        );
    }

    printf(
        "Arithmetic mean: %.4f, the closest element: a[%ld] = %ld\n",
        mean,
        closest_index,
        a[closest_index]
    );
    printf("Number of even elements: %ld\n", even_count);
}
