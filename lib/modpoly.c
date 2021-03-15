/**
 * @file modpoly.c
 * @brief Polynomial arithmetic implementation in Fm[x]
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modpoly.h"

/**
 * Return the maximum between a and b.
 * 
 * @param a first integer
 * @param b second integer
 * @return max(a, b)
 */
int max(int a, int b)
{
    return a < b ? b : a;
}

/**
 * Computes r = (p + q) in Fm[x].
 * 
 * @param p first polynomial
 * @param dp degree of p
 * @param q second polynomial
 * @param dq degree of q
 * @param r polynomial (p + q) in Fm[x]
 * @param m modulus
 * @return degree of r
 */
degree mp_add(const polynomial p, degree dp, const polynomial q, degree dq, polynomial r, modulus m)
{
    unsigned int i;

    /* Calculate polynomial r */
    if (dp < dq)
    {
        for (i = 0; i <= dp; i++)
        {
            r[i] = mi_add(p[i], q[i], m);
        }
        for (i = dp + 1; i <= dq; i++)
        {
            r[i] = mod(q[i], m);
        }
    }
    else
    {
        for (i = 0; i <= dq; i++)
        {
            r[i] = mi_add(p[i], q[i], m);
        }
        for (i = dq + 1; i <= dp; i++)
        {
            r[i] = mod(p[i], m);
        }
    }

    /* Calculate degree dr */
    for (i = max(dp, dq); i > 0; i--)
    {
        if (r[i] != 0)
        {
            return i;
        }
    }
    return 0;
}

/**
 * Computes r = (p - q) in Fm[x].
 * 
 * @param p first polynomial
 * @param dp degree of p
 * @param q second polynomial
 * @param dq degree of q
 * @param r polynomial (p - q) in Fm[x]
 * @param m modulus
 * @return degree of r
 */
degree mp_sub(const polynomial p, degree dp, const polynomial q, degree dq, polynomial r, modulus m)
{
    unsigned int i;

    /* Calculate polynomial r */
    if (dp < dq)
    {
        for (i = 0; i <= dp; i++)
        {
            r[i] = mi_sub(p[i], q[i], m);
        }
        for (i = dp + 1; i <= dq; i++)
        {
            r[i] = mod(-q[i], m);
        }
    }
    else
    {
        for (i = 0; i <= dq; i++)
        {
            r[i] = mi_sub(p[i], q[i], m);
        }
        for (i = dq + 1; i <= dp; i++)
        {
            r[i] = mod(p[i], m);
        }
    }
    /* Calculate degree dr */
    for (i = max(dp, dq); i > 0; i--)
    {
        if (r[i] != 0)
        {
            return i;
        }
    }
    return 0;
}

/**
 * Computes r = (p * q) in Fm[x].
 * 
 * @param p first polynomial
 * @param dp degree of p
 * @param q second polynomial
 * @param dq degree of q
 * @param r polynomial (p * q) in Fm[x]
 * @param m modulus
 * @return degree of r
 */
degree mp_mul(const polynomial p, degree dp, const polynomial q, degree dq, polynomial r, modulus m)
{
    unsigned int i, j;

    /* Calculate degree dr */
    degree dr = dp + dq;
    if (dr > MAX_DEGREE)
    {
        fprintf(stderr,
                "Mod Error: max degree for polynomials is %d (%d is too big). Exit.\n", MAX_DEGREE, dr);
        exit(EXIT_FAILURE);
    }   

    /* Initialize r */
    for (i = 0; i <= dr; i++)
    {
        r[i] = 0;
    }

    /* Calculate r */
    for (i = 0; i <= dp; i++)
    {
        for (j = 0; j <= dq; j++)
        {
            r[i + j] = mi_add(r[i + j], mi_mul(p[i], q[j], m), m);
        }
    }
    return dr;
}

/**
 * Computes q = (p / d) in Fm[x].
 * 
 * @param p dividend
 * @param dp degree of p
 * @param d divisor
 * @param dd degree of d
 * @param q quotient
 * @param m modulus
 * @return degree of q
 */
degree mp_div(const polynomial p, degree dp, const polynomial d, degree dd, polynomial q, modulus m)
{
    int i, j;
    integer t;
    polynomial r;

    /* Calculate degree dq */
    int dq = dp - dd;

    /* Case zero polynomial */
    if (dq < 0)
    {
        q[0] = 0;
        return 0;
    }

    /* Init remainder r */
    p_copy(p, dp, r);

    for (i = dp; i >= (int)dd; i--)
    {
        q[i - dd] = t = mi_div(r[i], d[dd], m);
        r[i] = 0;

        for (j = 0; j < dd; j++)
        {
            r[i - dd + j] = mod(r[i - dd + j] - d[j] * t, m);
        }
    }

    return dq;
}

