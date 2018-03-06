# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    init.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/01 19:01:20 by pprikazs          #+#    #+#              #
#    Updated: 2018/03/06 12:06:24 by pprikazs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!bin/zsh

root=`pwd`

sh $root/uninit.sh &>/dev/null

echo "Initialisation des liens..."
ln -sf $root/libs/libft/libft.h $root/ft_ls/includes/libft.h

mkdir $root/ft_ls/libs &>/dev/null
ln -sf $root/libs/libft/libft.a $root/ft_ls/libs/libft.a
mkdir $root/demo/libs &>/dev/null
ln -sf $root/libs/libft/libft.a $root/demo/libs/libft.a

echo "Initialisation finit"
