/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 16:07:56 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/13 17:15:31 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <time.h>
# include <stddef.h>

/*
** ft_ls
*/

typedef enum				e_bool
{
	FALSE = 0,
	TRUE = 1
}							t_bool;

int							ft_ls(int argc, char **argv);

/*
** Buffer
*/

typedef struct dirent		t_dirent;
typedef struct stat			t_stat;
typedef struct timespec		t_time;

int							ft_buffer_initarr(int size, t_buffer *buffer);
void						ft_buffer_setinfo(t_nbuff *nbuffer, t_ninfo ninfo);

typedef	struct				s_nbuff
{
	char					*path;
	size_t					size;
	size_t					cur;
	t_ninfo					*ninfo;
}							t_nbuff;


/*
** Display
*/

void						ft_display_nbuffer(t_nbuffer nbuffer);

/*
** Nodes
*/

typedef struct				s_ninfo
{
	unsigned char			n_type;
	mode_t					n_mode;
	nlink_t					n_nblink;
	uid_t					n_uid;
	gid_t					n_gid;
	off_t					n_size
	t_time					n_mtime;
	char					*n_name;
}							t_ninfo;


/*
** Params
*/

# define FT_PARAM_NBMAX (size_t)5
# define FT_PARAM "Rlart"
# define FT_PARAM_PRGNAME "ft_ls"

typedef struct				s_param
{
	char					key;
	t_bool					val;
}							t_param;

int							ft_param_arrsize(t_param *param);
void						ft_param_delarr(t_param **param);
void						ft_param_display(t_param *param, int state);
void						ft_param_displayusage(char param);
t_bool						ft_param_get(t_param *params, char key);
t_param						*ft_param_initarr(size_t max_size);
int							ft_param_parse(int argc, char **argv, t_param **param);
void						ft_param_set(t_param *param, char key, t_bool val);

/*
** Path
*/

typedef struct				s_path
{
	char					**path;
	int						size;
	int						cur;
}							t_path;

void						ft_path_init(int argc, char **argv, int cur, t_path *path);

#endif
