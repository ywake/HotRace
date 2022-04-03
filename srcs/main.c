/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:54:39 by ywake             #+#    #+#             */
/*   Updated: 2022/04/03 17:39:05 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avl.h"
#include "io.h"
#include "utils.h"

#include <stdlib.h>
#include <stdbool.h>

static int	insert(t_node **tree, t_list *lines)
{
	int		i;
	char	*key;
	char	*value;

	key = NULL;
	value = NULL;
	i = 0;
	while (lines && ((char *)lines->content)[0])
	{
		if (i % 2 == 0)
			key = ((char *)lines->content);
		else
		{
			value = ((char *)lines->content);
			if (avl_insert(tree, key, value) == NULL)
				return (-1);
			key = NULL;
			value = NULL;
		}
		lines = lines->next;
		i++;
	}
	return (0);
}

static int	search(t_list	**buf, t_node *root, t_list *lines)
{
	char	*keyword;
	t_node	*node;
	bool	err;

	while (lines && ((char *)lines->content)[0])
		lines = lines->next;
	lines = lines->next;
	err = false;
	while (lines)
	{
		keyword = (char *)lines->content;
		node = avl_get(root, keyword);
		if (node)
			err = err || add_to_buffer(buf, node->value);
		else
		{
			err = err || add_to_buffer(buf, keyword);
			err = err || add_to_buffer(buf, ": Not found.");
		}
		err = err || add_to_buffer(buf, "\n");
		lines = lines->next;
	}
	ft_lst_reverse(buf);
	return (-err);
}

int	main(void)
{
	t_list	*file;
	t_list	*lines;
	t_node	*root;
	t_list	*out_buf;

	file = read_stdin();
	if (file == NULL)
		return (1);
	lines = file_to_lines(&file);
	root = NULL;
	if (insert(&root, lines) == 0)
	{
		out_buf = NULL;
		if (search(&out_buf, root, lines) == 0)
		{
			flush_buffer(out_buf);
		}
	}
	avl_free_tree(root);
	ft_lstclear(&out_buf, NULL);
	ft_lstclear(&lines, NULL);
	ft_lstclear(&file, free);
	return (0);
}
