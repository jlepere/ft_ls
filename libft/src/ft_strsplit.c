/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 09:56:53 by jlepere           #+#    #+#             */
/*   Updated: 2016/04/13 19:36:43 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_wordlen(const char *s, char c)
{
	int	res;
	int	beg;

	res = 0;
	beg = 0;
	while (*s)
	{
		if (*s != c && !beg)
		{
			res++;
			beg++;
		}
		else if (*s == c && beg)
			beg--;
		s++;
	}
	return (res);
}

static int	ft_wordend(const char *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[i + count] != 0 && s[i + count] != c)
		count++;
	return (count);
}

char		**ft_strsplit(const char *s, char c)
{
	int		i;
	int		j;
	int		add;
	int		end;
	char	**str;

	i = 0;
	j = 0;
	add = ft_wordlen(s, c);
	str = (char**)ft_memalloc(sizeof(char*) * (add + 1));
	if (!str)
		return (NULL);
	while (s[i] != 0 && add)
	{
		if (s[i] != c)
		{
			end = ft_wordend(s, c, i);
			str[j++] = ft_strsub(s, i, end);
			i += end;
			add--;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
