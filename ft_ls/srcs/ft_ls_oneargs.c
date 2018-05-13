/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_oneargs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 16:40:27 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/13 16:49:58 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <sys/stat.h>
#include "libft.h"
#include "ft_ls.h"

extern int			ft_ls_oneargs(char *argv, t_list **buff)
{
	t_file			file;

	if (lstat(argv, &file.stat) == -1)
		return (-1); // Le fichier n'existe pas
	return (ft_ls_noargs(ft_strdup(argv), buff, ft_param_get('R')));
}
