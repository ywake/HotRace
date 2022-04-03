/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:13:05 by ywake             #+#    #+#             */
/*   Updated: 2022/04/03 14:17:24 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include <sys/types.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;

}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *elem);
void	ft_lst_reverse(t_list **lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));

size_t	ft_strlen(const char *s);
int		ft_strcmp(char const *s1, char const *s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_lite_split(char *s, char c);
void	ft_putstr_fd(char *s, int fd);

void	free_set(void **dst, void *src);

ssize_t	get_time(void);

#endif
