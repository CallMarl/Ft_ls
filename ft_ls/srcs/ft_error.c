/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:39:31 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/07 14:30:25 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static t_error			*ft_init_error1(void)
{
	static t_error		error_list[] = {
		{ ERR_CODE_1, ERR_MESS_1 },
		{ ERR_CODE_2, ERR_MESS_2 },
		{ ERR_CODE_3, ERR_MESS_3 },
		{ ERR_CODE_4, ERR_MESS_4 },
		{ ERR_CODE_4, ERR_MESS_5 },
		{ 0, 0 }
	};

	return (error_list);
}

/*
** Fonction de gestion des erreurs.
*/

extern int			ft_error(int err_code)
{
	t_error			*error_list;
	
	error_list = ft_init_error1();
	(void)error_list;
	(void)err_code;	
	return (0);
}
