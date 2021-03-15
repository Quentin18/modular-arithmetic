/**
 * @file polytree.h
 * @brief Definition of binary trees for polynomials
 */
#pragma once

#include "polynomial.h"

/**
 * Represents a node of a binary tree with a polynomial
 */
typedef struct polynode
{
    polynomial p;           /**< Polynomial */
    degree d;               /**< Degree of the polynomial */
    struct polynode *left;  /**< Left child */
    struct polynode *right; /**< Right child */
} polynode;

/**
 * Represents a binary tree with polynomials
 */
typedef struct polytree
{
    polynode* root;         /**< Root node of the tree */
} polytree;

polynode* pnode_new();
polytree* ptree_new();
void pnode_free(polynode* node);
void ptree_free(polytree* tree);
void pnode_print(const polynode* node);
void ptree_print(const polytree* tree);
void pnode_get_leaves_remainder(const polynode* node, integer *y, unsigned int *i);
void ptree_get_leaves_remainder(const polytree* tree, integer *y);
