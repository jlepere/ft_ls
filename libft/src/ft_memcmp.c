/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 09:58:51 by jlepere           #+#    #+#             */
/*   Updated: 2015/12/16 20:21:46 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				res;
	unsigned char	*cs1;
	unsigned char	*cs2;

	res = 0;
	cs1 = (unsigned char*)s1;
	cs2 = (unsigned char*)s2;
	while (n-- && res == 0)
		res = (*cs1++) - (*cs2++);
	return (res);
}
