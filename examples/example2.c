/**
 * @file example2.c
 * @brief Example 2: Simple operations with modular arithmetic for integers
 */
#include <stdio.h>
#include "modint.h"

/**
 * Simple operations with modular arithmetic for integers.
 */
int main()
{
    int a = 3, b = 4, m = 5;
    printf("a = %d, b = %d, m = %d\n", a, b, m);

    /* Addition */
    printf("a + b = %d mod %d\n", mi_add(a, b, m), m);

    /* Subtraction */
    printf("a - b = %d mod %d\n", mi_sub(a, b, m), m);

    /* Multiplication */
    printf("a * b = %d mod %d\n", mi_mul(a, b, m), m);

    return 0;
}
