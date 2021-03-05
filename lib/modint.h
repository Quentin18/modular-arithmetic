/**
 * @file modint.h
 * @brief Header file for modular arithmetic with integers
 */
#pragma once

#include "integer.h"

/**
 * Represents a modulus
 */
typedef uint32_t modulus;

integer mod(int64_t a, modulus m);
integer mi_add(integer a, integer b, modulus m);
integer mi_sub(integer a, integer b, modulus m);
integer mi_mul(integer a, integer b, modulus m);
integer mi_inv(integer a, modulus m);
integer mi_div(integer a, integer b, modulus m);
