/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:07:46 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/04 12:19:41 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

//# include <stddef.h>

/*
** ft_ls
*/

typedef struct s_param	t_param;
typedef struct s_error	t_error;

int						ft_ls(int argc, char **argv);

/*
** Gestion des paramettres
*/

struct					s_param
{
	char				key;
	_Bool				val;
};

int						ft_param_parse(int argc, char **argv);
_Bool					ft_param_get(char param);

/*
** Gestion des display
*/

void					ft_display_param(void);

/*
** Gestion des erreurs
*/

struct					s_error
{
	int					err_code;
	char				*err_message;
};

# define ERR_CODE_1 -1
# define ERR_CODE_2 -2

# define ERR_MESSAGE_1 "Erreur d'allocation lors de l'execuion du programme"
# define ERR_MESSAGE_2 "Erreur de définition de paramettre"

int				ft_error(int err_code);

#endif
