/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:25:49 by jlepere           #+#    #+#             */
/*   Updated: 2016/06/01 14:32:10 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_sort.h"
#include "libft.h"

char		**sort_ls_argv_alpha(char **argv)
{
	int		i;
	char	*argv_tmp;
	char	**argv_begin;

	i = 0;
	argv_tmp = NULL;
	argv_begin = argv;
	while (argv[i + 1])
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			argv_tmp = argv[i + 1];
			argv[i + 1] = argv[i];
			argv[i] = argv_tmp;
			i = 0;
		}
		else
			i++;
	}
	argv_tmp = NULL;
	return (argv_begin);
}

char		**sort_ls_argv_reverse(char **argv)
{
	int		i;
	int		size;
	char	*argv_tmp;

	i = 0;
	size = 0;
	while (argv[size])
		size++;
	if (size < 2)
		return (argv);
	size--;
	while (i < size)
	{
		argv_tmp = argv[size];
		argv[size] = argv[i];
		argv[i] = argv_tmp;
		size--;
		i++;
	}
	return (argv);
}

t_ls_data	*sort_ls_data_alpha(t_ls_data *ls_data, t_ls_data *ls_add)
{
	t_ls_data	*ls_begin;

	if (!ls_data)
		return (ls_add);
	ls_begin = ls_data;
	if (ft_strcmp(ls_data->file_name, ls_add->file_name) > 0)
	{
		if (ls_data->left)
			sort_ls_data_alpha(ls_data->left, ls_add);
		else
			ls_data->left = ls_add;
	}
	else
	{
		if (ls_data->right)
			sort_ls_data_alpha(ls_data->right, ls_add);
		else
			ls_data->right = ls_add;
	}
	return (ls_begin);
}

t_ls_data	*sort_ls_data_time(t_ls_data *ls_data, t_ls_data *ls_add)
{
	t_ls_data	*ls_begin;

	if (!ls_data)
		return (ls_add);
	ls_begin = ls_data;
	if ((ls_data->date < ls_add->date) || (ls_data->date == ls_add->date &&
				ls_data->nano < ls_add->nano) || (ls_data->date == ls_add->date
				&& ls_data->nano == ls_add->nano &&
				ft_strcmp(ls_data->file_name, ls_add->file_name) > 0))
	{
		if (ls_data->left)
			sort_ls_data_time(ls_data->left, ls_add);
		else
			ls_data->left = ls_add;
	}
	else
	{
		if (ls_data->right)
			sort_ls_data_time(ls_data->right, ls_add);
		else
			ls_data->right = ls_add;
	}
	return (ls_begin);
}
