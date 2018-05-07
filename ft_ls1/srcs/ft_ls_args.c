/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:02:45 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/07 19:02:20 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "libft.h"
#include "ft_ls.h"

/*
** Récupère dans le buffeur tout les appel à lstat ayant générer une erreur
** les range par ordre ascii. Et affiche les erreurs
*/

static int			ft_ls_argserr(t_list *buff)
{
	//Appel la fonction de display d'erreur
	(void)buff;
	return (1);
}

/*
** Récupère dans le buffer tout les appel à lstat correspondant à un fichier
** les range par ordre ascii et les affiche.
*/

static int			ft_ls_argsfile(t_list *buff)
{
	//Appel la fonction de display final
	(void)buff;
	return (1);
}

/*
** Récupère dans le buffer tout les appel à lstat correspondant à un dossier
** et fait un appel à ft_ls_noarg pour chacun d'entre eux.
*/

static int			ft_ls_argsdir(t_list *buff, _Bool opt_R)
{
	//Appel la fonction ft_ls_noarg()
	(void)buff;
	(void)opt_R;
	return (1);
}

/*
** Fonction de lancement de ls avec des argument elle display soit les fichier
** soit elle appel ft_ls_noargs() dans le cas d'un dossier
*/

static int			ft_ls_arglaunch(t_list *buff, _Bool opt_R)
{
	int				i;
	int				ret;

	i = 0;
	while (i < 3)
	{
		if (i == 0)
			ret = ft_ls_argserr(buff);
		else if (i == 1)
			ret = ft_ls_argsfile(buff);
		else
			ret = ft_ls_argsdir(buff, opt_R);
	}
	return (ret);
}

/*
** Initialisation d'un buffer dans le cas ou des chemin son spécifier en 
** argument de la commande ft_ls.
*/

extern int			ft_ls_args(char **argv, int size, t_list **buff)
{
	int				i;
	t_file			file;

	i = 0;
	while (i < size)
	{
		file.name = argv[i];
		if (lstat(argv[i], &file.stat) == -1) // Penser à l'ajouter dans le buffer pour le trie.
			return (-1); // Erreur d'acces fichier, vérifier si erreur fatale ou non.
		if (ft_buff_insert(buff, &file, size) == -1)
			return (ERR_CODE_1);
		i++;
	}
	ft_debug_buff((t_buff *)(*buff)->content);
	ft_ls_arglaunch(*buff, ft_param_get('R'));
	return (1); // Valeur de retour temporaire
}

