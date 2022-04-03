/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 17:00:13 by ywake             #+#    #+#             */
/*   Updated: 2022/04/03 13:44:02 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#include <stddef.h>

int	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == NULL)
		return (-1);
	new->next = *lst;
	*lst = new;
	return (0);
}
