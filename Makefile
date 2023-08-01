DIRLIB		= ./libft/

SRCS	=	push_swap.c \
			utilities.c

OBJS	= ${SRCS:.c=.o}

LIBFT   = ./libft/libft.a

NAME	= push.a

CC		= gcc

AR		= ar rcs

RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g

NAMELFT		= libft.a

all:	push_swap

%.o: %.c
	${CC} -c $< -o $@
	
push_swap:	${NAME}
	${CC} push_swap.c ${NAME}  -fsanitize=address -g -o push_swap

$(NAME):	$(OBJS) $(LIBFT)
	ar rcs ${NAME} ${OBJS}

$(LIBFT):
	make -C ./libft
	cp ./libft/libft.a $(NAME)

clean:
	make clean -C ./libft
		$(RM) $(OBJS) $(BOBJ)

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME) $(OBJS) push_swap 

re:			fclean all
				cd ${DIRLIB} && ${MAKE} clean

.PHONY:		all clean fclean re