/**
 * @file example09.c
 * @brief Example 09: Trees in Fm[x]
 */
#include <stdio.h>
#include "modpoly.h"

/**
 * Trees in Fm[x].
 */
int main()
{
    polytree *s_tree, *r_tree;

    polynomial p = {4, 1, 2, 1};
    degree dp = 3;
    integer x[] = {2, 5, 3, 4};
    unsigned int n = 4;
    modulus m = 7;

    /* Subproduct tree */
    printf("== Subproduct tree ==\n");
    s_tree = mp_subproduct_tree(x, n, m);
    ptree_print(s_tree);
    ptree_export(s_tree, "s_tree.dot", "Subproduct tree");

    /* Root polynomial */
    printf("== Root polynomial ==\n");
    p_print(s_tree->root->p, s_tree->root->d, "A");

    /* Remainder tree */
    printf("== Remainder tree of P ==\n");
    p_print(p, dp, "P");
    r_tree = mp_remainder_tree(s_tree, p, dp, m);
    ptree_print(r_tree);
    ptree_export(r_tree, "r_tree.dot", "Remainder tree");

    /* Free memory */
    ptree_free(s_tree);
    ptree_free(r_tree);

    return 0;
}
