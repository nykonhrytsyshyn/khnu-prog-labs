#include "digits.h"
#include "tasks.h"
#include "utils.h"

#include <stdio.h>

Digits4 extract_digits4(const int num) {
    return (Digits4){
        .thousands = num / 1000,
        .hundreds = num / 100 % 10,
        .tens = num / 10 % 10,
        .units = num % 10
    };
}

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

    const Digits4 d = extract_digits4((int)n);
    const int sum = d.thousands + d.hundreds + d.tens;

    printf("\nN = %ld\n", n);
    printf("Digits: %d %d %d %d\n", d.thousands, d.hundreds, d.tens, d.units);
    printf("Sum of the first three digits: %d\n", sum);
}
