/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywake <ywake@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:31:07 by ywake             #+#    #+#             */
/*   Updated: 2022/04/03 15:43:32 by ywake            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

# include "utils.h"

t_list	*read_stdin(void);
t_list	*file_to_lines(t_list **head);
int		add_to_buffer(t_list **buf, char *str);
void	flush_buffer(t_list *buf);

#endif
