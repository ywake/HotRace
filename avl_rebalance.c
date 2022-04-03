/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_rebalance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 01:48:08 by jtanaka           #+#    #+#             */
/*   Updated: 2022/04/03 01:52:12 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avl.h"

static void	avl_rebalance_left(t_node *target);
static void	avl_rebalance_right(t_node *target);

// new_nodeからrootに遡りながら平衡係数を計算して必要あれば回転する.
// 回転操作を行った箇所のノードを返す.
t_node	*avl_rebalance(t_node *new_node)
{
	t_node	*current;
	t_node	*child;
	int		is_active;
	int		height_diff;

	is_active = 1;
	child = new_node;
	current = child->parent;
	while (is_active && current)
	{
		height_diff = avl_get_height(current->left)
			- avl_get_height(current->right);
		if (height_diff > 1)
			avl_rebalance_left(current);
		else if (height_diff < -1)
			avl_rebalance_right(current);
		if (height_diff > 1 || height_diff < -1 || height_diff == 0)
			is_active = 0;
		child = current;
		current = current->parent;
	}
	return (child);
}

static void	avl_rebalance_left(t_node *current)
{
	int	height_diff;

	height_diff = avl_get_height(current->left->left)
		- avl_get_height(current->left->right);
	if (height_diff <= -1)
		current = avl_rotate_left_right(current);
	else
		current = avl_rotate_right(current);
}

static void	avl_rebalance_right(t_node *current)
{
	int	height_diff;

	height_diff = avl_get_height(current->right->left)
		- avl_get_height(current->right->right);
	if (height_diff >= 1)
		current = avl_rotate_right_left(current);
	else
		current = avl_rotate_left(current);
}
