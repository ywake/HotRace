/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:54:39 by ywake             #+#    #+#             */
/*   Updated: 2022/04/01 13:21:54 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avl.h"

static int insert_from_stdin(t_node *tree){
	while (改行出るまで){
	key = readline();
	value = readline();
	avl_insert(tree, key, value);
	}
}

static int search(t_node *tree) {
	while (EOFまで)
	{
		char *keyword = readline();
		t_node *node = avl_get(keyword);
		printf("%s\n", node->value);
	}
}

int	main(void)
{
	insert_from_stdin();
	search();
	return (0);
}
