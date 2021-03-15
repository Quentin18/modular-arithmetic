/**
 * @file example9.c
 * @brief Example 9: Subproduct tree in Fm[x]
 */
#include <stdio.h>
#include "modpoly.h"

/**
 * Subproduct tree in Fm[x].
 */
int main()
{
    polytree* tree;

    integer x[] = {1, 2, 4, 8};
    unsigned int n = 4;
    modulus m = 11;

    tree = mp_subproduct_tree(x, n, m);
    ptree_print(tree);
    ptree_free(tree);

    return 0;
}
