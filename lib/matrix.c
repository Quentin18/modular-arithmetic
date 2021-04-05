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
