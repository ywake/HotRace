/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 07:48:12 by ywake             #+#    #+#             */
/*   Updated: 2022/04/02 03:16:50 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buf;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	while (s1 != NULL && s1[len1])
		len1++;
	len2 = 0;
	while (s2 != NULL && s2[len2])
		len2++;
	buf = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	buf[len1 + len2] = '\0';
	while (len2--)
		buf[len1 + len2] = s2[len2];
	while (len1--)
		buf[len1] = s1[len1];
	return (buf);
}
