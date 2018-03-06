# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    uninit.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/01 19:12:19 by pprikazs          #+#    #+#              #
#    Updated: 2018/03/06 12:05:55 by pprikazs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!bin/zsh

root=`pwd`

echo "Suppression des fichiers superflux..."
sh $root/cleaner.sh

echo "Desinisialisation des liens..."

rm -f $root/ft_ls/libs/libft.a
rm -rf $root/ft_ls/libs
rm -f $root/demo/libs/libft.a
rm -rf $root/demo/libs

echo "Désinitialisation finit..."
