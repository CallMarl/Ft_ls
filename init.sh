#!bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    init.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/01 19:01:20 by pprikazs          #+#    #+#              #
#    Updated: 2018/05/03 13:59:11 by pprikazs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

function new_dir()
{
	if [ ! -d $1 ];
		then
			mkdir $1 &>/dev/null
	fi
}

function new_link()
{
	if [ ! -f $2 ];
		then
			ln -sf $1 $2
	fi
}

root=`pwd`
echo "Initialisation des liens..."

new_link $root/libs/libft/libft.h $root/ft_ls/includes/libft.h
new_dir $root/ft_ls/libs
new_link $root/libs/libft/libft.a $root/ft_ls/libs/libft.a

new_link $root/libs/libft/libft.h $root/ft_ls1/includes/libft.h
new_dir $root/ft_ls1/libs
new_link $root/libs/libft/libft.a $root/ft_ls1/libs/libft.a

new_dir $root/demo/libs
new_link $root/libs/libft/libft.a $root/demo/libs/libft.a

echo "Initialisation finit"
