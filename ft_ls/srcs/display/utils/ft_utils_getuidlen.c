/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_getuidlen.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:17:32 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/17 18:18:27 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pwd.h>
#include "libft.h"

/*
** Compte le nombre de caractere dans l'uid ayant pour valeur uid
*/

extern int			ft_utils_getuidlen(int uid)
{
	struct passwd		*pwd;
	int					len;

	pwd = getpwuid(uid);
	len = ft_strlen(pwd->pw_name);
	return (len);
}
