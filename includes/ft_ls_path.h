/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_path.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 12:01:21 by jlepere           #+#    #+#             */
/*   Updated: 2016/05/28 12:33:27 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_PATH_H
# define FT_LS_PATH_H

# include "ft_ls_flag.h"
# include "libft.h"

typedef struct			s_ls_path
{
	char				*name;
	int					bloc;
	int					user;
	int					grop;
	int					link;
	int					size;
	struct s_ls_data	*data;
}						t_ls_path;

t_ls_path				*create_ls_path(char *name);
void					free_ls_path(t_ls_path *ls_path);
void					process_ls_recursive(t_cbuff *ls_buff,
		t_ls_flag *ls_flag);
void					*process_ls_path(char *path, t_ls_flag *ls_flag);

#endif
