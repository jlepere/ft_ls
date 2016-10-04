/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 10:03:24 by jlepere           #+#    #+#             */
/*   Updated: 2015/12/16 20:29:47 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*sdst;

	sdst = dst;
	while (*src && n > 0)
	{
		*sdst++ = *src++;
		n--;
	}
	while (n-- > 0)
		*sdst++ = 0;
	return (dst);
}
