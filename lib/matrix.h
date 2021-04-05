/**
 * @file matrix.h
 * @brief Header file for integer matrix
 */
#pragma once

#include "integer.h"

/**
 * Represents a matrix
 */
typedef integer** matrix;

/**
 * Represents a dimension of a matrix
 */
typedef unsigned int dim;

matrix mat_create(dim nrows, dim ncols);
void mat_delete(matrix m, dim nrows);
matrix mat_zeros(dim nrows, dim ncols);
void mat_print(const matrix m, dim nrows, dim ncols, char *name);
