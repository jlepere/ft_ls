/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cbuff_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 15:29:59 by jlepere           #+#    #+#             */
/*   Updated: 2016/04/06 16:07:32 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_cbuff_resize(t_cbuff *buff, unsigned int size)
{
	int		c;
	char	*tmp_buff;
	char	*new_buff;

	c = -1;
	new_buff = ft_strnew(size);
	while (++c < (int)buff->count)
		new_buff[c] = buff->data[c];
	tmp_buff = buff->data;
	buff->data = new_buff;
	buff->size = size;
	ft_strdel(&tmp_buff);
}

void		ft_cbuff_add(t_cbuff *buff, char *str)
{
	int	c;
	int	size;

	c = -1;
	size = ft_strlen(str);
	if (buff->count + size >= buff->size)
		ft_cbuff_resize(buff, buff->size + size);
	while (++c < size)
		buff->data[buff->count++] = str[c];
}