/**
 * Computes r = (p mod d) in Fm[x].
 * 
 * @param p dividend
 * @param dp degree of p
 * @param d divisor
 * @param dd degree of d
 * @param r remainder
 * @param m modulus
 * @return degree of r
 */
degree mp_mod(const polynomial p, degree dp, const polynomial d, degree dd, polynomial r, modulus m)
{
    int i, j, t, dr;

    /* Init remainder r */
    dr = p_copy(p, dp, r);

    for (i = dp; i >= dd; i--)
    {
        t = mi_div(r[i], d[dd], m);
        r[i] = 0;

        for (j = 0; j < dd; j++)
        {
            r[i - dd + j] = mod(r[i - dd + j] - d[j] * t, m);
        }
    }

    /* Calculate degree dr */
    for (i = dr; i > 0; i--)
    {
        if (r[i] != 0)
        {
            return i;
        }
    }
    return 0;
}

/**
 * Evaluate a polynomial p at x using naive method.
 * 
 * @param p polynomial
 * @param dp degree of p
 * @param x integer
 * @param m modulus
 * @return p(x) mod m
 */
integer mp_eval(const polynomial p, degree dp, integer x, modulus m)
{
    return mod(p_eval(p, dp, x), m);
}

/**
 * Evaluate a polynomial p at x using Horner’s Method.
 * 
 * @param p polynomial
 * @param dp degree of p
 * @param x integer
 * @param m modulus
 * @return p(x) mod m
 */
integer mp_horner(const polynomial p, degree dp, integer x, modulus m)
{
    return mod(p_horner(p, dp, x), m);
}

/**
 * Evaluate a polynomial p at n points using Horner’s Method.
 * 
 * @param p polynomial
 * @param dp degree of p
 * @param x points
 * @param y p(x)
 * @param n number of points
 * @param m modulus
 */
void mp_horner_multipoint(const polynomial p, degree dp, const integer *x, integer *y, unsigned int n, modulus m)
{
    int i;
    for (i = 0; i < n; i++)
    {
        y[i] = mp_horner(p, dp, x[i], m);
    }
}

/**
 * Derivate a polynomial p in Fm[x].
 * 
 * @param p polynomial
 * @param dp degree of p
 * @param r derivative of p
 * @param m modulus
 * @return degree of r
 */
degree mp_derivate(const polynomial p, degree dp, polynomial r, modulus m)
{
    int i;
    degree dr;

    /* Case constant polynomial */
    if (dp == 0)
    {
        r[0] = 0;
        return 0;
    }

    dr = dp - 1;
    for (i = 0; i <= dr; i++)
    {
        r[i] = mi_mul(p[i + 1], i + 1, m);
    }

    /* Calculate degree dr */
    for (i = dr; i > 0; i--)
    {
        if (r[i] != 0)
        {
            return i;
        }
    }
    return 0;
}

/**
 * Computes the Lagrange basis polynomial li.
 * 
 * @param x points
 * @param n number of points
 * @param i index of xi
 * @param l Lagrange basis polynomial
 * @param m modulus
 * @return degree of li
 */
degree mp_lagrange_basis(const integer* x, unsigned int n, unsigned int i, polynomial l, modulus m)
{
    int j;
    polynomial p, q;
    degree dl, dp, dq;

    /* Init l */
    l[0] = 1; dl = 0;

    /* Calculate product */
    dp = 1;
    for (j = 0; j < n; j++)
    {
        if (j != i)
        {
            p[0] = mi_div(mod(-x[j], m), mi_sub(x[i], x[j], m), m);
            p[1] = mi_div(1, mi_sub(x[i], x[j], m), m);
            dq = mp_mul(l, dl, p, dp, q, m);
            dl = p_copy(q, dq, l);
        }
    }

    /* Calculate degree dl */
    for (j = dl; j > 0; j--)
    {
        if (l[j] != 0)
        {
            return j;
        }
    }
    return 0;
}

/**
 * Computes the Lagrange polynomial from a set of points (x, y).
 * 
 * @param x points
 * @param y points
 * @param n number of points
 * @param L Lagrange polynomial
 * @param m modulus
 * @return degree of L
 */
