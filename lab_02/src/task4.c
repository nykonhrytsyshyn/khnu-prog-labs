#include "tasks.h"
#include "utils.h"

#include <stdio.h>

enum { MIN_FOUR_DIGIT = 1000, MAX_FOUR_DIGIT = 9999 };

void run_task4(void) {
    long n = 0;

    puts("\n=== Task 4: sum of the first three digits of N ===\n");

    if (!read_long("Enter a positive four-digit integer N: ", &n)) {
        puts("Invalid input.");
        return;
    }

    if (n < MIN_FOUR_DIGIT || n > MAX_FOUR_DIGIT) {
        printf(
            "Error: N must be a four-digit integer (%d-%d).\n",
            MIN_FOUR_DIGIT,
            MAX_FOUR_DIGIT
        );
        return;
    }

    const long thousands = n / 1000;
    const long hundreds = n / 100 % 10;
    const long tens = n / 10 % 10;
    const long units = n % 10;
    const long sum = thousands + hundreds + tens;

    printf("\nN = %ld\n", n);
    printf("Digits: %ld %ld %ld %ld\n", thousands, hundreds, tens, units);
    printf("Sum of the first three digits: %ld\n", sum);
}
