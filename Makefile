DIRLIB		= ./ft_printf/ \

SRCS	=	push_swap.c \
			utilities.c \
			utilities1.c \
			utilities2.c \
			utilities3.c \
			utilities4.c \
			utilities5.c \
			checkers.c  \
			instructions.c \
			instructions2.c

OBJS	= ${SRCS:.c=.o}

LIBFT   = ./ft_printf/libft/libft.a

PRINTF	= ./ft_printf/libftprintf.a

NAME	= push.a

CC		= gcc

AR		= ar rcs

RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g

NAMELFT		= libft.a

NAMEPRINT	= libftprintf.a

all:	push_swap

# %.o: %.c
# 	${CC} -c $< -o $@

push_swap: ${NAME} ${PRINTF}
	gcc ${NAME} ${PRINTF} ${CFLAGS} -o push_swap


$(NAME):	$(OBJS) $(PRINTF)
	ar rcs ${NAME} ${OBJS}

$(PRINTF):
	make -C ./ft_printf
	cp ./ft_printf/libftprintf.a $(NAME)

clean:
	make clean -C ./ft_printf/libft
	make clean -C ./ft_printf
		$(RM) $(OBJS) $(BOBJ) 

fclean: 
	make fclean -C ./ft_printf/libft
	make fclean -C ./ft_printf
	$(RM) $(NAME) $(OBJS) push_swap 

re:
	${MAKE} fclean		
	cd ${DIRLIB} && ${MAKE} fclean
	cd ${DIRLIB}/libft && ${MAKE} fclean
	${MAKE}

.PHONY:		all clean fclean re