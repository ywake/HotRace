/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:43:43 by ywake             #+#    #+#             */
/*   Updated: 2022/04/01 17:12:12 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_H
#define AVL_H

typedef struct s_node {
  char *key;
  char *value;

  struct s_node *parent;
  struct s_node *left;
  struct s_node *right;
} t_node;

t_node *avl_insert(t_node **root, char *key, char *value);
t_node *avl_get(t_node *root, char *key);

t_node *avl_malloc_node(char *key, char *value);
void avl_free_node(t_node *node);
void avl_free_tree(t_node *root);
int avl_get_height(t_node *root);
void avl_print_tree(t_node *root, int indent);

t_node *avl_rotate_left(t_node *root);
t_node *avl_rotate_right(t_node *root);
t_node *avl_rotate_left_right(t_node *root);
t_node *avl_rotate_right_left(t_node *root);

#endif
