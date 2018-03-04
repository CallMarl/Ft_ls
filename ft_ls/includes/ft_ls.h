/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:07:56 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/04 17:11:03 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define FT_LS_PARAMS_NB 5
# define FT_LS_PARAMS_EXP "-"
# define FT_LS_PARAMS "Rlart"

typedef enum		e_bool
{
	FALSE;
	TRUE;
}					t_bool;

typedef struct		s_params
{
	char			key;
	t_bool			val;
}					t_params;

#endif
