/**
 * @file integer.h
 * @brief Header file for integer arithmetic
 */
#pragma once

#include <stdint.h>

/**
 * Represents an integer
 */
typedef int32_t integer;

void i_scan(integer *a, char *name);
void i_print(integer a, char *name);

integer i_add(integer a, integer b);
integer i_sub(integer a, integer b);
integer i_mul(integer a, integer b);
integer i_div(integer a, integer b);
integer i_mod(integer a, integer b);
