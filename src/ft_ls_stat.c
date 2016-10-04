/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_stat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:46:02 by jlepere           #+#    #+#             */
/*   Updated: 2016/06/01 15:08:56 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls_stat.h"
#include "ft_ls_util.h"
#include "libft.h"
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

static t_ls_data	*set_stat_type(t_ls_data *ls_data, struct stat *ls_stat,
		char *path)
{
	char	*name;

	ls_data->mode = ft_strnew(10);
	if (S_ISREG(ls_stat->st_mode))
		ls_data->mode[0] = '-';
	else if (S_ISDIR(ls_stat->st_mode))
		ls_data->mode[0] = 'd';
	else if (S_ISBLK(ls_stat->st_mode))
		ls_data->mode[0] = 'b';
	else if (S_ISCHR(ls_stat->st_mode))
		ls_data->mode[0] = 'c';
	else if (S_ISSOCK(ls_stat->st_mode))
		ls_data->mode[0] = 's';
	else if (S_ISLNK(ls_stat->st_mode))
	{
		ls_data->mode[0] = 'l';
		name = ft_strnew(4096);
		readlink(path, name, 4096);
		ls_data->link_name = ft_strdup(name);
		ft_strdel(&name);
	}
	else
		ls_data->mode[0] = '-';
	return (ls_data);
}

static t_ls_data	*set_stat_mode(t_ls_data *ls_data, struct stat *ls_stat)
{
	ls_data->mode[1] = (ls_stat->st_mode & S_IRUSR) ? 'r' : '-';
	ls_data->mode[2] = (ls_stat->st_mode & S_IWUSR) ? 'w' : '-';
	ls_data->mode[3] = (ls_stat->st_mode & S_IXUSR) ? 'x' : '-';
	ls_data->mode[4] = (ls_stat->st_mode & S_IRGRP) ? 'r' : '-';
	ls_data->mode[5] = (ls_stat->st_mode & S_IWGRP) ? 'w' : '-';
	ls_data->mode[6] = (ls_stat->st_mode & S_IXGRP) ? 'x' : '-';
	ls_data->mode[7] = (ls_stat->st_mode & S_IROTH) ? 'r' : '-';
	ls_data->mode[8] = (ls_stat->st_mode & S_IWOTH) ? 'w' : '-';
	ls_data->mode[9] = (ls_stat->st_mode & S_IXOTH) ? 'x' : '-';
	if (ls_stat->st_mode & S_ISVTX)
		ls_data->mode[9] = (ls_data->mode[9] == '-') ? 'T' : 't';
	if (ls_stat->st_mode & S_ISGID)
		ls_data->mode[6] = (ls_data->mode[6] == '-') ? 'S' : 's';
	if (ls_stat->st_mode & S_ISUID)
		ls_data->mode[3] = (ls_data->mode[3] == '-') ? 'S' : 's';
	return (ls_data);
}

static t_ls_data	*set_stat_othr(t_ls_data *ls_data, t_ls_path *ls_path,
		struct stat *ls_stat)
{
	struct passwd	*ls_pwd;
	struct group	*ls_grp;

	if ((ls_pwd = getpwuid(ls_stat->st_uid)))
		ls_data->user = ft_strdup(ls_pwd->pw_name);
	else
		ls_data->user = ft_itoa(ls_stat->st_uid);
	if (ls_path && (int)ft_strlen(ls_data->user) > ls_path->user)
		ls_path->user = ft_strlen(ls_data->user);
	if ((ls_grp = getgrgid(ls_stat->st_gid)))
		ls_data->grop = ft_strdup(ls_grp->gr_name);
	else
		ls_data->grop = ft_itoa(ls_stat->st_gid);
	if (ls_path && (int)ft_strlen(ls_data->grop) > ls_path->grop)
		ls_path->grop = ft_strlen(ls_data->grop);
	ls_data->bloc = ls_stat->st_blocks;
	ls_data->link = ls_stat->st_nlink;
	if (ls_path && ft_intlen(ls_data->link) > ls_path->link)
		ls_path->link = ft_intlen(ls_data->link);
	ls_data->size = ls_stat->st_size;
	if (ls_path && ft_intlen(ls_data->size) > ls_path->size)
		ls_path->size = ft_intlen(ls_data->size);
	return (ls_data);
}

t_ls_data			*set_data_stat(t_ls_path *ls_path, t_ls_data *ls_data)
{
	char		*path;
	char		*file;
	struct stat	ls_stat;

	if (ls_path->name[0] == '\n')
		path = ft_strdup("");
	else if (ls_path->name[ft_strlen(ls_path->name) - 1] == '/')
		path = ft_strdup(ls_path->name);
	else
		path = ft_strjoin(ls_path->name, "/");
	file = ft_strjoin(path, ls_data->file_name);
	if (lstat(file, &ls_stat))
		return (ls_perror(path));
	ls_data = set_stat_type(ls_data, &ls_stat, file);
	ls_data = set_stat_mode(ls_data, &ls_stat);
	ls_data = set_stat_othr(ls_data, ls_path, &ls_stat);
	ls_data->date = ls_stat.st_mtime;
	ls_data->nano = ls_stat.st_mtimespec.tv_nsec;
	ft_strdel(&path);
	ft_strdel(&file);
	return (ls_data);
}
