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

    i_print(a, "a");
    i_print(b, "b");
    i_print(m, "m");

    /* Ring */
    printf("Ring: Z/%dZ\n", m);

    /* Inverse */
    i_print(mi_inv(a, m), "a^-1");
    i_print(mi_inv(b, m), "b^-1");

    /* Division */
    i_print(mi_div(a, b, m), "a / b");

    /* Test inverse 0: error */
    mi_div(a, 0, m);

    return 0;
}
