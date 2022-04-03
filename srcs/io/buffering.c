/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 08:35:20 by ywake             #+#    #+#             */
/*   Updated: 2022/04/03 10:00:13 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

#include <stdlib.h>
#include "utils.h"

/**
 * @brief If malloc fails, buf will be clear.
 * @return Reversed(!) list. (elem can be null.)
 */
int	add_to_buffer(t_list **buf, char *str)
{
	t_list	*elem;

	elem = ft_lstnew(str);
	if (elem == NULL)
	{
		ft_lstclear(buf, free);
		*buf = NULL;
		return (-1);
	}
	ft_lstadd_front(buf, elem);
	return (0);
}

size_t	my_strcpy(char *dst, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

void	flush_buffer(t_list *buf)
{
	t_list	*count;
	char	*concat;
	size_t	size;
	size_t	i;

	size = 0;
	count = buf;
	while (count)
	{
		size += ft_strlen((char *)count->content);
		count = count->next;
	}
	concat = (char *)malloc(sizeof(char) * size + 1);
	i = 0;
	while (buf)
	{
		i += my_strcpy(&concat[i], (char *)buf->content);
		buf = buf->next;
	}
	ft_putstr_fd(concat, 1);
	free(concat);
}
