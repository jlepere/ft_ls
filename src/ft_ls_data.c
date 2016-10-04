/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 11:34:20 by jlepere           #+#    #+#             */
/*   Updated: 2016/05/31 12:17:35 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_data.h"
#include "ft_ls_stat.h"
#include "ft_ls_sort.h"
#include "libft.h"

t_ls_data	*create_ls_data(char *name)
{
	t_ls_data	*ls_data;

	if (!(ls_data = ft_memalloc(sizeof(struct s_ls_data))))
		return (NULL);
	ls_data->file_name = ft_strdup(name);
	ls_data->link_name = NULL;
	ls_data->user = NULL;
	ls_data->grop = NULL;
	ls_data->bloc = 0;
	ls_data->link = 0;
	ls_data->size = 0;
	ls_data->date = 0;
	ls_data->nano = 0;
	ls_data->left = NULL;
	ls_data->right = NULL;
	return (ls_data);
}

void		free_ls_data(t_ls_data *ls_data)
{
	if (!ls_data)
		return ;
	if (ls_data->left)
		free_ls_data(ls_data->left);
	if (ls_data->right)
		free_ls_data(ls_data->right);
	if (ls_data->file_name)
		ft_strdel(&ls_data->file_name);
	if (ls_data->link_name)
		ft_strdel(&ls_data->link_name);
	if (ls_data->mode)
		ft_strdel(&ls_data->mode);
	if (ls_data->user)
		ft_strdel(&ls_data->user);
	if (ls_data->grop)
		ft_strdel(&ls_data->grop);
	ft_memdel((void**)&ls_data);
}

t_ls_path	*process_ls_data(t_ls_path *ls_path, t_ls_flag *ls_flag, char *name)
{
	t_ls_data	*new_data;

	if (!ls_path)
		ls_path = create_ls_path("\n");
	if ((!ft_strcmp(name, ".") || !ft_strcmp(name, "..")) &&
				!(ls_flag->flag & FLAG_A))
		return (ls_path);
	new_data = create_ls_data(name);
	if (!(new_data = set_data_stat(ls_path, new_data)))
		free_ls_data(new_data);
	if (ls_path && new_data && ((ft_strcmp(new_data->file_name, ".") &&
			ft_strcmp(new_data->file_name, "..")) || ls_flag->flag & FLAG_A))
		ls_path->bloc += new_data->bloc;
	if (ls_flag->flag & FLAG_T)
		ls_path->data = sort_ls_data_time(ls_path->data, new_data);
	else
		ls_path->data = sort_ls_data_alpha(ls_path->data, new_data);
	return (ls_path);
}
