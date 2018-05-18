/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprikazs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:51:44 by pprikazs          #+#    #+#             */
/*   Updated: 2018/05/17 17:03:07 by pprikazs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <sys/types.h>
# include <stddef.h>
# include <stdint.h>

typedef enum		e_bool
{
	FALSE = 0,
	TRUE = 1
}					t_bool;

/*
** libft_binary
*/

# define MEM_SIZE sizeof(unsigned char *)

char				*ft_base2(unsigned char val, char *str);
int					ft_printf(char *str, ...);
void				ft_putbit_char(char val);
void				ft_putbit_int(int val);
void				ft_putbit_long(long val);
void				ft_putbit_short(short val);
void				ft_putbit_uchar(unsigned char val);
void				ft_putbit_uint(unsigned int val);
void				ft_putbit_ulong(unsigned long val);
void				ft_putbit_ushort(unsigned short val);

/*
** libf_buff
*/

# define FT_BUFF_SIZE 4096

typedef struct		s_buff
{
	void			*buff;
	size_t			cr;
	size_t			e_size;
	size_t			b_size;
}					t_buff;

int					ft_buffadd(t_buff *buff, const void *elem);
int					ft_buffextend(t_buff *buff, size_t nb);
void				ft_buffdel(t_buff *buff);
int					ft_buffinit(t_buff *buff, size_t nb, size_t (*size)(void));
/*
** libft_display
*/

void				ft_putbit(void *data, size_t n);
void				ft_putchar(char c);
short				ft_putchar_u(char *c);
void				ft_putclear(void);
void				ft_putcolor_24(const char *color, const char *str);
void				ft_putcolor_8(const char *color, const char *str);
void				ft_putcolor_hex24(long color, const char *str);
void				ft_putcolor_hex8(long color, const char *str);
void				ft_putendl(const char *str);
void				ft_putmemory(void *ptr, size_t n);
void				ft_putnbr(int nbr);
void				ft_putstr(const char *str);
void				ft_putstr_u(char *str);

/*
** libft_file
*/

# define FT_MAX_FD 256

int					ft_gnl(int fd, char **line);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(const char *str, int fd);
void				ft_putnbr_fd(int nbr, int fd);
void				ft_putstr_fd(const char *str, int fd);

/*
** libft_lst
*/

typedef struct		s_content
{
	void			*content;
	size_t			size;
}					t_content;

