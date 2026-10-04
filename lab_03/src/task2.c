#define X_COUNT 5
#define PROMPT_SIZE 32

#include "tasks.h"
#include "utils.h"

#include <math.h>
#include <stdio.h>

// Numerator: (x - 1024)(x - 1000)(x - 996)...(x - 4)(x - 2)
enum {
    NUM_FIRST = 1024,
    NUM_RUN_FROM = 1000,
    NUM_RUN_TO = 4,
    NUM_STEP = 4,
    NUM_LAST = 2
};

// Denominator: (x - 1)(x - 3)(x - 5)...(x - 31)
enum { DEN_FROM = 1, DEN_TO = 31, DEN_STEP = 2 };

// mantissa * 10^exp10
typedef struct {
    double mantissa;
    int exp10;
} ScaledValue;

static void normalize(ScaledValue *const value) {
    if (value->mantissa == 0.0) {
        value->exp10 = 0;
        return;
    }

    // Scale up when dropped below 1.0
    while (fabs(value->mantissa) < 1.0) {
        value->mantissa *= 10.0;
        value->exp10--;
    }

    // Scale down when reached or exceeded 10.0
    while (fabs(value->mantissa) >= 10.0) {
        value->mantissa /= 10.0;
        value->exp10++;
    }
}

static void multiply(ScaledValue *const value, const double factor) {
    if (value->mantissa == 0.0) {
        return;
    }

    if (factor == 0.0) {
        value->mantissa = 0.0;
        value->exp10 = 0;
        return;
    }

    value->mantissa *= factor;
    normalize(value);
}

static void divide(ScaledValue *const value, const double factor) {
    if (value->mantissa == 0.0) {
        return;
    }

    if (factor == 0.0) {
        value->mantissa = NAN;
        value->exp10 = 0;
        return;
    }

    value->mantissa /= factor;
    normalize(value);
}

static ScaledValue calculate_y(const double x) {
    ScaledValue y = {.mantissa = 1.0, .exp10 = 0};

    multiply(&y, x - NUM_FIRST);

    for (int k = NUM_RUN_FROM; k >= NUM_RUN_TO; k -= NUM_STEP) {
        multiply(&y, x - k);
    }

    multiply(&y, x - NUM_LAST);

    for (int k = DEN_FROM; k <= DEN_TO; k += DEN_STEP) {
        divide(&y, x - k);
    }

    return y;
}

static void print_scaled(const ScaledValue y) {
    if (isnan(y.mantissa)) {
        puts("undefined (division by zero)");
        return;
    }

    if (y.mantissa == 0.0) {
        puts("+0.000000e+0");
        return;
    }

    printf(
        "%c%.6fe%+d\n", y.mantissa < 0.0 ? '-' : '+', fabs(y.mantissa), y.exp10
    );
}

void run_task2(void) {
    puts("\n=== Task 2: product of factors for five values of x ===\n");
    puts("y = (x-1024)(x-1000)(x-996)...(x-2) / ((x-1)(x-3)...(x-31))\n");

    double xs[X_COUNT];
    char prompt[PROMPT_SIZE];

    for (int i = 0; i < X_COUNT; ++i) {
        snprintf(prompt, sizeof(prompt), "Enter real x%d: ", i + 1);

        if (!read_double_in_range(
                prompt, -MAX_INPUT_ABS, MAX_INPUT_ABS, &xs[i]
            )) {
            return;
        }
    }

    puts("");

    for (int i = 0; i < X_COUNT; ++i) {
        printf("x = %12.4f  ->  y = ", xs[i]);
        print_scaled(calculate_y(xs[i]));
    }
}
