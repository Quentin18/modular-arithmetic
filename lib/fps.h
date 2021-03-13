/**
 * @file fps.h
 * @brief Header file for Formal power series
 */
#pragma once

#include "modpoly.h"

/**
 * Represents a truncated formal power series
 */
typedef polynomial fps;

/**
 * Represents a precision of a truncated formal power series
 */
typedef unsigned int prec;

void fps_print(const fps s, prec n, char *name);
void fps_newton_inverse(const fps s, prec n, fps u, modulus m);
