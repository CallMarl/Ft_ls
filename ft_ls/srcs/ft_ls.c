/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:04:54 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/05 18:31:51 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#include "libft.h"
#include "ft_ls.h"

extern int			ft_ls(int argc, char **argv)
{
	t_param			*param;
	int				cur;

	param = 0;
	if ((cur = ft_param_parse(argc, argv, &param)) == -1)
		return (-1);
	{
		DIR				*test;
		struct dirent	*dir;
		struct stat		buff;
	
		if (!(test = opendir(".")))
		{
			ft_putendl("couldn't open .");
			return (0);
		}
		while ((dir = readdir(test)) != 0)
		{
			ft_putendl(dir->d_name);
			stat(dir->d_name, &buff);
			ft_putnbr(buff.st_blocks);
		}
	}
//	ft_param_display(param, 0);
	return (0);
}
