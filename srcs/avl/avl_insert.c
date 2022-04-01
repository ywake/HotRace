/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:18:32 by ywake             #+#    #+#             */
/*   Updated: 2022/04/01 18:05:37 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "avl.h"

static t_node* avl_rotate_left(t_node *root);
static t_node* avl_rotate_right(t_node *root);
static t_node* avl_rotate_left_right(t_node *root);
static t_node* avl_rotate_right_left(t_node *root);
static size_t avl_get_height(t_node *root);

t_node	*avl_insert(t_node *root, char *key, char *value) {
	// 挿入する場所までたどる
	if (ft_strcmp(key, root->key) > 0 && root->right){
		avl_insert(root->right, key, value);
	} else if (ft_strcmp(key, root->key) < 0 && root->left){
		avl_insert(root->left, key, value);
	} else if (ft_strcmp(key, root->key) == 0) {
		free(root->value);
		root->value = value;
		return root;
	}

	t_node *node = malloc(sizeof(t_node));
	node->key = key;
	node->value = value;
	// 挿入する
	if (ft_strcmp(key, root->key) > 0){
		root->right = node;
	} else {
		root->left = node;
	}

	// 平衡係数を計算して必要あれば回転する
}

static size_t avl_get_height(t_node *root) {
	size_t left_height;
	size_t right_height;
	size_t height;

	if (!root) {
		return 0;
	}
	left_height = avl_get_height(root->left);
	right_height = avl_get_height(root->right);
	if (left_height > right_height)
		height = left_height;
	else
		height = right_height;
	return height + 1;
}

static t_node* avl_rotate_left(t_node *root) {
	t_node *pivot;

	pivot = root->right;
	if (pivot) {
		root->right = pivot->left;
		pivot->left = root;
	}
	return pivot;
}

static t_node* avl_rotate_right(t_node *root) {
	t_node *pivot;

	pivot = root->left;
	if (pivot) {
		root->left = pivot->right;
		pivot->right = root;
	}
	return pivot;
}

static t_node* avl_rotate_left_right(t_node *root) {
	t_node *pivot;

	pivot = avl_rotate_left(root->left);
	root->left = pivot;
	pivot = avl_rotate_right(root);
	return pivot;
}

static t_node* avl_rotate_right_left(t_node *root) {
	t_node *pivot;

	pivot = avl_rotate_right(root->right);
	root->right = pivot;
	pivot = avl_rotate_left(root);
	return pivot;
}
