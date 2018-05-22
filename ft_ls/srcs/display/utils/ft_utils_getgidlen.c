/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_getgidlen.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:16:11 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/22 16:43:03 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <grp.h>
#include "libft.h"
#include "ft_ls.h"

/*
** Compte le nombre de caractere dans le gid ayant pour valeur gid
*/

extern int
	ft_utils_getgidlen(int gid)
{
	struct group		*grp;
	int					len;

	len = 0;
	if (!(grp = getgrgid(gid)))
		return (ft_utils_nbweight(gid));
	if (grp->gr_name)
		len = ft_strlen(grp->gr_name);
	return (len);
}
