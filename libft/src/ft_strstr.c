/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 10:05:04 by jlepere           #+#    #+#             */
/*   Updated: 2015/12/16 20:39:16 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*cs1;
	char	*cs2;

	if (!*s2)
		return ((char*)s1);
	while (*s1)
	{
		cs1 = (char*)s1;
		cs2 = (char*)s2;
		while (*cs2 && *cs1 == *cs2)
		{
			cs1++;
			cs2++;
		}
		if (!*cs2)
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
