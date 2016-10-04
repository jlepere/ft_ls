/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 12:05:31 by jlepere           #+#    #+#             */
/*   Updated: 2016/06/01 12:13:19 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_argv.h"
#include "ft_ls_path.h"
#include "ft_ls_data.h"
#include "ft_ls_view.h"
#include "ft_ls_util.h"
#include "libft.h"
#include <sys/stat.h>
#include <dirent.h>

static t_cbuff	*process_ls_dirs(t_cbuff *ls_buff, t_ls_flag *ls_flag,
		char *path)
{
	char	*new_path;

	if (!ls_buff)
		ls_buff = ft_cbuff_new();
	new_path = ft_strjoin(path, "\n");
	ft_cbuff_add(ls_buff, new_path);
	ft_strdel(&new_path);
	ls_flag->nb_dirs++;
	return (ls_buff);
}

static char		process_ls_link(char *link)
{
	DIR	*dir_open;

	if (!(dir_open = opendir(link)))
		return (1);
	closedir(dir_open);
	return (0);
}

void			process_ls_argv(t_ls_flag *ls_flag)
{
	int			i;
	struct stat	ls_stat;
	t_cbuff		*ls_dirs;
	t_ls_path	*ls_files;

	i = 0;
	ls_dirs = NULL;
	ls_files = NULL;
	while (ls_flag->argv[i])
	{
		if (lstat(ls_flag->argv[i], &ls_stat))
			ls_perror(ls_flag->argv[i]);
		else if (S_ISDIR(ls_stat.st_mode) || (S_ISLNK(ls_stat.st_mode) &&
					!process_ls_link(ls_flag->argv[i]) &&
					!(ls_flag->flag & FLAG_L)))
			ls_dirs = process_ls_dirs(ls_dirs, ls_flag, ls_flag->argv[i]);
		else if (S_ISREG(ls_stat.st_mode) || S_ISLNK(ls_stat.st_mode))
			ls_files = process_ls_data(ls_files, ls_flag, ls_flag->argv[i]);
		i++;
	}
	if (ls_files)
		view_ls_data(ls_files, ls_files->data, ls_flag);
	process_ls_recursive(ls_dirs, ls_flag);
}
