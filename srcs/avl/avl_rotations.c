#include "avl.h"

t_node *avl_rotate_left(t_node *root) {
  t_node *pivot;

  pivot = root->right;
  if (pivot) {
    root->right = pivot->left;
    pivot->left->parent = root;
    pivot->left = root;
    pivot->parent = root->parent;
    root->parent = pivot;
  }
  return pivot;
}

t_node *avl_rotate_right(t_node *root) {
  t_node *pivot;

  pivot = root->left;
  if (pivot) {
    root->left = pivot->right;
    pivot->right->parent = root;
    pivot->right = root;
    pivot->parent = root->parent;
    root->parent = pivot;
  }
  return pivot;
}

t_node *avl_rotate_left_right(t_node *root) {
  t_node *pivot;

  pivot = avl_rotate_left(root->left);
  root->left = pivot;
  pivot->parent = root;
  pivot = avl_rotate_right(root);
  return pivot;
}

t_node *avl_rotate_right_left(t_node *root) {
  t_node *pivot;

  pivot = avl_rotate_right(root->right);
  root->right = pivot;
  pivot->parent = root;
  pivot = avl_rotate_left(root);
  return pivot;
}