degree mp_lagrange_polynomial(const integer* x, const integer* y, unsigned int n, polynomial L, modulus m)
{
    int i, k;
    polynomial l, p;
    degree dL, dl, dp;

    /* Init L */
    L[0] = 0; dL = 0;

    /* Calculate sum */
    for (i = 0; i < n; i++)
    {
        /* Calculate Lagrange basis polynomial */
        dl = mp_lagrange_basis(x, n, i, l, m);

        /* Multiply li with yi */
        for (k = 0; k <= dl; k++)
        {
            l[k] = mi_mul(y[i], l[k], m);
        }

        /* Add to the sum */
        dp = mp_add(L, dL, l, dl, p, m);
        dL = p_copy(p, dp, L);
    }

    /* Calculate degree dL */
    for (i = dL; i > 0; i--)
    {
        if (L[i] != 0)
        {
            return i;
        }
    }
    return 0;
}

/**
 * Creates the subproduct tree recursively.
 * 
 * @param x points
 * @param n1 minimum index in x
 * @param n2 maximum index in x
 * @param m modulus
 * @return node
 */
polynode* mp_subproduct_node(const integer* x, unsigned int n1, unsigned int n2, modulus m)
{
    polynode *n;

    if ((n2 - n1) % 2 != 0)
    {
        fprintf(stderr, "Mod Error: n2 - n1 must be a multiple of 2. Exit.\n");
        exit(EXIT_FAILURE);
    }

    /* Create node */
    n = pnode_new();

    if (n2 - n1 == 2)
    {
        /* Create leaves */
        n->left = pnode_new();
        n->left->p[0] = mod(-x[n1], m); n->left->p[1] = 1;
        n->left->d = 1;

        n->right = pnode_new();
        n->right->p[0] = mod(-x[n1 + 1], m); n->right->p[1] = 1;
        n->right->d = 1;
    }
    else
    {
        /* Resursive call */
        n->left = mp_subproduct_node(x, n1, n2 / 2, m);
        n->right = mp_subproduct_node(x, n2 / 2, n2, m);
    }

    /* Multiply polynomials */
    n->d = mp_mul(n->left->p, n->left->d, n->right->p, n->right->d, n->p, m);

    return n;
}

/**
 * Creates the subproduct tree.
 * 
 * @param x points
 * @param n number of points
 * @param m modulus
 * @return tree
 */
polytree* mp_subproduct_tree(const integer* x, unsigned int n, modulus m)
{
    polytree* tree = ptree_new();
    tree->root = mp_subproduct_node(x, 0, n, m);
    return tree;
}

/**
 * Creates the remainder tree recursively.
 * 
 * @param node node of the subproduct tree
 * @param p polynomial
 * @param dp degree of p
 * @param m modulus
 * @return node
 */
polynode* mp_remainder_node(const polynode* node, const polynomial p, degree dp, modulus m)
{
    polynode* n;

    if (node == NULL)
    {
        return NULL;
    }

    /* Create node */
    n = pnode_new();

    /* Calculate polynomial */
    n->d = mp_mod(p, dp, node->p, node->d, n->p, m);

    /* Recursive call */
    n->left = mp_remainder_node(node->left, n->p, n->d, m);
    n->right = mp_remainder_node(node->right, n->p, n->d, m);

    return n;
}

/**
 * Creates the remainder tree.
 * 
 * @param node node of the subproduct tree
 * @param p polynomial
 * @param dp degree of p
 * @param m modulus
 * @return node
 */
polytree* mp_remainder_tree(const polytree* tree, const polynomial p, degree dp, modulus m)
{
    polytree* t = ptree_new();
    t->root = mp_remainder_node(tree->root, p, dp, m);
    return t;
}

/**
 * Evaluate a polynomial p at n points using fast evaluation.
 * 
 * @param p polynomial
 * @param dp degree of p
 * @param x points
 * @param y p(x)
 * @param n number of points
 * @param m modulus
 */
void mp_fast_multipoint_eval(const polynomial p, degree dp, const integer *x, integer *y, unsigned int n, modulus m)
{
    /* TODO to modify */
    int i;
    polynomial r;
    degree dd = 1;
    polynomial d = {0, 1};
    for (i = 0; i < n; i++)
    {
        d[0] = mod(-x[i], m);
        mp_mod(p, dp, d, dd, r, m);
        y[i] = r[0];
    }
}
