#include <stddef.h>
#include <stdlib.h>
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
