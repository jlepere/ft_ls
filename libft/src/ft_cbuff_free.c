/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cbuff_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 15:36:50 by jlepere           #+#    #+#             */
/*   Updated: 2016/04/06 16:06:49 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cbuff_free(t_cbuff *buffer)
{
	if (!buffer)
		return ;
	if (buffer->data)
		ft_strdel(&buffer->data);
	ft_memdel((void**)&buffer);
}
