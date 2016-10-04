/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_util.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:25:08 by jlepere           #+#    #+#             */
/*   Updated: 2016/06/01 14:52:20 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_UTIL_H
# define FT_LS_UTIL_H

void	*ls_perror(char *file);
void	ls_add_space(int ls_path, int ls_data);
char	*ls_add_backslash(char *str);

#endif
