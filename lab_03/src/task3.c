#include "tasks.h"
#include "utils.h"

#include <limits.h>
#include <stdio.h>

static int sum_of_digits(unsigned long magnitude) {
    int sum = 0;

    while (magnitude > 0) {
        sum += (int)(magnitude % 10);
        magnitude /= 10;
    }

    return sum;
}

void run_task3(void) {
    long n = 0;

    puts("\n=== Task 3: sum of the digits of N ===\n");

    if (!read_long_in_range("Enter an integer N: ", LONG_MIN, LONG_MAX, &n)) {
        return;
    }

    const unsigned long magnitude =
        n < 0 ? 0UL - (unsigned long)n : (unsigned long)n;

    printf("\nN = %ld\n", n);
    printf("Sum of the digits: %d\n", sum_of_digits(magnitude));
}