typedef struct		s_dlist
{
	void			*content;
	size_t			size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

typedef struct		s_list
{
	void			*content;
	size_t			size;
	struct s_list	*next;
}					t_list;

typedef struct		s_rot
{
	size_t			size;
	t_dlist			*head;
}					t_rot;

void				ft_dlstdel(t_dlist **alst, void (*del)(t_dlist *elem));
void				ft_dlstdel_elem(t_dlist *elem);
t_dlist				*ft_dlstextract(t_dlist **alst, int indice);
int					ft_dlstget(t_dlist *alst, t_content *content, int indice);
void				ft_dlstinsert(t_dlist **alst, t_dlist *elem, int indice);
int					ft_dlstissort_c(t_dlist *alst, size_t size);
int					ft_dlstissort_d(t_dlist *alst, size_t size);
void				ft_dlstiter(t_dlist *lst, void (*f)(t_dlist *elem));
void				ft_dlstiter_size(t_dlist *lst, size_t size, \
		void (*f)(t_dlist *elem));
t_dlist				*ft_dlstlast(t_dlist **alst);
t_dlist				*ft_dlstmap(t_dlist *lst, t_dlist *(*f)(t_dlist *elem));
size_t				ft_dlstmemsize(t_dlist *lst);
t_dlist				*ft_dlstnew(const void *content, size_t content_size);
int					ft_dlstpush(t_dlist **alst, void *data, \
		size_t content_size, void (*f)(t_dlist **list, t_dlist *elem));
void				ft_dlstpushb(t_dlist **alst, t_dlist *new_one);
void				ft_dlstpushf(t_dlist **alst, t_dlist *new_one);
t_dlist				*ft_dlstrecover(t_dlist *alst, int indice);
void				ft_dlstremove(t_dlist **alst, int indice);
t_dlist				*ft_dlstreplace(t_dlist **alst, t_dlist *elem, int indice);
int					ft_dlstset(t_dlist *alst, t_content content, int indice);
void				ft_dlstset_rot(t_dlist **alst, t_rot *rot);
int					ft_dlstsize(t_dlist *begin_list);
int					ft_dlstswap(t_dlist **alst, int indice);
void				ft_lstdel(t_list **alst, \
		void (*del)(void *elem, size_t size));
void				ft_lstdel_elem(t_list *elem);
t_list				*ft_lstextract(t_list **alst, int indice);
int					ft_lstget(t_list *alst, t_content *content, int indice);
void				ft_lstinsert(t_list **alst, t_list *elem, int indice);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstiter_size(t_list *lst, size_t size, \
		void (*f)(t_list *elem));
t_list				*ft_lstlast(t_list **elem);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_lstmemsize(t_list *alst);
t_list				*ft_lstnew(const void *content, size_t size);
int					ft_lstpush(t_list **alst, void *data, \
		size_t content_size, void (*f)(t_list **list, t_list *elem));
void				ft_lstpushb(t_list **alst, t_list *new_one);
void				ft_lstpushf(t_list **alst, t_list *new_one);
t_list				*ft_lstrecover(t_list *alst, int indice);
void				ft_lstremove(t_list **alst, int indice, \
		void (*del)(void *elem));
t_list				*ft_lstreplace(t_list **alst, t_list *elem, int indice);
int					ft_lstset(t_list *alst, t_content content, int indice);
int					ft_lstsize(t_list *begin_list);
int					ft_lstswap(t_list **alst, int indice);
t_dlist				*ft_rlstextract(t_rot *rot, int indice);
void				ft_rlstinsert(t_rot *rot, t_dlist *elem, int indice);
int					ft_rlstissort_c(t_rot rot);
void				ft_rlstiter(t_rot *rot, int size, void (*f)(t_dlist *elem));
void				ft_rlstremove(t_rot *rot, int indice);
void				ft_rlstrotate(t_rot *rot, int indice);
t_dlist				*ft_rlstset_heap(t_rot *rot);

/*
** libft_math
*/

# define ABS(Value) (Value >= 0) ? Value : -Value

int					ft_next_sqrt(int nb);
int					ft_pow(int x, int y);
int					ft_sqrt(int nb);

/*
** libft_memory
*/

void				*ft_bzero(void *ptr, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *ptrd, const void *ptrs, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *ptrd, const void *ptrs, size_t n);
void				*ft_memcpy_x(void *ptrd, const void *ptrs, size_t n);
void				ft_memdel(void **ptr);
void				ft_memdel_size(void *content, size_t size);
char				*ft_memjoin(const void *s1, const void *s2, size_t l1, \
		size_t l2);
int					ft_memjunc(void *ptr1, void *ptr2, size_t n);
void				*ft_memmove(void *ptrd, const void *ptrs, size_t n);
void				*ft_memset(void *ptr, int c, size_t n);
void				ft_memswap(void *s1, void *s2, size_t width);

/*
** libft_qsort
*/

void				ft_qsort(void *base, size_t nel, size_t width, \
		int (*cmp)(const void *, const void *));
int					ft_sort_intcmp_c(const void *v1, const void *v2);
int					ft_sort_strcmp_c(const void *v1, const void *v2);

/*
** libft_str
*/

int					ft_ischarval(uintmax_t val);
int					ft_isintval(uintmax_t val);
int					ft_islongval(uintmax_t val);
int					ft_isshortval(uintmax_t val);
int					ft_issort_c(int *array, size_t size);
int					ft_issort_d(int *array, size_t size);
void				ft_swap_uint(unsigned int *nb1, unsigned int *nb2);
int					ft_atoi(const char *str);
long				ft_atol(const char *str);
intmax_t			ft_atoim(const char *str);
uintmax_t			ft_atoum(const char *str);
size_t				ft_charsize_u(wchar_t c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_isupper(int c);
char				*ft_itoa(int nbr);
char				*ft_itoa_base(intmax_t nbr, char *base);
char				*ft_itoau_base(uintmax_t nbr, char *base);
void				ft_strarr_del(char	**arr);
int					ft_strarr_len(char **arr);
int					ft_strarr_size(char **arr);
char				*ft_strattach(const char *str1, const char *str2, \
		const char *occ);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *str, int c);
void				ft_strclr(char *str);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
int					ft_strcpy_x(char *dest, const char *src);
void				ft_strdel(char **str);
char				*ft_strdup(const char *s);
int					ft_strequ(const char *s1, const char *s2);
char				*ft_strimplode(char	**arr, char *occ);
int					ft_strisdigit(const char *str);
int					ft_strisnumber(const char *str);
void				ft_striter(char *str, void (*f)(char *val));
void				ft_striteri(char *str,\
		void (*f)(unsigned int val, char *s));
char				*ft_strjoin(const char *s1, const char *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src);
size_t				ft_strlen(const char *str);
char				*ft_strmap(const char *s, char (*f)(char c));
char				*ft_strmapi(const char *s,\
		char (*f)(unsigned int val, char c));
char				*ft_strncat(char *dest, const char *src, int nbr);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_strnequ(const char *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnew_c(size_t size, char c);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
char				*ft_strrchr(const char *str, int c);
int					ft_strsize_u(wchar_t *str);
char				**ft_strsplit(const char *s, char c);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
void				ft_strsup(char *s, int cr);
char				*ft_strtrim(const char *s1);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_unicode(wchar_t val);
int					ft_unicode_str(wchar_t *str, char **uni);

/*
** libft_time
*/

# define T_UTC 1

typedef struct		s_tm
{
	int				sec;
	int				min;
	int				hour;
	int				day;
	int				month;
	int				year;
	int				nbd;
}					t_tm;

t_tm				*ft_localtime(time_t *clock);
t_tm				*ft_localtime_r(time_t *clock, t_tm *date);
int					ft_time_count(time_t *clock, int time_type);

#endif
