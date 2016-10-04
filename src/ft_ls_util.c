/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:24:55 by jlepere           #+#    #+#             */
/*   Updated: 2016/06/01 14:31:56 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_util.h"
#include "libft.h"
#include <stdio.h>

void	*ls_perror(char *file)
{
	ft_putstr("ft_ls: ");
	perror(file);
	return (NULL);
}

void	ls_add_space(int ls_path, int ls_data)
{
	int	tab;

	tab = ls_path - ls_data;
	while (tab-- > 0)
		ft_putchar(' ');
}

char	*ls_add_backslash(char *str)
{
	if (str[ft_strlen(str) - 1] == '/')
		return (ft_strdup(str));
	return (ft_strjoin(str, "/"));
}
