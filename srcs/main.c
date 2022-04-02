/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtanaka <jtanaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:54:39 by ywake             #+#    #+#             */
/*   Updated: 2022/04/03 02:12:35 by jtanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avl.h"
#include "io.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

static int	insert(t_node **tree, char **inputs)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	while (ft_strlen(inputs[i]))
	{
		key = ft_strdup(inputs[i++]);
		value = ft_strdup(inputs[i++]);
		if (!key || !value)
			return (-1);
		avl_insert(tree, key, value);
	}
	return (i);
}

static int	search(t_node *root, char **inputs)
{
	int		i;
	char	*keyword;
	t_node	*node;

	i = 0;
	while (inputs[i])
	{
		keyword = inputs[i++];
		node = avl_get(root, keyword);
		printf("%s\n", node->value);
	}
	return (i);
}

int	main(void)
{
	t_node	*root;
	int		i;

	char **inputs; // ["key1", "value1", "", "search1", "search2", NULL]
	inputs = read_stdin();
	i = insert(&root, inputs);
	search(root, inputs + i + 1);
	// free_all(inputs);
	free(inputs);
	return (0);
}
