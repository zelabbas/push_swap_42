NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = check_arguments.c check_stack.c commands_push.c commands_swap.c commands_rotate.c \
	   commands_reverse.c ft_add_back.c ft_atol.c ft_putstr.c ft_split.c ft_strjoin.c \

all : ${NAME}

OBJS = ${SRCS:.c=.o}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBJS}
	${CC} ${CFLAGS} main.c ${OBJS} -o ${NAME}

clean :
	rm -rf ${OBJS}

fclean : clean
	rm -rf ${NAME}

re : fclean all