DIRLIB		= ./ft_printf/ \

SRCS	=	push_swap.c \
			utilities.c \
			checkers.c  \
			instructions.c

OBJS	= ${SRCS:.c=.o}

LIBFT   = ./ft_printf/libft/libft.a

PRINTF	= ./ft_printf/print.a

NAME	= push.a

CC		= gcc

AR		= ar rcs

RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror

NAMELFT		= libft.a

NAMEPRINT	= libftprintf.a

all:	push_swap

%.o: %.c
	${CC} -c $< -o $@
	
push_swap:	${NAME}
	${CC} push_swap.c ${NAME} -o push_swap
# -fsanitize=address -g
$(NAME):	$(OBJS) ${PRINTF}
	ar rcs ${NAME} ${OBJS}

$(PRINTF):
	make -C ./ft_printf
	cp ./ft_printf/libftprintf.a $(NAME)

clean:
	make clean -C ./ft_printf/libft
	make clean -C ./ft_printf
		$(RM) $(OBJS) $(BOBJ)

fclean: clean
	make clean -C ./ft_printf/libft
	make clean -C ./ft_printf
	$(RM) $(NAME) $(OBJS) push_swap 

re:			fclean all
				cd ${DIRLIB} && ${MAKE} clean

.PHONY:		all clean fclean re