/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_flag.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlepere <jlepere@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 14:43:21 by jlepere           #+#    #+#             */
/*   Updated: 2016/05/31 11:11:47 by jlepere          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_FLAG_H
# define FT_LS_FLAG_H

# define FLAG_BR 0x01
# define FLAG_A 0x02
# define FLAG_L 0x04
# define FLAG_R 0x08
# define FLAG_T 0x10

typedef struct	s_ls_flag
{
	char		**argv;
	int			argc;
	char		flag;
	int			end;
	int			nb_dirs;
}				t_ls_flag;

t_ls_flag		*create_ls_flag(void);
t_ls_flag		*parse_ls_argv(t_ls_flag *ls_flag, char **argv);

#endif
