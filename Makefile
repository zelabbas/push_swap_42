NAME = push_swap

NAME_B = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = Mandatory/check_arguments.c Mandatory/check_stack.c Mandatory/commands_push.c Mandatory/commands_swap.c \
	   Mandatory/commands_rotate.c Mandatory/commands_reverse.c Mandatory/ft_add_back.c Mandatory/ft_atol.c \
	   Mandatory/ft_putstr.c Mandatory/ft_split.c Mandatory/ft_strjoin.c Mandatory/utils_sort_stack.c \
	   Mandatory/utils_to_sort_stack.c Mandatory/utils_update_stacks.c Mandatory/ft_strdup.c Mandatory/push_swap.c\

SRCS_B = Bonus/check_arguments_b.c Bonus/checker.c Bonus/commands_push_b.c Bonus/commands_reverse_b.c \
		 Bonus/commands_rotate_b.c Bonus/commands_swap_b.c Bonus/ft_strcmp.c Bonus/get_next_line.c Bonus/get_next_line_utils.c \
		 Bonus/utils_checker.c Bonus/utils_free.c Bonus/utils_oprts.c Mandatory/ft_split.c Mandatory/ft_atol.c \
		 Mandatory/ft_strjoin.c\

all : ${NAME}

OBJS = ${SRCS:.c=.o}

OBJS_B = ${SRCS_B:.c=.o}

%.o : %.c ./Includes/push.h ./Includes/get_next_line.h
	${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBJS}
	${CC} ${OBJS} -o ${NAME}

${NAME_B} : ${OBJS_B}
	${CC} ${OBJS_B} -o ${NAME_B}

bonus : ${NAME_B};

clean :
	rm -rf ${OBJS} ${OBJS_B}

fclean : clean
	rm -rf ${NAME} ${NAME_B}

re : fclean all