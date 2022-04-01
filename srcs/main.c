/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:54:39 by ywake             #+#    #+#             */
/*   Updated: 2022/04/01 14:53:21 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avl.h"
#include "io.h"

static int insert_from_stdin(t_node *tree){
	while (改行出るまで){
	char *key = readline();
	char *value = readline();
	avl_insert(tree, key, value);
	}
}

static int search(t_node *root) {
	while (EOFまで)
	{
		char *keyword = readline();
		t_node *node = avl_get(keyword);
		printf("%s\n", node->value);
	}
}

int	main(void)
{
	t_node	*root;
	char	**input;  // ["key1", "value1", "", "search1", "search2", NULL]

	input = read_stdin();
	insert_from_stdin(root);
	search(root);
	free_all(input);
	return (0);
}
