/**
 * @file example12.c
 * @brief Example 12: Formal power series
 */
#include <stdio.h>
#include "fps.h"

/**
 * Formal power series.
 */
int main()
{
    fps u;
    fps s = {2, 3, 4, 5, 6, 0, 1, 2};
    prec n = 8;
    modulus m = 7;

    fps_print(s, n, "S");
    fps_newton_inverse(s, n, u, m);

    return 0;
}
