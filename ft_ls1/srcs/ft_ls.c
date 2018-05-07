/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 17:39:35 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/07 14:33:20 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include "libft.h"
#include "ft_ls.h"

static int			ft_ls_init(char **argv, int argc, t_list **buff)
{
	int				i;
	t_file			file;

	i = 0;
	while (i < argc)
	{
		file.name = argv[i];
		if (lstat(argv[i], &file.stat) == -1)
			return (-1); // Erreur d'acces fichier, vérifier si erreur fatale ou non.
		ft_buff_insert(buff, &file, argc);
	}
	//ft_sort_file((t_buff *)buff->content);
	return (1); // Valeur de retour temporaire.
}

/*
** Surcouche de la fonction main().
** Fonction de lancement du programme ft_ls.
*/

extern int			ft_ls(int argc, char **argv)
{
	int 			ret;
	int				cur;
	t_list			*buff;

	cur = ft_param_parse(argc, argv);
	ret = cur;
	if (ret > 0)
	{	
		if (cur < argc)
			ft_ls_init(&argv[cur], argc - cur, &buff);
	}
	if (ret < 0)
		ret = ft_error(ret);
	return (ret);
}
