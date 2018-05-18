/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_getgidlen.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 18:16:11 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/18 12:22:57 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <grp.h>
#include <libft.h>

/*
** Compte le nombre de caractere dans le gid ayant pour valeur gid
*/

extern int
	ft_utils_getgidlen(int gid)
{
	struct group		*grp;
	int					len;

	grp = getgrgid(gid);
	len = ft_strlen(grp->gr_name);
	return (len);
}
