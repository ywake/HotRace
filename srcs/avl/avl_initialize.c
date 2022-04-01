#include "avl.h"
#include <stdlib.h>

t_node  *avl_initialize() {
	t_node *nil_node;

	nil_node = malloc(sizeof(t_node));
	nil_node->key = NULL;
	nil_node->value = NULL;
	nil_node->parent = nil_node;
	nil_node->left = nil_node;
	nil_node->right = nil_node;
	return nil_node;
}
