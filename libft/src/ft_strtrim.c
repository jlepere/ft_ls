/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 09:57:49 by jlepere           #+#    #+#             */
/*   Updated: 2015/12/16 20:56:57 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	int		i;
	int		t;
	size_t	e;

	i = -1;
	t = -1;
	e = 0;
	if (!ft_strlen(s))
		return ("\0");
	while (s[++i])
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
		{
			if (t < 0)
				t = i;
			e = i;
		}
		if (!s[i + 1] && t < 0)
			return ("\0");
	}
	return (ft_strsub(s, t, e - t + 1));
}
