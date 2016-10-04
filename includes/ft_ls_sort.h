/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:26:15 by jlepere           #+#    #+#             */
/*   Updated: 2016/06/01 14:09:46 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_SORT_H
# define FT_LS_SORT_H

# include "ft_ls_data.h"

char		**sort_ls_argv_alpha(char **argv);
char		**sort_ls_argv_reverse(char **argv);
t_ls_data	*sort_ls_data_alpha(t_ls_data *ls_data, t_ls_data *ls_add);
t_ls_data	*sort_ls_data_time(t_ls_data *ls_data, t_ls_data *ls_add);

#endif
