#ifndef DIGITS_H
#define DIGITS_H

enum { MIN_FOUR_DIGIT = 1000, MAX_FOUR_DIGIT = 9999 };

typedef struct {
    int thousands;
    int hundreds;
    int tens;
    int units;
} Digits4;

Digits4 extract_digits4(int num);

#endif // DIGITS_H
