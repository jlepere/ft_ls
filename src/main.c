/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:27:20 by jlepere           #+#    #+#             */
/*   Updated: 2016/06/01 15:07:44 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_argv.h"
#include "ft_ls_flag.h"
#include "ft_ls_sort.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_ls_flag	*ls_flag;

	(void)argc;
	ls_flag = create_ls_flag();
	ls_flag = parse_ls_argv(ls_flag, argv);
	if (ls_flag->argc != -1)
	{
		if (ls_flag->argc > 1)
			ls_flag->argv = sort_ls_argv_alpha(ls_flag->argv);
		process_ls_argv(ls_flag);
	}
	if (ls_flag && ls_flag->argv)
		ft_strdel_tab(ls_flag->argv);
	if (ls_flag)
		ft_memdel((void**)&ls_flag);
	return (0);
}
