/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:07:46 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/23 11:34:40 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <limits.h>
# include <stddef.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include "libft.h"

/*
** ft_ls
*/

typedef struct dirent	t_dirent;
typedef struct s_disp	t_disp;
typedef struct s_param	t_param;
typedef struct s_error	t_error;
typedef struct s_file	t_file;

struct					s_file
{
	char				name[255];
	char				*path;
	int					err;
	struct stat			stat;
};

int						ft_ls(int argc, char **argv);
int						ft_ls_args(char **argv, int size, t_list **buff);
int						ft_ls_noargs(char *path, t_list **buff, \
		int opt_r, int opt_a);

/*
** Gestion du buffer
*/

# define LS_BUFFSIZE 1024

void					ft_buff_delelem(void *elem);
t_buff					*ft_buff_get(t_list *buff);
t_file					*ft_buff_getfile(t_buff *buff, int i);
int						ft_buff_insert(t_list **list, t_file *elem, \
		size_t b_size);
int						ft_buff_new(t_list **list, size_t b_size);
void					ft_buff_rm(void *elem, size_t size);

/*
** Gestion des paramettres
*/

struct					s_param
{
	char				key;
	int					val;
};

int						ft_param_parse(int argc, char **argv);
int						ft_param_get(char param);

/*
** Gestion du trie
*/

void					ft_sort_file(t_file *files, size_t size);
int						ft_sort_filecmp_c(const void *f1, const void *f2);
int						ft_sort_filecmp_d(const void *f1, const void *f2);
int						ft_sort_sizecmp_c(const void *f1, const void *f2);
int						ft_sort_timecmp_c(const void *f1, const void *f2);

/*
** Gestion des display
*/

struct					s_disp
{
	int					mode;
	int					nlink;
	int					uid;
	int					gid;
	int					size;
	int					major;
	int					minor;
};

int						ft_display_column(t_buff *buff, int opt_a);
void					ft_display_file(t_file *file, int opt_l);
int						ft_display_long(t_buff *buff, int opt_a);
int						ft_display_ls(t_buff *buff);
void					ft_display_path1(char *path);
void					ft_display_path2(char *path);
void					ft_display_prepare(t_buff *buff, t_disp *disp, \
		int opt_a, size_t *block);
char					*ft_display_preparestr(t_disp *disp);
int						ft_display_short(t_buff *buff, int opt_a);
void					ft_display_usage(void);
int						ft_utils_getgidlen(int gid);
int						ft_utils_getuidlen(int uid);
char					*ft_utils_insertnbr(char *str, int nbr);
void					ft_utils_mode(mode_t st_mode, char mode[12]);
int						ft_utils_modetype(mode_t st_mode);
int						ft_utils_nbweight(int nb);
size_t					ft_utils_pflag_d(char **str, int dispval, \
		size_t count);
size_t					ft_utils_pflag_offs(char **str, int dispval, \
		size_t count);
size_t					ft_utils_pflag_s(char **str, int dispval, \
		size_t count);
void					ft_utils_putblanck(size_t size);
char					*ft_utils_time(struct stat *stat, char *str);

/*
** Gestion des display en mode debug
*/

void					ft_debug_buff(t_buff *buff);
void					ft_debug_disp(t_disp *disp);
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

# define ERR_MESS_1 "Erreur d'allocation lors de l'execuion du programme"
# define ERR_MESS_2 "Erreur de définition de paramettre"

int						ft_error(int err_code);
int						ft_err_args(t_file *file, int count);
int						ft_err_basic(void);

#endif
