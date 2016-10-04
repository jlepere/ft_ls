/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 10:05:43 by jlepere           #+#    #+#             */
/*   Updated: 2015/12/16 20:40:32 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	if (!ft_strlen(s2))
		return ((char*)s1);
	i = 0;
	while (s1[i] && i < n)
	{
		j = 0;
		if (s2[j] == s1[i + j])
		{
			while ((s2[j] == s1[i + j]) && (i + j) < n)
			{
				if (!s2[j + 1])
					return ((char*)s1 + i);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
