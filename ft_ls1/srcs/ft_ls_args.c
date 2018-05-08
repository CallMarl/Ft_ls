/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:02:45 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/08 14:47:17 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <errno.h>
	#include <string.h>
#include "libft.h"
#include "ft_ls.h"

/*
** Récupère dans le buffeur tout les appel à lstat ayant générer une erreur
** les range par ordre ascii. Et affiche les erreurs
*/

static int			ft_ls_argserr(t_list *buff, int count)
{
	char			**file_name;
	size_t			i;
	int				j;
	t_buff			tmp;

	if (!(file_name = (char **)ft_memalloc(sizeof(char *) * (count + 1))))
		return (ERR_CODE_1);
	file_name[count] == 0;
	i = 0;
	j = 0;
	tmp = (t_buff *)buff->content;
	while (i < tmp->cr)
	{
		if (tmp->buff[i].err != 0)
		{
			file_name[j] = tmp->buff[i].name;
			j++;
		}
		i++;
	}
	ft_sort_ascii(file_name, count);
	//Appel la fonction de display d'erreur
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

static int			ft_ls_argslaunch(t_list *buff, int count[3], _Bool opt_R)
{
	int				i;
	int				ret;

	i = 0;
	while (i < 3)
	{
		if (i == 0)
			ret = ft_ls_argserr(buff, count[i]);
		else if (i == 1)
			ret = ft_ls_argsfile(buff, count[i]);
		else
			ret = ft_ls_argsdir(buff, count[i], opt_R);
		i++;
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
	int				count[3];
	t_file			file;

	i = 0;
	while (i < 2)
		count[i++] = 0;
	i = 0;
	while (i < size)
	{
		file.name = argv[i];
		file.err = 0;
		if (lstat(argv[i], &file.stat) == -1)
			file.err = errno;;
		if (ft_buff_insert(buff, &file, size) == -1)
			return (ERR_CODE_1);
		if (file.err != 0)
			(count[0])++;
		else
			((file.stat.st_mode & S_IFDIR) != 0) ? (count[2])++ : (count[1])++;
		i++;
	}
	ft_ls_argslaunch(*buff, count, ft_param_get('R'));
	return (1); // Valeur de retour temporaire
}

