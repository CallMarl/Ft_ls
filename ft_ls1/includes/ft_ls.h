/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:07:46 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/04 17:22:11 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <stddef.h>
# include <unistd.h>

/*
** ft_ls
*/

typedef struct s_param	t_param;
typedef struct s_error	t_error;
typedef struct s_file	t_file;

struct					s_file
{
	char				*name;
	DIR					*dd;
	FILE				*fd;
};

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
**
*/

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
# define ERR_CODE_3 -3
# define ERR_CODE_3 -4
# define ERR_CODE_3 -5

# define ERR_MESS_1 "Erreur d'allocation lors de l'execuion du programme"
# define ERR_MESS_2 "Erreur de définition de paramettre"
# define ERR_MESS_3 "Erreur vous ne possédez pas les droits d'accès"
# define ERR_MESS_4 "Erreur le nom du chemin est trop long"
# define ERR_MESS_5 "Erreur n'est pas un fichier ou un dossier" 

int				ft_error(int err_code);

#endif
