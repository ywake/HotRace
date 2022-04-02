#include <stdio.h>
#include <string.h>

#include "avl.h"

#define BUF_SIZE 200

static void print_tree(t_node *root, int indent) {
  if (root == NULL)
    return;

  print_tree(root->right, indent + 1);

  for (int i = 0; i < indent; ++i)
  	printf("\t");
  printf("%s\n", root->key);

  print_tree(root->left, indent + 1);
}

// https://www.cs.usfca.edu/~galles/visualization/AVLtree.html
int main() {
  t_node *tree = NULL;
  char buf[BUF_SIZE];

  buf[0] = '\0';
  while (1) {
    printf("\nKey: ");
    fgets(buf, BUF_SIZE, stdin);
	if (strncmp(buf, "END", 3) == 0) {
		return 0;
	}
    char *key = strdup(buf);

    printf("\nValue: ");
    fgets(buf, BUF_SIZE, stdin);
    char *value = strdup(buf);

    avl_insert(&tree, key, value);

    print_tree(tree, 0);
  }

  return 0;
}
