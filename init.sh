# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    init.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/01 19:01:20 by pprikazs          #+#    #+#              #
#    Updated: 2018/03/04 16:11:23 by pprikazs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!bin/zsh

root=`pwd`

sh $root/uninit.sh &>/dev/null

echo "Initialisation des liens..."
ln -sf $root/libs/libft/libft.h $root/ft_ls/includes/libft.h

mkdir $root/ft_ls/libs &>/dev/null
touch $root/libs/libft/libft.a
ln -sf $root/libs/libft/libft.a $root/ft_ls/libs/libft.a
rm $root/libs/libft/libft.a

echo "Initialisation finit"
