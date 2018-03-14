/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:07:56 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/14 12:00:46 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <stddef.h>
# include <time.h>
# include <dirent.h>

typedef enum e_bool		t_bool;
typedef struct dirent	t_dirent;
typedef struct stat		t_stat;
typedef struct timespec	t_time;
typedef struct s_nbuff	t_nbuff;
typedef struct s_ninfo	t_ninfo;
typedef struct s_param	t_param;
typedef struct s_path	t_path;

/*
** ft_ls
*/

enum					e_bool
{
	FALSE = 0,
	TRUE = 1
};

int						ft_ls(int argc, char **argv);
int						ft_ls_launch(char *bpath, char opt, t_param *param);

/*
** Buffer
*/

struct					s_nbuff
{
	char				*path;
	size_t				size;
	size_t				cur;
	t_ninfo				*ninfo;
};

int						ft_buffer_initarr(DIR *nd, char *bpath, t_nbuff *nbuffer);
void					ft_buffer_setinfo(t_nbuff *nbuffer, t_ninfo *ninfo);

/*
** Display
*/

void					ft_display_ninfo(t_ninfo ninfo);
void					ft_display_nbuffer(t_nbuff nbuffer);

/*
** Nodes
*/

struct					s_ninfo
{
	unsigned char		n_type;
	mode_t				n_mode;
	nlink_t				n_nblink;
	uid_t				n_uid;
	gid_t				n_gid;
	off_t				n_size;
	t_time				n_mtime;
	char				*n_name;
};

int						ft_node_getinfo(DIR *nd, char *bpath, t_ninfo *ninfo);
void					ft_node_setinfo(t_dirent *ndetail, t_stat *nextra, t_ninfo *ninfo);

/*
** Params
*/

# define FT_PARAM_PRGNAME "ft_ls"
# define FT_PARAM "Rlart"
# define FT_PARAM_NBMAX (size_t)5

struct					s_param
{
	char				key;
	t_bool				val;
};

int						ft_param_arrsize(t_param *param);
void					ft_param_delarr(t_param **param);
void					ft_param_display(t_param *param, int state);
void					ft_param_displayusage(char param);
t_bool					ft_param_get(t_param *params, char key);
t_param					*ft_param_initarr(size_t max_size);
int						ft_param_parse(int argc, char **argv, t_param **param);
void					ft_param_set(t_param *param, char key, t_bool val);

/*
** Path
*/

typedef struct			s_path
{
	char				**path;
	int					size;
	int					cur;
}						t_path;

void					ft_path_init(int argc, char **argv, int cur, t_path *path);

#endif
