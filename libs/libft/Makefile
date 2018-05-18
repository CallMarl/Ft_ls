NAME = libft.a
CC = ar
FLAGS = -Wall -Wextra -Werror

ROOT = $(shell dirname `pwd`)
DEBUG = no
ifeq ($(DEBUG), yes)
	FLAGS = -g -w
endif

INCLUDES = -I./ \
		   -I./libft_display/ft_printf/ \
		   -I./libft_time/

SRCS = ./libft_binary/ft_base2.c \
	   ./libft_binary/ft_putbit.c \
	   ./libft_binary/ft_putbit_char.c \
	   ./libft_binary/ft_putbit_int.c \
	   ./libft_binary/ft_putbit_long.c \
	   ./libft_binary/ft_putbit_short.c \
	   ./libft_binary/ft_putbit_uchar.c \
	   ./libft_binary/ft_putbit_uint.c \
	   ./libft_binary/ft_putbit_ulong.c \
	   ./libft_binary/ft_putbit_ushort.c \
	   ./libft_buff/ft_buffadd.c \
	   ./libft_buff/ft_buffextend.c \
	   ./libft_buff/ft_buffdel.c \
	   ./libft_buff/ft_buffinit.c \
	   ./libft_display/ft_printf/extra/ft_lstiter_andsum.c \
	   ./libft_display/ft_printf/ft_analyze_flag.c \
	   ./libft_display/ft_printf/ft_args.c \
	   ./libft_display/ft_printf/ft_args_imt.c \
	   ./libft_display/ft_printf/ft_args_lgd.c \
	   ./libft_display/ft_printf/ft_args_ptr.c \
	   ./libft_display/ft_printf/ft_display.c \
	   ./libft_display/ft_printf/ft_option.c \
	   ./libft_display/ft_printf/ft_parser.c \
	   ./libft_display/ft_printf/ft_printf.c \
	   ./libft_display/ft_printf/ft_skeleton.c \
	   ./libft_display/ft_printf/option/ft_option_accu1.c \
	   ./libft_display/ft_printf/option/ft_option_accu2.c \
	   ./libft_display/ft_printf/option/ft_option_disp.c \
	   ./libft_display/ft_printf/option/ft_option_size.c \
	   ./libft_display/ft_printf/skel/ft_getskel_spe.c \
	   ./libft_display/ft_printf/skel/ft_getskel_val.c \
	   ./libft_display/ft_printf/skel/ft_resetskel.c \
	   ./libft_display/ft_printf/skel/ft_setskel.c \
	   ./libft_display/ft_printf/skel/ft_setupskel.c \
	   ./libft_display/ft_printf/type/ft_bigc.c \
	   ./libft_display/ft_printf/type/ft_bigd.c \
	   ./libft_display/ft_printf/type/ft_bigo.c \
	   ./libft_display/ft_printf/type/ft_bigs.c \
	   ./libft_display/ft_printf/type/ft_bigx.c \
	   ./libft_display/ft_printf/type/ft_c.c \
	   ./libft_display/ft_printf/type/ft_d.c \
	   ./libft_display/ft_printf/type/ft_e.c \
	   ./libft_display/ft_printf/type/ft_f.c \
	   ./libft_display/ft_printf/type/ft_g.c \
	   ./libft_display/ft_printf/type/ft_i.c \
	   ./libft_display/ft_printf/type/ft_o.c \
	   ./libft_display/ft_printf/type/ft_p.c \
	   ./libft_display/ft_printf/type/ft_percent.c \
	   ./libft_display/ft_printf/type/ft_s.c \
	   ./libft_display/ft_printf/type/ft_u.c \
	   ./libft_display/ft_printf/type/ft_undef.c \
	   ./libft_display/ft_printf/type/ft_x.c \
	   ./libft_display/ft_putchar.c \
	   ./libft_display/ft_putchar_u.c \
	   ./libft_display/ft_putclear.c \
	   ./libft_display/ft_putcolor_24.c \
	   ./libft_display/ft_putcolor_8.c \
	   ./libft_display/ft_putcolor_hex24.c \
	   ./libft_display/ft_putcolor_hex8.c \
	   ./libft_display/ft_putendl.c \
	   ./libft_display/ft_putmemory.c \
	   ./libft_display/ft_putnbr.c \
	   ./libft_display/ft_putstr.c \
	   ./libft_display/ft_putstr_u.c \
	   ./libft_file/ft_gnl.c \
	   ./libft_file/ft_putchar_fd.c \
	   ./libft_file/ft_putendl_fd.c \
	   ./libft_file/ft_putnbr_fd.c \
	   ./libft_file/ft_putstr_fd.c \
	   ./libft_lst/ft_dlstdel.c \
	   ./libft_lst/ft_dlstdel_elem.c \
	   ./libft_lst/ft_dlstextract.c \
	   ./libft_lst/ft_dlstget.c \
	   ./libft_lst/ft_dlstinsert.c \
	   ./libft_lst/ft_dlstissort_c.c \
	   ./libft_lst/ft_dlstissort_d.c \
	   ./libft_lst/ft_dlstiter.c \
	   ./libft_lst/ft_dlstiter_size.c \
	   ./libft_lst/ft_dlstlast.c \
	   ./libft_lst/ft_dlstmap.c \
	   ./libft_lst/ft_dlstmemsize.c \
	   ./libft_lst/ft_dlstnew.c \
	   ./libft_lst/ft_dlstpush.c \
	   ./libft_lst/ft_dlstpushb.c \
	   ./libft_lst/ft_dlstpushf.c \
	   ./libft_lst/ft_dlstrecover.c \
	   ./libft_lst/ft_dlstremove.c \
	   ./libft_lst/ft_dlstreplace.c \
	   ./libft_lst/ft_dlstset.c \
	   ./libft_lst/ft_dlstset_rot.c \
	   ./libft_lst/ft_dlstsize.c \
	   ./libft_lst/ft_dlstswap.c \
	   ./libft_lst/ft_lstdel.c \
	   ./libft_lst/ft_lstdel_elem.c \
	   ./libft_lst/ft_lstextract.c \
	   ./libft_lst/ft_lstget.c \
	   ./libft_lst/ft_lstinsert.c \
	   ./libft_lst/ft_lstiter.c \
	   ./libft_lst/ft_lstiter_size.c \
	   ./libft_lst/ft_lstlast.c \
	   ./libft_lst/ft_lstmap.c \
	   ./libft_lst/ft_lstmemsize.c \
	   ./libft_lst/ft_lstnew.c \
	   ./libft_lst/ft_lstpush.c \
	   ./libft_lst/ft_lstpushb.c \
	   ./libft_lst/ft_lstpushf.c \
	   ./libft_lst/ft_lstrecover.c \
	   ./libft_lst/ft_lstremove.c \
	   ./libft_lst/ft_lstreplace.c \
	   ./libft_lst/ft_lstset.c \
	   ./libft_lst/ft_lstsize.c \
	   ./libft_lst/ft_lstswap.c \
	   ./libft_lst/ft_rlstextract.c \
	   ./libft_lst/ft_rlstinsert.c \
	   ./libft_lst/ft_rlstissort_c.c \
	   ./libft_lst/ft_rlstiter.c \
	   ./libft_lst/ft_rlstremove.c \
	   ./libft_lst/ft_rlstrotate.c \
	   ./libft_lst/ft_rlstset_heap.c \
	   ./libft_math/ft_next_sqrt.c \
	   ./libft_math/ft_pow.c \
	   ./libft_math/ft_sqrt.c \
	   ./libft_memory/ft_bzero.c \
	   ./libft_memory/ft_memalloc.c \
	   ./libft_memory/ft_memccpy.c \
	   ./libft_memory/ft_memchr.c \
	   ./libft_memory/ft_memcmp.c \
	   ./libft_memory/ft_memcpy.c \
	   ./libft_memory/ft_memcpy_x.c \
	   ./libft_memory/ft_memdel.c \
	   ./libft_memory/ft_memdel_size.c \
	   ./libft_memory/ft_memjoin.c \
	   ./libft_memory/ft_memjunc.c \
	   ./libft_memory/ft_memmove.c \
	   ./libft_memory/ft_memset.c \
	   ./libft_memory/ft_memswap.c \
	   ./libft_nbr/ft_ischarval.c \
	   ./libft_nbr/ft_isintval.c \
	   ./libft_nbr/ft_islongval.c \
	   ./libft_nbr/ft_isshortval.c \
	   ./libft_nbr/ft_issort_c.c \
	   ./libft_nbr/ft_issort_d.c \
	   ./libft_nbr/ft_swap_uint.c \
	   ./libft_sort/ft_qsort.c \
	   ./libft_sort/ft_sort_intcmp_c.c \
	   ./libft_sort/ft_sort_strcmp_c.c \
	   ./libft_sort/ft_qsort.c \
	   ./libft_str/ft_atoi.c \
	   ./libft_str/ft_atoim.c \
	   ./libft_str/ft_atol.c \
	   ./libft_str/ft_atoum.c \
	   ./libft_str/ft_charsize_u.c \
	   ./libft_str/ft_isalnum.c \
	   ./libft_str/ft_isalpha.c \
	   ./libft_str/ft_isascii.c \
	   ./libft_str/ft_isdigit.c \
	   ./libft_str/ft_islower.c \
	   ./libft_str/ft_isprint.c \
	   ./libft_str/ft_isupper.c \
	   ./libft_str/ft_itoa.c \
	   ./libft_str/ft_itoa_base.c \
	   ./libft_str/ft_itoau_base.c \
	   ./libft_str/ft_strarr_del.c \
	   ./libft_str/ft_strarr_len.c \
	   ./libft_str/ft_strarr_size.c \
	   ./libft_str/ft_strattach.c \
	   ./libft_str/ft_strcat.c \
	   ./libft_str/ft_strchr.c \
	   ./libft_str/ft_strclr.c \
	   ./libft_str/ft_strcmp.c \
	   ./libft_str/ft_strcpy.c \
	   ./libft_str/ft_strcpy_x.c \
	   ./libft_str/ft_strdel.c \
	   ./libft_str/ft_strdup.c \
	   ./libft_str/ft_strequ.c \
	   ./libft_str/ft_strimplode.c \
	   ./libft_str/ft_strisdigit.c \
	   ./libft_str/ft_strisnumber.c \
	   ./libft_str/ft_striter.c \
	   ./libft_str/ft_striteri.c \
	   ./libft_str/ft_strjoin.c \
	   ./libft_str/ft_strlcat.c \
	   ./libft_str/ft_strlcpy.c \
	   ./libft_str/ft_strlen.c \
	   ./libft_str/ft_strmap.c \
	   ./libft_str/ft_strmapi.c \
	   ./libft_str/ft_strncat.c \
	   ./libft_str/ft_strncmp.c \
	   ./libft_str/ft_strncpy.c \
	   ./libft_str/ft_strnequ.c \
	   ./libft_str/ft_strnew.c \
	   ./libft_str/ft_strnew_c.c \
	   ./libft_str/ft_strnstr.c \
	   ./libft_str/ft_strrchr.c \
	   ./libft_str/ft_strsize_u.c \
	   ./libft_str/ft_strsplit.c \
	   ./libft_str/ft_strstr.c \
	   ./libft_str/ft_strsub.c \
	   ./libft_str/ft_strsup.c \
	   ./libft_str/ft_strtrim.c \
	   ./libft_str/ft_tolower.c \
	   ./libft_str/ft_toupper.c \
	   ./libft_str/ft_unicode.c \
	   ./libft_str/ft_unicode_str.c \
	   ./libft_time/ft_isbisextil.c \
	   ./libft_time/ft_localtime.c \
	   ./libft_time/ft_localtime_r.c \
	   ./libft_time/ft_time_count.c \
	   ./libft_time/ft_time_month.c \
	   ./libft_time/ft_time_year.c

OBJ = $(SRCS:%.c=%.o)
DEPS = includes/*.h Makefile
DEPS = $(shell find . -regex ".*\.[ch]") 

.PHONY: all clean fclean re
.SUFFIXES:

%.o : %.c
	gcc $(INCLUDES) -c $< -o $@ $(FLAGS)
	
$(NAME) : $(OBJ) $(DEPS)
	@$(CC) -rc $@ $(OBJ);

all : $(NAME)

clean :
	@$(RM) -f $(OBJ)

fclean : clean
	@$(RM) -f $(NAME)

re :
	@$(MAKE) fclean
	@$(MAKE) all
