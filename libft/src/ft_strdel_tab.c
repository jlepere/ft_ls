/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 15:54:15 by jlepere           #+#    #+#             */
/*   Updated: 2016/04/06 16:06:08 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_strdel_tab(char **as)
{
	int	i;

	if (!as)
		return ;
	i = -1;
	while (as[++i])
		ft_strdel(&as[i]);
	free(as);
}
