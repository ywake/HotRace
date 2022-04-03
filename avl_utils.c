/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 00:53:29 by jtanaka           #+#    #+#             */
/*   Updated: 2022/04/03 10:46:28 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avl.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int	avl_get_height(t_node *root)
{
	int	left_height;
	int	right_height;
	int	height;

	if (!root)
	{
		return (0);
	}
	left_height = avl_get_height(root->left);
	right_height = avl_get_height(root->right);
	if (left_height > right_height)
		height = left_height;
	else
		height = right_height;
	return (height + 1);
}

t_node	*avl_malloc_node(char *key, char *value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (node);
	node->key = key;
	node->value = value;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	avl_free_node(t_node *node)
{
	free(node);
}

void	avl_free_tree(t_node *root)
{
	if (!root)
		return ;
	avl_free_tree(root->left);
	avl_free_tree(root->right);
	avl_free_node(root);
}

void	avl_print_tree(t_node *root, int indent)
{
	int	i;

	if (root == NULL)
		return ;
	avl_print_tree(root->right, indent + 1);
	i = 0;
	while (i++ < indent)
		printf("\t");
	printf("%s\n", root->key);
	avl_print_tree(root->left, indent + 1);
}
