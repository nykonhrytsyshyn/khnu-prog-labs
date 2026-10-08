#include "tasks.h"
#include "utils.h"

#include <stdio.h>

void run_task3(void) {
    long a[MAX_ARRAY_SIZE];
    long n = 0;

    puts(
        "\n=== Task 3: sum of even elements with even ordinal numbers (through "
        "a pointer) ==="
    );

    if (!read_sequence("a", a, &n)) {
        return;
    }

    long sum = 0;

    for (const long *p = a; p < a + n; ++p) {
        const ptrdiff_t ordinal = p - a;

        if (ordinal % 2 == 0 && *p % 2 == 0) {
            sum += *p;
        }
    }

    puts("");
    print_sequence("a", a, n);
    printf("\nSum: %ld\n", sum);
}
