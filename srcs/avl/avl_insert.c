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
#include <stdio.h>
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
  } else {
    new_root = avl_insert_sub(*root, new_node);
    if (!new_root)
      return NULL;
    *root = new_root;
  }
  return new_node;
}

static t_node *avl_insert_sub(t_node *root, t_node *new_node) {
  t_node *parent;
  t_node *current;

  parent = NULL;
  current = root;
  while (current) {
    parent = current;
    if (ft_strcmp(new_node->key, current->key) > 0)
      current = current->right;
    else if (ft_strcmp(new_node->key, current->key) < 0)
      current = current->left;
    else {
      new_node->left = current->left;
      if (current->left)
        current->left->parent = new_node;

      new_node->right = current->right;
      if (current->right)
        current->right->parent = new_node;

      new_node->parent = current->parent;
      if (current->parent) {
        if (current->parent->left == current)
          current->parent->left = new_node;
        else if (current->parent->right == current)
          current->parent->right = new_node;
      }
      avl_free_node(current);
      current = new_node;
      while (current && current->parent) current = current->parent;
      return current;
    }
  }
  if (ft_strcmp(new_node->key, parent->key) > 0) {
    parent->right = new_node;
    new_node->parent = parent;
  } else if (ft_strcmp(new_node->key, parent->key) < 0) {
    parent->left = new_node;
    new_node->parent = parent;
  }

  current = avl_rebalance(new_node);
  while (current && current->parent) current = current->parent;
  return current;
}

// 平衡係数を計算して必要あれば回転する
static t_node *avl_rebalance(t_node *new_node) {
  t_node *current;
  t_node *child;
  int is_active;
  int height_diff;

  is_active = 1;
  child = new_node;
  current = child->parent;
  while (is_active && current) {
    height_diff =
        avl_get_height(current->left) - avl_get_height(current->right);
    if (height_diff > 1) {
      height_diff = avl_get_height(current->left->left) -
                    avl_get_height(current->left->right);
      if (height_diff <= -1)
        current = avl_rotate_left_right(current);
      else
        current = avl_rotate_right(current);
      is_active = 0;
    } else if (height_diff < -1) {
      height_diff = avl_get_height(current->right->left) -
                    avl_get_height(current->right->right);
      if (height_diff >= 1)
        current = avl_rotate_right_left(current);
      else
        current = avl_rotate_left(current);
      is_active = 0;
    } else if (height_diff == 0) {
      is_active = 0;
    }
    child = current;
    current = current->parent;
  }
  return child;
}
