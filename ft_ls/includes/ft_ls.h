/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:07:56 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/05 13:06:12 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <stddef.h>

/*
** ft_ls
*/

typedef enum		e_bool
{
	FALSE = 0,
	TRUE = 1
}					t_bool;

int					ft_ls(int argc, char **argv);

/*
** Params
*/

# define FT_PARAM_NBMAX (size_t)5
# define FT_PARAM "Rlart"
# define FT_PARAM_PRGNAME "ft_ls"

typedef struct		s_param
{
	char			key;
	t_bool			val;
}					t_param;

int					ft_param_arrsize(t_param *param);
void				ft_param_delarr(t_param **param);
void				ft_param_display(t_param *param, int state);
void				ft_param_displayusage(char param);
t_bool				ft_param_get(t_param **params, char key);
t_param				*ft_param_initarr(size_t max_size);
int					ft_param_parse(int argc, char **argv, t_param **param);
void				ft_param_set(t_param *param, char key, t_bool val);

#endif
