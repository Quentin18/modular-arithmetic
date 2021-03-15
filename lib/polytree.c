/**
 * @file polytree.c
 * @brief Binary trees for polynomials
 */
#include <stdlib.h>
#include "polytree.h"

/**
 * Creates a new node.
 * 
 * @return node
 */
polynode* pnode_new()
{
    polynode* n = malloc(sizeof(polynode));
    n->left = n->right = NULL;
    return n;
}

/**
 * Creates a new tree.
 * 
 * @return tree
 */
polytree* ptree_new()
{
    polytree* t = malloc(sizeof(polytree));
    t->root = NULL;
    return t;
}

/**
 * Frees the memory allocated for a node.
 * 
 * @param node node
 */
void pnode_free(polynode* node)
{
    if (node->left != NULL)
    {
        pnode_free(node->left);
    }
    if (node->right != NULL)
    {
        pnode_free(node->right);
    }    
    free(node);
}

/**
 * Frees the memory allocated for a tree.
 * 
 * @param tree tree
 */
void ptree_free(polytree* tree)
{
    if (tree->root != NULL)
    {
        pnode_free(tree->root);
    }    
    free(tree);
}

/**
 * Prints a node.
 * 
 * @param node node
 */
void pnode_print(polynode* node)
{
    if (node->left != NULL)
    {
        pnode_print(node->left);
    }
    if (node->right != NULL)
    {
        pnode_print(node->right);
    }
    p_print(node->p, node->d, "P");
}

/**
 * Prints a tree.
 * 
 * @param tree tree
 */
void ptree_print(polytree* tree)
{
    if (tree->root != NULL)
    {
        pnode_print(tree->root);
    }    
}
