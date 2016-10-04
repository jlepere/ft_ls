/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_stat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:51:20 by jlepere           #+#    #+#             */
/*   Updated: 2016/05/30 11:55:27 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_STAT_H
# define FT_LS_STAT_H

# include "ft_ls_path.h"
# include "ft_ls_data.h"

t_ls_data	*set_data_stat(t_ls_path *ls_path, t_ls_data *ls_data);

#endif
