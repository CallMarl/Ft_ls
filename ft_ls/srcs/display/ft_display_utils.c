/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 10:06:09 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/14 11:19:38 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pwd.h>
#include <grp.h>
#include "libft.h"
#include "ft_ls.h"

/*
** Compte le nombre de caractere dans l'uid ayant pour valeur uid
*/

extern int				ft_getuidlen(int uid)
{
	struct passwd		*pwd;
	int					len;

	pwd = getpwuid(uid);
	len = ft_strlen(pwd->pw_name);
	return (len);
}

/*
** Compte le nombre de caractere dans le gid ayant pour valeur gid
*/

extern int				ft_getgidlen(int gid)
{
	struct group		*grp;
	int					len;

	grp = getgrgid(gid);
	len = ft_strlen(grp->gr_name);
	return (len);
}

/*
** Insert un nombre dans un chaine de caractere
*/

extern char				*ft_insertnbr(char *str, int nbr)
{
	int size;
	int tmp;

	if (nbr == -2147483648)
	{
		*str++= '-';
		*str++= '2';
		nbr = nbr % 2000000000;
		nbr = -nbr;
	}
	else if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	size = 1;
	tmp = nbr;
	while ((tmp = tmp / 10) != 0)
		size = size * 10;
	while (size)
	{
		*str++ = (char)((nbr / size) + 48);
		nbr %= size;
		size /= 10;
	}
	return (str);
}

/*
** Compte le nombre de chiffre dans un nombre
*/

extern int				ft_nbweight(int nb)
{
	int					i;

	i = 1;
	while ((nb /= 10) > 0)
		i++;
	return (i);
}
