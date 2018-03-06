/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 12:02:26 by pprikazs          #+#    #+#             */
/*   Updated: 2018/03/06 19:04:27 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h> //Need by dirent struct
#include <sys/stat.h> //Add stat struct
#include <sys/time.h> //Add the time type
#include <sys/xattr.h>
#include <dirent.h> //Add dirent struct
#include <stdio.h>
#include "libft.h"

typedef struct dirent t_dirent;
typedef struct stat t_stat;

#define RC ft_putchar('\n')

int		parcour_dir_error_path_stat(void)
{
	DIR				*dir_descriptor;
	t_dirent		*dir_detail; // file and dir, symlink...
	t_stat			dir_extradetail; // file and dir, symlink...

	if ((dir_descriptor = opendir("/dev")) == 0)
		return (0);
	while ((dir_detail = readdir(dir_descriptor)) != 0)
	{
		ft_putstr("Nom : ");
		ft_putendl(dir_detail->d_name);
		ft_putstr("Numero du noeud : ");
		ft_putnbr(dir_detail->d_ino);RC;
		ft_putstr("Longueur de l'enregistrement : ");
		ft_putnbr(dir_detail->d_reclen);RC;
		/**
				#define	DT_UNKNOWN	 0
				#define	DT_FIFO		 1		'p'
				#define	DT_CHR		 2		'c'
				#define	DT_DIR		 4		'd'
				#define	DT_BLK		 6		'b'
				#define	DT_REG		 8		'r'
				#define	DT_LNK		10		'l'
				#define	DT_SOCK		12		's'
				#define	DT_WHT		14
		*/
		ft_putstr("Type : ");
		ft_putnbr(dir_detail->d_type);RC;
		RC;

		int tmp;
		tmp = stat(dir_detail->d_name, &dir_extradetail);
		ft_putnbr(tmp);RC;
		ft_putstr("Numero du noeud : ");
		ft_putnbr(dir_extradetail.st_ino);RC;
		ft_putstr("Inode device : ");RC;
		ft_putnbr(dir_extradetail.st_dev);RC;
		ft_putnbr(major(dir_extradetail.st_dev));RC;
		ft_putnbr(minor(dir_extradetail.st_dev));RC;
		ft_putstr("Mode de prtotection du noeud : ");
		ft_putnbr(dir_extradetail.st_mode);RC; // Donné en binaire 0 == - et 1 == lettre: ---rwxrwxrwx
		ft_putstr("Nombre de hard_link pour le noeud : ");
		ft_putnbr(dir_extradetail.st_nlink);RC;
		ft_putstr("Id utilisateur : ");
		ft_putnbr(dir_extradetail.st_uid);RC;
		ft_putstr("Id groupe : ");
		ft_putnbr(dir_extradetail.st_gid);RC;
		ft_putstr("Id device : ");RC;
		ft_putnbr(dir_extradetail.st_rdev);RC;
		ft_putnbr(major(dir_extradetail.st_dev));RC;
		ft_putnbr(minor(dir_extradetail.st_dev));RC;
		ft_putstr("Date de derniere acces : ");
		ft_putnbr(dir_extradetail.st_atimespec.tv_sec);RC;
		ft_putstr("Date de derniere modification : ");
		ft_putnbr(dir_extradetail.st_mtimespec.tv_sec);RC;
		ft_putstr("Date de dernier changement de status : ");
		ft_putnbr(dir_extradetail.st_ctimespec.tv_sec);RC;
		ft_putstr("Taille du fichier en bit : ");
		ft_putnbr(dir_extradetail.st_size);RC;
		ft_putstr("Nb de block alloué pour le fichier : ");
		ft_putnbr(dir_extradetail.st_blocks);RC;
		ft_putstr("Meilleurs taille de block pour IO : ");
		ft_putnbr(dir_extradetail.st_blksize);RC;
		ft_putstr("Flags définit par l'utilisateur: ");
		ft_putnbr(dir_extradetail.st_flags);RC;
		ft_putstr("numero de generation du fichier : ");
		ft_putnbr(dir_extradetail.st_gen);RC;
		RC;
		RC;
	}
	return (1);
}

/** Man xattr
	size_t	bufflen;
	char	*buff;
	char	*path;

	path = "/dev";
	bufflen = listxattr(path, NULL, 0, XATTR_SHOWCOMPRESSION);
	ft_putnbr((int)bufflen);
	if (!(buff = ft_memalloc(sizeof(char) * bufflen)))
		return (0);
	bufflen =listxattr(".", buff, bufflen, 1);
	ft_putstr(buff);
*/

/*
		int tmp;
		tmp = stat("/dev/zero", &dir_extradetail);
		ft_putnbr(tmp);RC;
		ft_putstr("Id device : ");RC;
		ft_putnbr(dir_extradetail.st_rdev);RC;
		ft_putnbr(major(dir_extradetail.st_rdev));RC;
		ft_putnbr(minor(dir_extradetail.st_rdev));RC;
*/

int			main(int argc, char *argv[])
{
	DIR				*dir_descriptor;
	t_dirent		*dir_detail; // file and dir, symlink...

	if ((dir_descriptor = opendir("..")) == 0)
		return (0);
	while ((dir_detail = readdir(dir_descriptor)) != 0)
	{
		ft_putstr("Nom : ");
		ft_putendl(dir_detail->d_name);
		ft_putstr("Numero du noeud : ");
		ft_putnbr(dir_detail->d_ino);RC;
		ft_putstr("Longueur de l'enregistrement : ");
		ft_putnbr(dir_detail->d_reclen);RC;
		ft_putstr("Type : ");
		ft_putnbr(dir_detail->d_type);RC;
		RC;

		RC;
		RC;
	}

	(void)argc;
	(void)argv;
	return (0);
}
