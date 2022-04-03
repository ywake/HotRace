/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:54:05 by ywake             #+#    #+#             */
/*   Updated: 2022/04/03 10:57:31 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG
# include "io.h"
#endif

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

#define BUF_SIZE (1048576)

static char	**read_abort(char *file)
{
	free(file);
	return (NULL);
}

/**
 * @return ["key1", "value1", "", "search1", "search2", "", NULL] in heap
 */
char	**read_stdin(void)
{
	ssize_t	read_size;
	char	read_buf[BUF_SIZE];
	char	*file;

	read_size = BUF_SIZE;
	file = NULL;
	while (read_size > 0)
	{
		read_size = read(STDIN_FILENO, read_buf, BUF_SIZE);
		read_buf[read_size] = '\0';
		if (read_size < 0)
			return (read_abort(file));
		free_set((void **)&file, ft_strjoin(file, read_buf));
		if (file == NULL)
			return (read_abort(file));
	}
	return (ft_lite_split(file, '\n'));
}
