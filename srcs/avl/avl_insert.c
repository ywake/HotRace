/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:18:32 by ywake             #+#    #+#             */
/*   Updated: 2022/04/01 18:05:37 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "avl.h"
#include "utils.h"

static t_node *avl_rebalance(t_node *root);
static t_node *avl_insert_sub(t_node *root, t_node *new_node);

t_node *avl_insert(t_node **root, char *key, char *value) {
  t_node *new_root;
  t_node *new_node;

  new_node = avl_malloc_node(key, value);
  if (!new_node)
    return NULL;
  if (*root == NULL) {
    *root = new_node;
  }
  else {
	new_root = avl_insert_sub(*root, new_node);
	if (!new_root)
		return NULL;
	*root = new_root;
  }
  return new_node;
}

// TODO: strcmp を ft_strcmp に置き換える
static t_node *avl_insert_sub(t_node *root, t_node *new_node) {
  t_node *parent;
  t_node *current;

  parent = NULL;
  current = root;
  while (current) {
    parent = current;
    if (strcmp(new_node->key, current->key) > 0)
      current = current->right;
    else if (strcmp(new_node->key, current->key) < 0)
      current = current->left;
  }
  if (strcmp(new_node->key, parent->key) > 0) {
    parent->right = new_node;
    new_node->parent = parent;
  } else if (strcmp(new_node->key, parent->key) < 0) {
    parent->left = new_node;
    new_node->parent = parent;
  }

  current = avl_rebalance(new_node->parent);
  while (current->parent)
	current = current->parent;
  return current;
}

// 平衡係数を計算して必要あれば回転する
static t_node *avl_rebalance(t_node *parent) {
  t_node *current;
  int is_active;
  int height_diff;

  is_active = 1;
  current = parent;
  while (is_active && current->parent) {
    height_diff = avl_get_height(current->left) - avl_get_height(current->right);
    if (height_diff > 1) {
      if (avl_get_height(current->left) < avl_get_height(current->left->right))
        current = avl_rotate_left_right(current);
      else
        current = avl_rotate_right(current);
	  is_active = 0;
    } else if (height_diff < -1) {
      if (avl_get_height(current->right) < avl_get_height(current->right->left))
        current = avl_rotate_right_left(current);
      else
        current = avl_rotate_left(current);
	  is_active = 0;
    } else if (height_diff == 0) {
		is_active = 0;
	}
	current = current->parent;
  }
  return current;
}
