/**
 * @file polytree.c
 * @brief Binary trees for polynomials
 */
#include <stdio.h>
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
void pnode_print(const polynode* node)
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
void ptree_print(const polytree* tree)
{
    if (tree->root != NULL)
    {
        pnode_print(tree->root);
    }    
}

/**
 * Gets values of leaves in a remainder tree recursively.
 * 
 * @param node node
 * @param y leaves values
 * @param i index
 */
void pnode_get_leaves_remainder(const polynode* node, integer *y, unsigned int *i)
{
    if (node->left == NULL && node->right == NULL)
    {
        y[(*i)++] = p_const(node->p);
    }
    else
    {
        pnode_get_leaves_remainder(node->left, y, i);
        pnode_get_leaves_remainder(node->right, y, i);
    }
}

/**
 * Gets values of leaves in a remainder tree.
 * 
 * @param tree tree
 * @param y leaves values
 */
void ptree_get_leaves_remainder(const polytree* tree, integer *y)
{
    unsigned int i = 0;
    pnode_get_leaves_remainder(tree->root, y, &i);
}

/**
 * Writes a node to a dot file.
 * 
 * @param node node
 * @param file file
 * @param i node number
 */
void pnode_write(const polynode* node, FILE *file, unsigned int *i)
{
    /* Number of the node */
    unsigned int num = *i;

    fprintf(file, "\tn%u [label=\"", num);
    p_write(node->p, node->d, file);
    fprintf(file, "\"];\n");
    if (node->left != NULL)
    {
        fprintf(file, "\tn%u -- n%u;\n", num, ++(*i));
        pnode_write(node->left, file, i);
    }
    if (node->right != NULL)
    {
        fprintf(file, "\tn%u -- n%u;\n", num, ++(*i));
        pnode_write(node->right, file, i);
    }
}

/**
 * Exports a tree of polynomials to dot format.
 * 
 * @param tree tree
 * @param filename filename
 * @param title title
 */
void ptree_export(const polytree* tree, const char* filename, const char* title)
{
    unsigned int i = 0;

    /* Create file */
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        fprintf(stderr, "Mod Error: cannot open file %s. Exit.\n", filename);
        exit(1);
    }

    /* Init graph */
    fprintf(file, "graph tree {\n\tnode [shape=box];\n");

    /* Write tree */
    pnode_write(tree->root, file, &i);

    /* Add title and close graph */
    fprintf(file, "\tlabel=\"%s\";\n}\n", title);

    /* Close file */
    fclose(file);
}
