/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:54:05 by ywake             #+#    #+#             */
/*   Updated: 2022/04/02 13:22:01 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG
# include "io.h"
#endif

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

// #define BUF_SIZE (1024 * 1024)
#define BUF_SIZE (10)

static char	**read_abort(char *read_buf, char *file)
{
	free(read_buf);
	free(file);
	return (NULL);
}

/**
 * @return ["key1", "value1", "", "search1", "search2", "", NULL] in heap
 */
char	**read_stdin(void)
{
	ssize_t	read_size;
	char	*read_buf;
	char	*file;
	char	**input;

	read_size = BUF_SIZE;
	file = NULL;
	read_buf = (char *)malloc(BUF_SIZE + 1);
	if (read_buf == NULL)
		return (read_abort(read_buf, file));
	while (read_size > 0)
	{
		read_size = read(STDIN_FILENO, read_buf, BUF_SIZE);
		read_buf[read_size] = '\0';
		if (read_size < 0)
			return (read_abort(read_buf, file));
		free_set((void **)&file, ft_strjoin(file, read_buf));
		if (file == NULL)
			return (read_abort(read_buf, file));
	}
	return (ft_lite_split(file, '\n'));
}
