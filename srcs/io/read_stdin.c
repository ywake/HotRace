/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:54:05 by ywake             #+#    #+#             */
/*   Updated: 2022/04/03 21:48:31 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

#define BUF_SIZE (1048576)
// #define BUF_SIZE (3)

static t_list	*read_abort(char *read_buf, t_list *file)
{
	free(read_buf);
	ft_lstclear(&file, free);
	return (NULL);
}

static void	store(t_list **file, char *read_buf, char **remain)
{
	char	*ptr;

	ptr = NULL;
	if (*remain)
	{
		*remain = ft_strjoin(*remain, read_buf);
		free(read_buf);
	}
	else
		*remain = read_buf;
	while (1)
	{
		ptr = ft_strchr(*remain, '\n');
		if (ptr == NULL)
			break ;
		*ptr = '\0';
		ft_lstadd_front(file, ft_lstnew(*remain));
		if (ptr[1] != '\0')
			*remain = ptr + 1;
		else
		{
			*remain = NULL;
			break ;
		}
	}
}

/**
 * @return ["key1", "value1", "", "search1", "search2", "", NULL] in heap
 */
t_list	*read_stdin(void)
{
	ssize_t	read_size;
	char	*read_buf;
	t_list	*file;
	char	*remain;

	read_size = 1;
	file = NULL;
	remain = NULL;
	while (read_size > 0)
	{
		read_buf = (char *)malloc(sizeof(char) * (BUF_SIZE + 1));
		if (read_buf == NULL)
			return (read_abort(read_buf, file));
		read_size = read(STDIN_FILENO, read_buf, BUF_SIZE);
		if (read_size < 0)
			return (read_abort(read_buf, file));
		read_buf[read_size] = '\0';
		store(&file, read_buf, &remain);
	}
	if (remain && remain[0])
		ft_lstadd_front(&file, ft_lstnew(remain));
	ft_lst_reverse(&file);
	return (file);
}
