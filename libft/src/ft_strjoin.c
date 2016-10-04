/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 09:53:11 by jlepere           #+#    #+#             */
/*   Updated: 2015/12/16 20:56:20 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	char	*res;

	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	res = str;
	if (!str)
		return (NULL);
	while (*s2)
	{
		if (*s1)
			*str++ = *s1++;
		else
			*str++ = *s2++;
	}
	return (res);
}
