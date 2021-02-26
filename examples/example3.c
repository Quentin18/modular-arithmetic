/**
 * @file example3.c
 * @brief Example 3: Advanced operations with modular arithmetic for integers
 */
#include <stdio.h>
#include "modint.h"

/**
 * Advanced operations with modular arithmetic for integers.
 */
int main()
{
    int a = 3, b = 4, m = 5;
    printf("a = %d, b = %d, m = %d\n", a, b, m);

    /* Inverse */
    printf("a^-1 = %d mod %d\n", mi_inv(a, m), m);
    printf("b^-1 = %d mod %d\n", mi_inv(b, m), m);

    /* Division */
    printf("a / b = %d mod %d\n", mi_div(a, b, m), m);

    /* Test inverse 0: error */
    mi_div(a, 0, m);

    return 0;
}