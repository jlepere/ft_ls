/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:05:31 by jlepere           #+#    #+#             */
/*   Updated: 2016/04/13 19:37:32 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*list;

	list = (t_list*)ft_memalloc(sizeof(struct s_list));
	if (!list)
		return (NULL);
	if (!content)
	{
		list->content = NULL;
		content_size = 0;
	}
	else
	{
		list->content = (void*)ft_memalloc(content_size);
		ft_memcpy(list->content, content, content_size);
	}
	list->content_size = content_size;
	list->next = NULL;
	return (list);
}
