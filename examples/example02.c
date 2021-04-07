/**
 * @file example02.c
 * @brief Example 02: Simple operations with modular arithmetic for integers
 */
#include <stdio.h>
#include "modint.h"

/**
 * Simple operations with modular arithmetic for integers.
 */
int main()
{
    integer a = 3, b = 4;
    modulus m = 5;

    i_print(a, "a");
    i_print(b, "b");
    i_print(m, "m");

    /* Ring */
    printf("Ring: Z/%dZ\n", m);

    /* Addition */
    i_print(mi_add(a, b, m), "a + b");

    /* Subtraction */
    i_print(mi_sub(a, b, m), "a - b");

    /* Multiplication */
    i_print(mi_mul(a, b, m), "a * b");

    return 0;
}
