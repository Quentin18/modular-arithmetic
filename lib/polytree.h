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
    polynomial p;
    degree d;
    struct polynode *left, *right;
} polynode;

/**
 * Represents a binary tree with polynomials
 */
typedef struct polytree
{
    polynode* root;
} polytree;

polynode* pnode_new();
polytree* ptree_new();
void pnode_free(polynode* node);
void ptree_free(polytree* tree);
void pnode_print(polynode* node);
void ptree_print(polytree* tree);
