/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:07:46 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/09 19:05:28 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <limits.h>
# include <stddef.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include "libft.h"

/*
** ft_ls
*/

typedef struct s_param	t_param;
typedef struct s_error	t_error;
typedef struct s_file	t_file;

struct					s_file
{
	char				name[PATH_MAX];
	int					err;
	struct stat			stat;
};

int						ft_ls(int argc, char **argv);
int						ft_ls_args(char **argv, int size, t_list **buff);
int						ft_ls_noargs(char *path, t_list **buff, _Bool opt_R);

/*
** Gestion du buffer
*/


t_file					*ft_buff_get(t_buff *buff, int i);
int						ft_buff_insert(t_list **list, t_file *elem, size_t b_size);
void					ft_buff_rm(void *elem, size_t size);

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
** Gestion des display en mode debug
*/

void					ft_debug_buff(t_buff *buff);
void					ft_debug_param(void);
void					ft_debug_strarr(char **strarr);

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
# define ERR_CODE_4 -4
# define ERR_CODE_5 -5

# define ERR_MESS_1 "Erreur d'allocation lors de l'execuion du programme"
# define ERR_MESS_2 "Erreur de définition de paramettre"
# define ERR_MESS_3 "Erreur vous ne possédez pas les droits d'accès"
# define ERR_MESS_4 "Erreur le nom du chemin est trop long"
# define ERR_MESS_5 "Erreur n'est pas un fichier ou un dossier" 

int				ft_error(int err_code);

#endif
