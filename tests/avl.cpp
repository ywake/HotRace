extern "C" {
#include "avl.h"
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <map>

#include "gtest/gtest.h"

static int get_digit(int n);
static int itoa_recursive(char *result, int n);
static char *ft_itoa(int n);

// AVL木がルール(左右の部分木の高さの差の絶対値が1以下)を守っているかチェックする.
// Time Complexity is O(n).
static void exepct_avl_tree_keeps_rules(t_node *root) {
  int height_diff = avl_get_height(root->left) - avl_get_height(root->right);
  EXPECT_TRUE(height_diff >= -1 && height_diff <= 1);
  if (!((height_diff >= -1 && height_diff <= 1))) {
    printf("height_diff: %d\n", height_diff);
    avl_print_tree(root, 0);
    exit(1);
  }
}

TEST(AVLTree, Random100000) {
  typedef std::map<std::string, std::string> map_type;

  srand(time(NULL));

  const int MAX_NUM = 100000;

  t_node *tree = NULL;

  map_type m;

  printf("start insert data\n");
  for (int i = 0; i < MAX_NUM; ++i) {
    char *key = ft_itoa(rand());
    char *value = ft_itoa(i);
    m[std::string(key)] = std::string(value);
    t_node *new_node_ptr = avl_insert(&tree, strdup(key), strdup(value));
    EXPECT_TRUE(new_node_ptr);
    free(key);
    free(value);
  }

  printf("start search data\n");
  for (map_type::iterator it = m.begin(); it != m.end(); ++it) {
    // printf(
    // "map[%s]=%s\n"
    // "avl[%s]=%s\n"
    // "\n",
    // it->first.c_str(), it->second.c_str(), it->first.c_str(),
    // avl_get(tree, (char *)it->first.c_str())->value);
    EXPECT_TRUE(strcmp(avl_get(tree, (char *)it->first.c_str())->value,
                       it->second.c_str()) == 0);
  }

  avl_free_tree(tree);
}

TEST(AVLTree, AlwaysKeepsRules) {
  srand(time(NULL));

  const int MAX_NUM = 10000;

  t_node *tree = NULL;

  for (int i = 0; i < MAX_NUM; ++i) {
    char *str = ft_itoa(i);
    t_node *new_node_ptr = avl_insert(&tree, strdup(str), strdup(str));
    EXPECT_TRUE(new_node_ptr);
    free(str);
    exepct_avl_tree_keeps_rules(tree);
  }
  avl_free_tree(tree);
}

/************** utils ****************/

static int get_digit(int n) {
  int digit;

  if (n == 0)
    return (1);
  digit = 0;
  while (n) {
    digit++;
    n /= 10;
  }
  return (digit);
}

static int itoa_recursive(char *result, int n) {
  int idx;
  int sign;

  idx = 0;
  sign = 1;
  if (n / 10)
    idx = itoa_recursive(result, n / 10);
  else if (n < 0)
    result[idx++] = '-';
  if (n < 0)
    sign = -1;
  result[idx++] = '0' + sign * (n % 10);
  result[idx] = '\0';
  return (idx);
}

static char *ft_itoa(int n) {
  int arr_size;
  char *result;

  arr_size = get_digit(n) + 1;
  if (n < 0)
    arr_size++;
  result = (char *)calloc(arr_size, sizeof(char));
  if (!result)
    return (NULL);
  itoa_recursive(result, n);
  return (result);
}
