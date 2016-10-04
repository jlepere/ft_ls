/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 11:47:06 by jlepere           #+#    #+#             */
/*   Updated: 2016/05/30 09:48:35 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_DATA_H
# define FT_LS_DATA_H

# include "ft_ls_path.h"
# include "ft_ls_flag.h"
# include <time.h>

typedef struct			s_ls_data
{
	char				*file_name;
	char				*link_name;
	char				*mode;
	char				*user;
	char				*grop;
	int					bloc;
	int					link;
	int					size;
	time_t				date;
	int					nano;
	struct s_ls_data	*left;
	struct s_ls_data	*right;
}						t_ls_data;

t_ls_data				*create_ls_data(char *name);
void					free_ls_data(t_ls_data *ls_data);
t_ls_path				*process_ls_data(t_ls_path *ls_path,
		t_ls_flag *ls_flag, char *name);

#endif
