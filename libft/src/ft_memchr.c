/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 09:38:38 by jlepere           #+#    #+#             */
/*   Updated: 2015/12/16 20:18:58 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	sc;

	str = (unsigned char *)s;
	sc = c;
	while (n--)
	{
		if (*str == sc)
			return ((unsigned char *)str);
		str++;
	}
	return (NULL);
}
