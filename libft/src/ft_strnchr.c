/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 17:38:49 by jlepere           #+#    #+#             */
/*   Updated: 2016/04/06 15:28:23 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(char const *s, int c, size_t n)
{
	int	i;

	i = -1;
	while (*s)
	{
		if (*s == c)
		{
			while (++i < (int)n)
				s++;
			return ((char*)s);
		}
		s++;
	}
	if (!c)
		return ((char*)s++);
	return (NULL);
}
