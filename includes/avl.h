/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:43:43 by ywake             #+#    #+#             */
/*   Updated: 2022/04/01 17:12:12 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_H
# define AVL_H

typedef struct s_node
{
	char			*key;
	char			*value;

	struct s_node	*left;
	struct s_node	*right;

}	t_node;

t_node	*avl_insert(t_node *root, char *key, char *value);
t_node	*avl_get(t_node *root, char *key);

#endif
