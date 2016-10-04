/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:33:22 by jlepere           #+#    #+#             */
/*   Updated: 2016/06/01 15:44:27 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_view.h"
#include "ft_ls_util.h"
#include "libft.h"
#include <time.h>

static void	view_ls_time(t_ls_data *ls_data, char **date_str, char **time_str)
{
	time_t	time_now;
	char	*year_str;

	year_str = NULL;
	time_now = time(NULL);
	if (time_now - ls_data->date >= 15552000 ||
			ls_data->date - time_now <= -15552000)
	{
		year_str = ft_strnew(4);
		ft_putchar(' ');
		ft_putstr(ft_strncpy(year_str, date_str[4], 4));
		if (year_str)
			ft_strdel(&year_str);
	}
	else
	{
		ft_putstr(time_str[0]);
		ft_putchar(':');
		ft_putstr(time_str[1]);
	}
}

static void	view_ls_date(t_ls_data *ls_data)
{
	char	**date_str;
	char	**time_str;

	if (!ls_data->date)
		return ;
	date_str = ft_strsplit(ctime(&ls_data->date), ' ');
	time_str = ft_strsplit(date_str[3], ':');
	ft_putstr(date_str[1]);
	ft_putchar(' ');
	if (ft_strlen(date_str[2]) == 1)
		ft_putchar(' ');
	ft_putstr(date_str[2]);
	ft_putchar(' ');
	view_ls_time(ls_data, date_str, time_str);
	ft_putchar(' ');
	ft_strdel_tab(date_str);
	ft_strdel_tab(time_str);
}

static void	view_ls_stat(t_ls_path *ls_path, t_ls_data *ls_data)
{
	if (!ls_data->mode || !ls_data->user || !ls_data->grop)
		return ;
	ft_putstr(ls_data->mode);
	ft_putstr("  ");
	if (ls_path)
		ls_add_space(ls_path->link, ft_intlen(ls_data->link));
	ft_putnbr(ls_data->link);
	ft_putchar(' ');
	ft_putstr(ls_data->user);
	if (ls_path)
		ls_add_space(ls_path->user, ft_strlen(ls_data->user));
	ft_putstr("  ");
	ft_putstr(ls_data->grop);
	if (ls_path)
		ls_add_space(ls_path->grop, ft_strlen(ls_data->grop));
	ft_putstr("  ");
	if (ls_path)
		ls_add_space(ls_path->size, ft_intlen(ls_data->size));
	ft_putnbr(ls_data->size);
	ft_putchar(' ');
	view_ls_date(ls_data);
}

void		view_ls_data(t_ls_path *ls_path, t_ls_data *ls_data,
		t_ls_flag *ls_flag)
{
	if (!ls_path || !ls_data || !ls_flag)
		return ;
	if (ls_data->left && !(ls_flag->flag & FLAG_R))
		view_ls_data(ls_path, ls_data->left, ls_flag);
	else if (ls_data->right && ls_flag->flag & FLAG_R)
		view_ls_data(ls_path, ls_data->right, ls_flag);
	if ((ls_data->file_name[0] != '.' && ft_strcmp(ls_data->file_name, ".") &&
			ft_strcmp(ls_data->file_name, "..")) || ls_flag->flag & FLAG_A)
	{
		if (ls_flag->flag & FLAG_L)
			view_ls_stat(ls_path, ls_data);
		ft_putstr(ls_data->file_name);
		if (ls_flag->flag & FLAG_L && ls_data->mode[0] == 'l')
		{
			ft_putstr(" -> ");
			ft_putstr(ls_data->link_name);
		}
		ft_putchar('\n');
	}
	if (ls_data->right && !(ls_flag->flag & FLAG_R))
		view_ls_data(ls_path, ls_data->right, ls_flag);
	else if (ls_data->left && ls_flag->flag & FLAG_R)
		view_ls_data(ls_path, ls_data->left, ls_flag);
}

void		view_ls_path(t_ls_path *ls_path, t_ls_flag *ls_flag, char path)
{
	static int	nb_dirs = 0;

	if (!ls_path)
		return ;
	if (ls_path->name && path &&
			(ls_flag->nb_dirs > 1 || (ls_flag->argc - ls_flag->nb_dirs)))
	{
		if (nb_dirs > 0 || (ls_flag->argc - ls_flag->nb_dirs))
			ft_putchar('\n');
		ft_putstr(ls_path->name);
		ft_putendl(":");
	}
	if (ls_flag->flag & FLAG_L && !path)
	{
		ft_putstr("total ");
		ft_putnbr(ls_path->bloc);
		ft_putchar('\n');
	}
	view_ls_data(ls_path, ls_path->data, ls_flag);
	if (path)
		nb_dirs++;
}
