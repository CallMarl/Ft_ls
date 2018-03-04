# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    uninit.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/01 19:12:19 by pprikazs          #+#    #+#              #
#    Updated: 2018/03/04 14:12:00 by pprikazs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!bin/zsh

root=`pwd`

echo "Suppression des fichiers superflux..."
sh $root/cleaner.sh

echo "Desinisialisation des liens..."

rm -f "$root/bin/lem-in"
rm -f $root/ft_ls/libs/libft.a
rm -rf $root/ft_ls/libs

echo "Désinitialisation finit..."
