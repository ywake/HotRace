/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 04:35:06 by ywake             #+#    #+#             */
/*   Updated: 2022/04/01 14:21:25 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#include <stddef.h>

void	ft_lst_reverse(t_list **lst)
{
	t_list	*first_one;
	t_list	*ans;

	ans = NULL;
	while (*lst)
	{
		first_one = (*lst);
		*lst = (*lst)->next;
		first_one->next = NULL;
		ft_lstadd_front(&ans, first_one);
	}
	*lst = ans;
}
