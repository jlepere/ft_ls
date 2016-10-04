/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 11:51:20 by jlepere           #+#    #+#             */
/*   Updated: 2016/06/01 14:09:58 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_path.h"
#include "ft_ls_data.h"
#include "ft_ls_sort.h"
#include "ft_ls_util.h"
#include "ft_ls_view.h"
#include <dirent.h>

t_ls_path		*create_ls_path(char *name)
{
	t_ls_path	*ls_path;

	if (!(ls_path = ft_memalloc(sizeof(struct s_ls_path))))
		return (NULL);
	ls_path->name = ft_strdup(name);
	ls_path->bloc = 0;
	ls_path->user = 0;
	ls_path->grop = 0;
	ls_path->link = 0;
	ls_path->size = 0;
	ls_path->data = NULL;
	return (ls_path);
}

void			free_ls_path(t_ls_path *ls_path)
{
	if (!ls_path)
		return ;
	if (ls_path->name)
		ft_strdel(&ls_path->name);
	if (ls_path->data)
		free_ls_data(ls_path->data);
	ft_memdel((void**)&ls_path);
}

static t_cbuff	*check_ls_recursive(t_cbuff *ls_buff, t_ls_path *ls_path,
	t_ls_data *ls_data, t_ls_flag *ls_flag)
{
	char		*path;
	char		*new_path;
	char		*new_data;

	if (!ls_data)
		return (ls_buff);
	if (ls_data->left)
		ls_buff = check_ls_recursive(ls_buff, ls_path, ls_data->left, ls_flag);
	if (ls_data->mode && ls_data->mode[0] == 'd' &&
		ft_strcmp(ls_data->file_name, ".") && (ls_data->file_name[0] != '.' ||
		ls_flag->flag & FLAG_A) && ft_strcmp(ls_data->file_name, ".."))
	{
		path = ls_add_backslash(ls_path->name);
		new_path = ft_strjoin(path, ls_data->file_name);
		new_data = ft_strjoin(new_path, "\n");
		ft_cbuff_add(ls_buff, new_data);
		ft_strdel(&path);
		ft_strdel(&new_path);
		ft_strdel(&new_data);
		ls_flag->nb_dirs++;
	}
	if (ls_data->right)
		ls_buff = check_ls_recursive(ls_buff, ls_path, ls_data->right, ls_flag);
	return (ls_buff);
}

void			process_ls_recursive(t_cbuff *ls_buff, t_ls_flag *ls_flag)
{
	int		i;
	char	**argv;

	if (!ls_buff)
		return ;
	i = 0;
	argv = ft_strsplit(ls_buff->data, '\n');
	if (argv[0] && argv[1] && ls_flag->flag & FLAG_R)
		argv = sort_ls_argv_reverse(argv);
	ft_cbuff_free(ls_buff);
	while (argv[i])
		process_ls_path(argv[i++], ls_flag);
	ft_strdel_tab(argv);
}

void			*process_ls_path(char *path, t_ls_flag *ls_flag)
{
	t_cbuff			*ls_buff;
	t_ls_path		*new_path;
	DIR				*dir_open;
	struct dirent	*dir_read;

	ls_buff = NULL;
	new_path = create_ls_path(path);
	view_ls_path(new_path, ls_flag, 1);
	if (!(dir_open = opendir(path)))
		return (ls_perror(path));
	while ((dir_read = readdir(dir_open)))
		new_path = process_ls_data(new_path, ls_flag, dir_read->d_name);
	closedir(dir_open);
	view_ls_path(new_path, ls_flag, 0);
	if (ls_flag->flag & FLAG_BR)
	{
		if (!ls_buff)
			ls_buff = ft_cbuff_new();
		ls_buff = check_ls_recursive(ls_buff, new_path, new_path->data,
				ls_flag);
	}
	free_ls_path(new_path);
	if (ls_flag->flag & FLAG_BR)
		process_ls_recursive(ls_buff, ls_flag);
	return (NULL);
}
