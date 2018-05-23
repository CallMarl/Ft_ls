/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:39:31 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/23 09:13:29 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"
#include "ft_ls.h"

extern int
	ft_err_basic(void)
{
	char			*ls;

	ls = "ls ";
	perror(ls);
	return (0);
}

extern int
	ft_err_args(t_file *file, int count)
{
	int				i;

	i = 0;
	while (i < count)
	{
		if (ft_printf("ls : %s : %s\n", \
					file[i].name, strerror(file[i].err)) == -1)
			return (ERR_CODE_1);
		i++;
	}
	return (0);
}

static t_error
	*ft_init_error1(void)
{
	static t_error		error_list[] = {
		{ ERR_CODE_1, ERR_MESS_1 },
		{ ERR_CODE_2, ERR_MESS_2 },
		{ 0, 0 }
	};

	return (error_list);
}

/*
** Fonction de gestion des erreurs.
*/

extern int
	ft_error(int err_code)
{
	t_error			*error_list;
	int				i;

	error_list = ft_init_error1();
	if (err_code == ERR_CODE_2)
		ft_display_usage();
	else
	{
		i = 0;
		while (error_list[i].err_code != 0)
		{
			if (err_code == error_list[i].err_code)
			{
				ft_putendl(error_list[i].err_message);
				break ;
			}
			i++;
		}
	}
	return (0);
}
