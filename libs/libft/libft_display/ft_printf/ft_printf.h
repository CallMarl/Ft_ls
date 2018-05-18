/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:38:04 by pprikazs          #+#    #+#             */
/*   Updated: 2018/02/22 09:24:15 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stddef.h>
# include "libft.h"

# define FT_DISPLAY_SPE 0
# define FT_SIZE_SPE 1
# define FT_ACCURACY_SPE 2
# define FT_DISPOSITION_SPE 3
# define FT_SKEL_SIZE 4

typedef struct	s_skel
{
	char		*spe;
	int			val;
}				t_skel;

typedef struct	s_imt
{
	char		*type;
	t_list		*(*pfct)(uintmax_t val, t_skel **skel);
}				t_imt;

typedef struct	s_lgd
{
	char		*type;
	t_list		*(*pfct)(long double val, t_skel **skel);
}				t_lgd;

typedef struct	s_ptr
{
	char		*type;
	t_list		*(*pfct)(void *val, t_skel **skel);
}				t_ptr;

size_t			ft_lstiter_andsum(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_option_accu1(t_skel **skel, t_list *result, char *sign);
char			*ft_option_accu2(t_skel **skel, char *nbr, size_t *size);
char			*ft_option_disp(t_skel **skel, intmax_t val);
void			ft_option_usize(uintmax_t *val, char *size_spe);
void			ft_option_size(uintmax_t *val, char *size_spe);
char			*ft_getskel_spe(t_skel **skel, int type);
int				ft_getskel_val(t_skel **skel, int type, char *spe);
t_skel			**ft_reset_skel(t_skel **skel);
int				ft_setskel(t_skel **skel, int type, char *val, int nb);
int				ft_setupskel(t_skel **skel, int type, char *val, int nb);
t_list			*ft_bigc(uintmax_t val, t_skel **skel);
t_list			*ft_bigd(uintmax_t val, t_skel **skel);
t_list			*ft_bigo(uintmax_t val, t_skel **skel);
t_list			*ft_bigs(void *val, t_skel **skel);
t_list			*ft_bigx(uintmax_t val, t_skel **skel);
t_list			*ft_c(uintmax_t val, t_skel **skel);
t_list			*ft_d(uintmax_t val, t_skel **skel);
t_list			*ft_e(long double val, t_skel **skel);
t_list			*ft_f(long double val, t_skel **skel);
t_list			*ft_g(long double val, t_skel **skel);
t_list			*ft_i(uintmax_t val, t_skel **skel);
t_list			*ft_o(uintmax_t val, t_skel **skel);
t_list			*ft_p(void *val, t_skel **skel);
t_list			*ft_percent(uintmax_t val, t_skel **skel);
t_list			*ft_s(void *val, t_skel **skel);
t_list			*ft_u(uintmax_t val, t_skel **skel);
t_list			*ft_undef(t_skel **skel, char *flag, int size);
t_list			*ft_x(uintmax_t val, t_skel **skel);
t_skel			**ft_analyze_flag(char *flag, int size, t_skel **skel);
t_list			*ft_args(va_list ap, t_skel **skel, char *flag, int size);
int				ft_args_imt(va_list ap, t_skel **skel, char *skel_val,\
		t_list **result);
int				ft_args_lgd(va_list ap, t_skel **skel, char *skel_val,\
		t_list **result);
int				ft_args_ptr(va_list ap, t_skel **skel, char *skel_val,\
		t_list **result);
void			ft_displaybuff(t_list *elem);
void			ft_display_skel(t_skel **skel);
t_list			*ft_option(t_skel **skel, char *nbr, intmax_t val, size_t size);
int				ft_parse_flag(char **str, char **flag);
t_skel			**ft_initialize_skel(char *flag, int size);

#endif
