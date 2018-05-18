/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 11:39:44 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/18 12:53:34 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Ce fichier utilise la variable globale g_param, voir srcs/ft_global.c
*/

extern t_param		g_param[];

/*
** Met le paramettre à 1 dans la table des paramettre.
** sinon le paramettre n'existe pas.
*/

static int
	ft_param_insert(char param, int val)
{
	int				i;

	i = 0;
	while (g_param[i].key != 0)
	{
		if (param == g_param[i].key)
		{
			g_param[i].val = val;
			return (1);
		}
		i++;
	}
	return (ERR_CODE_2);
}

static int
	ft_param_read(char *param, int call)
{
	int				i;
	int				ret;

	i = 0;
	ret = 1;
	while (param[i] != '\0')
	{
		if ((ret = ft_param_insert(param[i], call + i)) < 0)
			return (ret);
		i++;
	}
	return (ret);
}

/*
** Fonction de parsing des paramettres, elle vérifie les paramettre passé en
** argument de la commande et initialise le tableau g_param.
*/

extern int
	ft_param_parse(int argc, char **argv)
{
	int				i;
	int				ret;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != '-' || (argv[i][0] == '-' && argv[i][1] == '\0'))
			return (i);
		else if (argv[i][0] == '-' && argv[i][1] == '-')
			return (i + 1);
		if ((ret = ft_param_read(&argv[i][1], i * 10000000)) < 0)
			return (ret);
		i++;
	}
	return (i);
}
