LIBFT		= libft/libft.a
NAME		= libftprintf.a
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
				format_validity.c

OBJS		=	$(SRC:.c=.o)

FLAGS		=	-Wall -Wextra -Werror
CC			=	gcc $(FLAGS)

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT) ft_printf.h
			ar rcs $(NAME) $(OBJS) $(LIBFT)

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
