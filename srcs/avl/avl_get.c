/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:18:18 by ywake             #+#    #+#             */
/*   Updated: 2022/04/01 18:06:33 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avl.h"
#include "utils.h"
#include <string.h>

t_node	*avl_get(t_node *root, char *key)
{
	t_node *current;

	current = root;
	while (current) {
		if (ft_strcmp(key, current->key) > 0)
			current = current->right;
		else if (ft_strcmp(key, current->key) < 0)
			current = current->left;
		else
			return current;
	}
	return current;
}
