/**
 * @file matrix.c
 * @brief Integer matrix implementation
 */
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

/**
 * Creates a matrix.
 * 
 * @param nrows number of rows
 * @param ncols number of columns
 * @return matrix
 */
matrix mat_create(dim nrows, dim ncols)
{
    unsigned int i;

    /* Allocate rows */
    matrix m = (integer**)malloc(nrows * sizeof(integer*));
    if (m == NULL)
    {
        fprintf(stderr, "Error: matrix creation failed.\n");
        return NULL;
    }

    /* Allocate columns */
    for (i = 0; i < nrows; i++)
    {
        m[i] = (integer*)malloc(ncols * sizeof(integer));
        if (m[i] == NULL)
        {
            fprintf(stderr, "Error: matrix creation failed.\n");
            return NULL;
        }
    }

    return m;
}

/**
 * Deletes a matrix.
 * 
 * @param m matrix
 * @param nrows number of rows
 */
void mat_delete(matrix m, dim nrows)
{
    unsigned int i;

    /* Free rows */
    for (i = 0; i < nrows; i++)
    {
        free(m[i]);
    }
    free(m);
}

/**
 * Creates a matrix with zero coefficients.
 * 
 * @param nrows number of rows
 * @param ncols number of columns
 * @return matrix of zeros
 */
matrix mat_zeros(dim nrows, dim ncols)
{
    unsigned int i, j;
    matrix m = mat_create(nrows, ncols);

    for (i = 0; i < nrows; i++)
    {
        for (j = 0; j < ncols; j++)
        {
            m[i][j] = 0;
        }
    }

    return m;
}

/**
 * Prints a matrix.
 * 
 * @param m matrix
 * @param nrows number of rows
 * @param ncols number of columns
 * @param name name of m
 */
void mat_print(const matrix m, dim nrows, dim ncols, char *name)
{
    unsigned int i, j;

    printf("%s =\n", name);
    for (i = 0; i < nrows; i++)
    {
        for (j = 0; j < ncols; j++)
        {
            printf(" %7d", m[i][j]);
        }
        printf("\n");
    }
}

/**
 * Computes the submatrix of m privated of a row and a column in s.
 * 
 * @param m matrix of dimension d
 * @param d dimension
 * @param row row to ignore
 * @param col column to ignore
 * @param s submatrix of dimension d - 1
 */
void mat_submat(const matrix m, dim d, int row, int col, matrix s)
{
    /* Indexes for m */
    int r, c;

    /* Indexes for s */
    int i = 0, j = 0;

    /* Loop rows */
    for (r = 0; r < d; r++)
    {
        /* Row to ignore */
        if (r == row)
        {
            continue;
        }

        /* Reset column index for new row */
        j = 0;

        /* Loop columns */
        for (c = 0; c < d; c++)
        {
            /* Column to ignore */
            if (c == col)
            {
                continue;
            }
            s[i][j] = m[r][c];

            /* Next column */
            j++;
        }

        /* Next row */
        i++;
    }
}

/**
 * Computes the determinant of a square matrix.
 * 
 * @param m matrix
 * @param d dimension
 * @return det(m)
 */
integer mat_det(const matrix m, dim d)
{
    matrix subm;
    int i, j;
    integer det = 0;

    if (d == 1)
    {
        det = m[0][0];
    }
    if (d == 2)
    {
        det = m[0][0] * m[1][1] - m[0][1] * m[1][0];
    }
    else
    {
        subm = mat_create(d - 1, d - 1);
        j = 0;
        for (i = 0; i < d; i++)
        {
            mat_submat(m, d, i, j, subm);
            det += m[i][j] * ((i % 2 == 0)? 1 : -1) * mat_det(subm, d - 1);
        }
        mat_delete(subm, d - 1);
    }
    return det;
}
