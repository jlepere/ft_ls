/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_view.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:36:19 by jlepere           #+#    #+#             */
/*   Updated: 2016/06/01 13:33:34 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_VIEW_H
# define FT_LS_VIEW_H

# include "ft_ls_path.h"
# include "ft_ls_data.h"
# include "ft_ls_flag.h"

void	view_ls_data(t_ls_path *ls_path, t_ls_data *ls_data,
		t_ls_flag *ls_flag);
void	view_ls_path(t_ls_path *ls_path, t_ls_flag *ls_flag, char dirs);

#endif
