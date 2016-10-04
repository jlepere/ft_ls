/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 14:29:56 by jlepere           #+#    #+#             */
/*   Updated: 2016/05/31 11:29:52 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_flag.h"
#include "ft_ls_util.h"
#include "libft.h"

t_ls_flag			*create_ls_flag(void)
{
	t_ls_flag	*ls_flag;

	if (!(ls_flag = ft_memalloc(sizeof(struct s_ls_flag))))
		return (NULL);
	ls_flag->argv = NULL;
	ls_flag->argc = 0;
	ls_flag->flag = 0;
	ls_flag->end = 0;
	ls_flag->nb_dirs = 0;
	return (ls_flag);
}

static t_ls_flag	*parse_ls_error(t_ls_flag *ls_flag, char flag)
{
	ls_flag->argc = -1;
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(flag);
	ft_putchar('\n');
	ft_putendl("usage: ./ft_ls [-Ralrt] [file ...]");
	return (ls_flag);
}

static t_ls_flag	*parse_ls_flag(t_ls_flag *ls_flag, char *argv)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (argv[i] == 'R')
			ls_flag->flag |= FLAG_BR;
		else if (argv[i] == 'a')
			ls_flag->flag |= FLAG_A;
		else if (argv[i] == 'l')
			ls_flag->flag |= FLAG_L;
		else if (argv[i] == 'r')
			ls_flag->flag |= FLAG_R;
		else if (argv[i] == 't')
			ls_flag->flag |= FLAG_T;
		else if (argv[i] == '1')
			ls_flag->flag = ls_flag->flag;
		else if (argv[i] != '-' || (argv[i] == '-' && i > 1))
			return (parse_ls_error(ls_flag, argv[i]));
		else if (argv[i] == '-')
			ls_flag->end = 1;
	}
	return (ls_flag);
}

static t_cbuff		*add_ls_argv(t_ls_flag *ls_flag,
	t_cbuff *ls_buff, char *argv)
{
	char	*data;

	data = NULL;
	if (!ls_buff)
		ls_buff = ft_cbuff_new();
	data = ft_strjoin(argv, "\n");
	ft_cbuff_add(ls_buff, data);
	ft_strdel(&data);
	if (ls_flag->argc != -1)
		ls_flag->argc++;
	return (ls_buff);
}

t_ls_flag			*parse_ls_argv(t_ls_flag *ls_flag, char **argv)
{
	int		i;
	int		end;
	t_cbuff	*ls_buff;

	i = 1;
	end = 0;
	ls_buff = NULL;
	while (argv[i])
	{
		if (!ls_flag->end && argv[i][0] == '-' && argv[i][1] && !ls_buff)
			ls_flag = parse_ls_flag(ls_flag, argv[i]);
		else
			ls_buff = add_ls_argv(ls_flag, ls_buff, argv[i]);
		i++;
	}
	if (!argv[1] || !ls_buff)
		ls_buff = add_ls_argv(ls_flag, ls_buff, ".");
	ls_flag->argv = ft_strsplit(ls_buff->data, '\n');
	ft_cbuff_free(ls_buff);
	return (ls_flag);
}
