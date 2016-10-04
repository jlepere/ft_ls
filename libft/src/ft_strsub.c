/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 09:57:35 by jlepere           #+#    #+#             */
/*   Updated: 2016/04/06 14:58:32 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*str;

	if (!ft_strlen(s))
		return (NULL);
	if (start > ft_strlen(s))
		len = -1;
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	ft_strncpy(str, s + start, len);
	return (str);
}
