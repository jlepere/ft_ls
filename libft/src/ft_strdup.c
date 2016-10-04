/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 10:02:55 by jlepere           #+#    #+#             */
/*   Updated: 2015/12/16 20:27:47 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		c;
	char	*str;

	c = 0;
	str = ft_strnew(ft_strlen(s1));
	if (!str)
		return (NULL);
	while (*s1)
		str[c++] = *s1++;
	str[c] = 0;
	return (str);
}
