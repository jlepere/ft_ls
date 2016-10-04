/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 09:45:09 by jlepere           #+#    #+#             */
/*   Updated: 2016/01/05 10:12:57 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		i;
	size_t	nb;
	char	*str;

	nb = n;
	if (n < 0)
		nb *= -1;
	i = ft_intlen(n);
	str = ft_strnew(i);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	if (!str)
		return (NULL);
	str[0] = '-';
	i--;
	while (nb > 0)
	{
		str[i--] = nb % 10 + 48;
		nb /= 10;
	}
	if (n == 0)
		str[0] = 48;
	return (str);
}
