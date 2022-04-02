#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "avl.h"

int avl_get_height(t_node *root) {
	int left_height;
	int right_height;
	int height;

	if (!root) {
		return 0;
	}
	left_height = avl_get_height(root->left);
	right_height = avl_get_height(root->right);
	if (left_height > right_height)
		height = left_height;
	else
		height = right_height;
	return height + 1;
}

t_node *avl_malloc_node(char *key, char *value) {
	t_node *node = malloc(sizeof(t_node));
	if (!node)
		return node;
	node->key = key;
	node->value = value;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void avl_free_node(t_node* node) {
	free(node->key);
	free(node->value);
	free(node);
}

void avl_free_tree(t_node *root) {
	if (!root)
		return;
	avl_free_tree(root->left);
	avl_free_tree(root->right);
	avl_free_node(root);
}

void avl_print_tree(t_node *root, int indent) {
  if (root == NULL)
    return;

  avl_print_tree(root->right, indent + 1);

  for (int i = 0; i < indent; ++i)
  	printf("\t");
  printf("%s\n", root->key);

  avl_print_tree(root->left, indent + 1);
}
