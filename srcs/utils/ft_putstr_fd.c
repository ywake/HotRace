/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 12:41:22 by ywake             #+#    #+#             */
/*   Updated: 2022/04/02 02:19:08 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#include "unistd.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	byte;

	if (s == NULL)
		return ;
	byte = 0;
	while (s[byte])
		byte++;
	write(fd, s, byte);
}
