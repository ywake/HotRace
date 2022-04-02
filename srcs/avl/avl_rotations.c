#include <stdio.h>
#include "avl.h"

t_node *avl_rotate_left(t_node *root) {
  printf("Execute avl_rotate_left at %s\n", root->key);
  t_node *pivot;

  pivot = root->right;
  if (pivot) {
    root->right = pivot->left;
	if (pivot->left)
    	pivot->left->parent = root;
    pivot->left = root;
	if (root->parent) {
		if (root->parent->left == root)
			root->parent->left = pivot;
		else
			root->parent->right = pivot;
	}
    pivot->parent = root->parent;
    root->parent = pivot;
  }
  return pivot;
}

t_node *avl_rotate_right(t_node *root) {
  printf("Execute avl_rotate_right at %s\n", root->key);
  t_node *pivot;

  pivot = root->left;
  if (pivot) {
    root->left = pivot->right;
	if (pivot->right)
 	   pivot->right->parent = root;
    pivot->right = root;
	if (root->parent) {
		if (root->parent->left == root)
			root->parent->left = pivot;
		else
			root->parent->right = pivot;
	}
    pivot->parent = root->parent;
    root->parent = pivot;
  }
  return pivot;
}

t_node *avl_rotate_left_right(t_node *root) {
  printf("Execute avl_rotate_left_right at %s\n", root->key);
  t_node *pivot;

  pivot = avl_rotate_left(root->left);
  root->left = pivot;
  pivot->parent = root;
  pivot = avl_rotate_right(root);
  return pivot;
}

t_node *avl_rotate_right_left(t_node *root) {
  printf("Execute avl_rotate_right_left at %s\n", root->key);
  t_node *pivot;

  pivot = avl_rotate_right(root->right);
  root->right = pivot;
  pivot->parent = root;
  pivot = avl_rotate_left(root);
  return pivot;
}
