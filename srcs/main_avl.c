#include <stdio.h>
#include <string.h>

#include "avl.h"

#define BUF_SIZE 200

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

    avl_print_tree(tree, 0);
  }
  avl_free_tree(tree);

  return 0;
}
