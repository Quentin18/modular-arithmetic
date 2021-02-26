/**
 * @file testModInt.c
 * @brief Tests for modular arithmetic for integers
 */
#include <stdio.h>
#include "modint.h"

/**
 * Tests for modular arithmetic for integers.
 */
int main()
{
    int a = 3, b = 4, m = 5;
    printf("a = %d, b = %d, m = %d\n", a, b, m);

    /* Test operators */
    printf("a + b = %d mod %d\n", mi_add(a, b, m), m);
    printf("a - b = %d mod %d\n", mi_sub(a, b, m), m);
    printf("a * b = %d mod %d\n", mi_mul(a, b, m), m);
    printf("a^-1 = %d mod %d\n", mi_inv(a, m), m);
    printf("b^-1 = %d mod %d\n", mi_inv(b, m), m);
    printf("a / b = %d mod %d\n", mi_div(a, b, m), m);

    /* Test inverse 0 */
    mi_div(a, 0, m);

    return 0;
}
