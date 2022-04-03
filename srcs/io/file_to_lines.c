/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:02:35 by ywake             #+#    #+#             */
/*   Updated: 2022/04/03 17:42:43 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

#include <stdlib.h>
#include "utils.h"

static t_list	*f2l_abort(t_list *file, t_list *lines, char **split)
{
	free(split);
	ft_lstclear(&file, free);
	ft_lstclear(&lines, NULL);
	return (NULL);
}

static int	cat_and_replace(t_list **head, t_list *line, char *second)
{
	char	*first;
	char	*cat;

	first = (char *)line->content;
	cat = ft_strjoin(first, second);
	if (cat == NULL)
		return (-1);
	if (ft_lstadd_front(head, ft_lstnew(cat)))
		return (-1);
	line->content = (*head)->content;
	return (0);
}

enum e_f2l
{
	FILE,
	LINES,
	LEN
};

t_list	*file_to_lines(t_list **head)
{
	t_list	*list[LEN];
	char	**split;
	size_t	i;
	bool	end_is_sep;

	list[FILE] = *head;
	list[LINES] = NULL;
	end_is_sep = 0;
	while (list[FILE])
	{
		split = ft_lite_split((char *)list[FILE]->content, '\n', &end_is_sep);
		i = 0;
		while (split[i])
		{
			if (list[LINES] && i == 0 && !end_is_sep)
				cat_and_replace(head, list[LINES], split[0]);
			else if (ft_lstadd_front(&list[LINES], ft_lstnew(split[i])))
				return (f2l_abort(list[FILE], list[LINES], split));
			i++;
		}
		free(split);
		list[FILE] = list[FILE]->next;
	}
	ft_lst_reverse(&list[LINES]);
	return (list[LINES]);
}
