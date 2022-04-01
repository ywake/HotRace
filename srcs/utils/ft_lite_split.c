/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lite_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 17:25:26 by ywake             #+#    #+#             */
/*   Updated: 2022/04/02 04:53:36 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#include <stdlib.h>
#include <unistd.h>

/**
 * No allocations except return char **.
 */
char	**ft_lite_split(char *s, char c)
{
	char		**buf;
	const char	*ptr;
	size_t		i;

	ptr = s;
	i = 2;
	while (*ptr)
		if (*ptr++ == c)
			++i;
	buf = (char **)malloc(sizeof(char *) * i);
	while (buf && i)
		buf[--i] = NULL;
	while (buf && *s)
	{
		if (buf[i] == NULL)
			buf[i] = s;
		if (*s == c)
		{
			*s = '\0';
			++i;
		}
		++s;
	}
	return (buf);
}

// #ifdef DEBUG

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char **a = ft_lite_split(strdup("this  is  test.    "), ' ');
// 	for (size_t i = 0; a[i]; i++)
// 	{
// 		printf("[%zu](%lu) %s\n", i, strlen(a[i]), a[i]);
// 	}
// 	return (0);
// }

// #endif
