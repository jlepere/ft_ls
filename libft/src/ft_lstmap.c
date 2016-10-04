/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:37:18 by jlepere           #+#    #+#             */
/*   Updated: 2015/12/04 09:57:19 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*last;
	t_list	*current;

	last = NULL;
	current = NULL;
	while (lst)
	{
		list = (*f)(lst);
		if (!list)
			return (NULL);
		if (!current)
			current = list;
		if (last)
			last->next = list;
		last = list;
		list = list->next;
		lst = lst->next;
	}
	return (current);
}
