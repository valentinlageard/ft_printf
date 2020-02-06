LIBFT		=	libft/libft.a
NAME		=	libftprintf.a
SRC			=	ft_printf.c \
				format.c \
				parse_format.c \
				parse_format_utils.c \
				format_char.c \
				format_hex.c \
				format_int.c \
				format_pointer.c \
				format_str.c \
				format_uint.c \
				format_percent.c \
				format_validity.c

SRC_LIBFT	=	libft/ft_abs.c \
				libft/ft_atoi.c \
				libft/ft_bzero.c \
				libft/ft_calloc.c \
				libft/ft_isalnum.c \
				libft/ft_isalpha.c \
				libft/ft_isascii.c \
				libft/ft_isdigit.c \
				libft/ft_isprint.c \
				libft/ft_itoa.c \
				libft/ft_memccpy.c \
				libft/ft_memchr.c \
				libft/ft_memcmp.c \
				libft/ft_memcpy.c \
				libft/ft_memmove.c \
				libft/ft_memset.c \
				libft/ft_putchar_fd.c \
				libft/ft_putendl_fd.c \
				libft/ft_putnbr_fd.c \
				libft/ft_putstr_fd.c \
				libft/ft_rand.c \
				libft/ft_randr.c \
				libft/ft_split.c \
				libft/ft_strchr.c \
				libft/ft_strdup.c \
				libft/ft_strjoin.c \
				libft/ft_strlcat.c \
				libft/ft_strlcpy.c \
				libft/ft_strlen.c \
				libft/ft_strmapi.c \
				libft/ft_strncmp.c \
				libft/ft_strnstr.c \
				libft/ft_strrchr.c \
				libft/ft_strtrim.c \
				libft/ft_substr.c \
				libft/ft_tolower.c \
				libft/ft_toupper.c \
				libft/ft_lstadd_back.c \
				libft/ft_lstadd_front.c \
				libft/ft_lstclear.c \
				libft/ft_lstdelone.c \
				libft/ft_lstiter.c \
				libft/ft_lstlast.c \
				libft/ft_lstnew.c \
				libft/ft_lstsize.c \
				libft/ft_lstmap.c \
				libft/ft_iscinstr.c \
				libft/ft_cdup.c \
				libft/ft_min.c \
				libft/ft_max.c \
				libft/ft_utoa.c \
				libft/ft_utoabase.c \
				libft/ft_ultoabase.c \
				libft/ft_rtputchar_fd.c \
				libft/ft_rtputstr_fd.c

OBJS		=	$(SRC:.c=.o)

OBJS_LIBFT	=	$(SRC_LIBFT:.c=.o)

FLAGS		=	-Wall -Wextra -Werror
CC			=	gcc $(FLAGS)

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT) ft_printf.h
			ar rcs $(NAME) $(OBJS) $(OBJS_LIBFT)

%.o: %.c
			$(CC) -c -o $@ $<

$(LIBFT):
			make -C libft

clean:
			rm -f $(OBJS)
			make -C libft clean

fclean:		clean
			rm -f $(NAME)
			rm -f $(LIBFT)

re:			fclean all

.PHONY: 	all clean fclean re
