/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:18:32 by ywake             #+#    #+#             */
/*   Updated: 2022/04/03 01:48:15 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avl.h"
#include "utils.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static t_node	*avl_insert_sub(t_node *root, t_node *new_node);
static void		avl_replace_node(t_node *old, t_node *new);
static t_node	*avl_get_root_node(t_node *base);

t_node	*avl_insert(t_node **root, char *key, char *value)
{
	t_node	*new_root;
	t_node	*new_node;

	new_node = avl_malloc_node(key, value);
	if (!new_node)
		return (NULL);
	if (*root == NULL)
	{
		*root = new_node;
	}
	else
	{
		new_root = avl_insert_sub(*root, new_node);
		if (!new_root)
			return (NULL);
		*root = new_root;
	}
	return (new_node);
}

static t_node	*avl_insert_sub(t_node *root, t_node *new_node)
{
	t_node	*parent;
	t_node	*current;

	current = root;
	while (current)
	{
		parent = current;
		if (ft_strcmp(new_node->key, current->key) > 0)
			current = current->right;
		else if (ft_strcmp(new_node->key, current->key) < 0)
			current = current->left;
		else
		{
			avl_replace_node(current, new_node);
			avl_free_node(current);
			return (avl_get_root_node(new_node));
		}
	}
	if (ft_strcmp(new_node->key, parent->key) > 0)
		parent->right = new_node;
	else if (ft_strcmp(new_node->key, parent->key) < 0)
		parent->left = new_node;
	new_node->parent = parent;
	return (avl_get_root_node(avl_rebalance(new_node)));
}

static void	avl_replace_node(t_node *old_node, t_node *new_node)
{
	new_node->left = old_node->left;
	if (old_node->left)
		old_node->left->parent = new_node;
	new_node->right = old_node->right;
	if (old_node->right)
		old_node->right->parent = new_node;
	new_node->parent = old_node->parent;
	if (old_node->parent)
	{
		if (old_node->parent->left == old_node)
			old_node->parent->left = new_node;
		else if (old_node->parent->right == old_node)
			old_node->parent->right = new_node;
	}
}

static t_node	*avl_get_root_node(t_node *base)
{
	while (base && base->parent)
		base = base->parent;
	return (base);
}
