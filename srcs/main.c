/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:54:39 by ywake             #+#    #+#             */
/*   Updated: 2022/04/03 12:57:50 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avl.h"
#include "io.h"
#include "utils.h"

#include <stdlib.h>
#include <stdbool.h>

static int	insert(t_node **tree, char **inputs)
{
	int		i;
	char	*key;
	char	*value;

	key = NULL;
	value = NULL;
	i = 0;
	while (inputs[i] && inputs[i][0])
	{
		if (i % 2 == 0)
			key = inputs[i];
		else
		{
			value = inputs[i];
			if (!key || !value)
				return (-1);
			avl_insert(tree, key, value);
			key = NULL;
			value = NULL;
		}
		i++;
	}
	return (i);
}

static int	search(t_list	**buf, t_node *root, char **inputs)
{
	int		i;
	char	*keyword;
	t_node	*node;
	bool	err;

	err = false;
	i = 0;
	while (inputs[i])
	{
		keyword = inputs[i++];
		node = avl_get(root, keyword);
		if (node)
			err = err || add_to_buffer(buf, node->value);
		else
		{
			err = err || add_to_buffer(buf, keyword);
			err = err || add_to_buffer(buf, ": Not found.");
		}
		err = err || add_to_buffer(buf, "\n");
	}
	ft_lst_reverse(buf);
	return (-err);
}

int	main(void)
{
	t_node	*root;
	t_list	*out_buf;
	char	**inputs;
	int		i;

	root = NULL;
	inputs = read_stdin();
	i = insert(&root, inputs);
	if (i < 0)
		return (1);
	out_buf = NULL;
	if (search(&out_buf, root, inputs + i + 1) == 0)
		flush_buffer(out_buf);
	avl_free_tree(root);
	ft_lstclear(&out_buf, NULL);
	free(inputs[0]);
	free(inputs);
	return (0);
}
