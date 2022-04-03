/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:54:05 by ywake             #+#    #+#             */
/*   Updated: 2022/04/03 22:47:10 by ywake            ###   ########.fr       */
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

static void	store(t_list **file, char *read_buf, char **remain, t_list **gc)
{
	char	*ptr;

	ptr = NULL;
	if (*remain)
		*remain = ft_strjoin(*remain, read_buf);
	else
		*remain = read_buf;
	if (*remain != read_buf)
		free(read_buf);
	ft_lstadd_front(gc, ft_lstnew(*remain));
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

enum e_char
{
	BUF,
	REMAIN,
	CHAR_LEN
};

/**
 * @return ["key1", "value1", "", "search1", "search2", "", NULL] in heap
 */
t_list	*read_stdin(t_list **gc)
{
	ssize_t	read_size;
	t_list	*file;
	char	*s[CHAR_LEN];

	read_size = 1;
	file = NULL;
	s[REMAIN] = NULL;
	while (read_size > 0)
	{
		s[BUF] = (char *)malloc(sizeof(char) * (BUF_SIZE + 1));
		if (s[BUF] == NULL)
			return (read_abort(s[BUF], file));
		read_size = read(STDIN_FILENO, s[BUF], BUF_SIZE);
		if (read_size < 0)
			return (read_abort(s[BUF], file));
		s[BUF][read_size] = '\0';
		store(&file, s[BUF], &s[REMAIN], gc);
	}
	if (s[REMAIN] && s[REMAIN][0])
		ft_lstadd_front(&file, ft_lstnew(s[REMAIN]));
	ft_lst_reverse(&file);
	return (file);
}
