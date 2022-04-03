/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:54:05 by ywake             #+#    #+#             */
/*   Updated: 2022/04/03 14:53:53 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG
# include "io.h"
#endif

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

#define BUF_SIZE (1048576)

static char	**read_abort(char *file)
{
	free(file);
	return (NULL);
}

enum e_time
{
	START,
	FIRST,
	READ,
	SPLIT,
	STRJOIN,
	END,
	LEN
};

/**
 * @return ["key1", "value1", "", "search1", "search2", "", NULL] in heap
 */
char	**read_stdin(void)
{
	ssize_t	read_size;
	char	read_buf[BUF_SIZE];
	char	*file;
	ssize_t	times[LEN];

	read_size = BUF_SIZE;
	file = NULL;
	times[FIRST] = get_time();
	times[READ] = 0;
	times[STRJOIN] = 0;
	while (read_size > 0)
	{
		times[START] = get_time();
		read_size = read(STDIN_FILENO, read_buf, BUF_SIZE);
		read_buf[read_size] = '\0';
		times[READ] += get_time() - times[START];
		if (read_size < 0)
			return (read_abort(file));
		times[START] = get_time();
		free_set((void **)&file, ft_strjoin(file, read_buf));
		times[STRJOIN] += get_time() - times[START];
		if (file == NULL)
			return (read_abort(file));
	}
	times[END] = get_time();
	char **tmp = ft_lite_split(file, '\n');

	fprintf(stderr, "===== in READ =====\n");
	fprintf(stderr, "TOTAL: %zd\n", times[END] - times[FIRST]);
	fprintf(stderr, "read(): %zd\n", times[READ]);
	fprintf(stderr, "strjoin(): %zd\n", times[STRJOIN]);
	fprintf(stderr, "===================\n");
	return (tmp);
}
