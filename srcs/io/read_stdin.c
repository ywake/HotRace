/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:54:05 by ywake             #+#    #+#             */
/*   Updated: 2022/04/03 17:48:44 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG
# include "io.h"
#endif

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

#define BUF_SIZE (104857600)
// #define BUF_SIZE (2)

static t_list	*read_abort(char *read_buf, t_list *file)
{
	free(read_buf);
	ft_lstclear(&file, free);
	return (NULL);
}

/**
 * @return ["key1", "value1", "", "search1", "search2", "", NULL] in heap
 */
t_list	*read_stdin(void)
{
	ssize_t	read_size;
	char	*read_buf;
	t_list	*file;

	read_size = 1;
	file = NULL;
	while (read_size > 0)
	{
		read_buf = (char *)malloc(sizeof(char) * (BUF_SIZE + 1));
		if (read_buf == NULL)
			return (read_abort(read_buf, file));
		read_size = read(STDIN_FILENO, read_buf, BUF_SIZE);
		if (read_size < 0)
			return (read_abort(read_buf, file));
		read_buf[read_size] = '\0';
		if (ft_lstadd_front(&file, ft_lstnew(read_buf)))
			return (read_abort(read_buf, file));
	}
	ft_lst_reverse(&file);
	return (file);
}
