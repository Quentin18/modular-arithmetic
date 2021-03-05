/**
 * @file extendedGcdInt.h
 * @brief Header file for Extended Euclidean algorithm for integers
 */
#pragma once

#include "integer.h"

integer extended_gcd_int(integer a, integer b, integer* u, integer* v);
integer print_extended_gcd_int(integer a, integer b, integer* u, integer* v);
