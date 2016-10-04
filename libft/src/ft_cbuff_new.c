/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cbuff_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 15:32:59 by jlepere           #+#    #+#             */
/*   Updated: 2016/05/11 15:12:13 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cbuff	*ft_cbuff_new(void)
{
	t_cbuff	*buff;

	buff = (t_cbuff*)ft_memalloc(sizeof(struct s_cbuff));
	buff->data = (char*)ft_strnew(1);
	buff->size = 0;
	buff->count = 0;
	return (buff);
}
