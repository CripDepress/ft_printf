SRCS	=	ft_printf.c ft_format_utils.c ft_utils.c ft_print_int.c \
		ft_print_ptr.c ft_print_str.c ft_print_hex.c ft_print_unsign.c
BONS	=	
OBJS	=	$(SRCS:.c=.o)
BOBJ	=	$(BONS:.c=.o)

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror -I.

NAME	=	libftprintf.a

all:		$(NAME)

$(NAME):	$(OBJS)
				ar rcs $(NAME) $(OBJS)

bonus:		$(OBJS) $(BOBJ)
				ar rcs $(NAME) $(OBJS) $(BOBJ)

norm:
				norminette $(NAME) $(SRCS) $(BONS)

clean:
				$(RM) $(OBJS) $(BOBJ)

fclean:		clean
				$(RM) $(NAME)

re:			fclean $(NAME)

test:
		$(CC) $(CFLAGS) $(SRCS)
		./a.out

.PHONY:		all clean fclean re bonus


