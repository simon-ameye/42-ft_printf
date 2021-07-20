OBJS_DIR = obj/
INC = ft_printf.h
NAME = libftprintf.a

SRCS += ft_printf.c
SRCS += ft_printf_parse.c
SRCS += ft_printf_print.c
SRCS += ft_printf_threat.c
SRCS += ft_printf_utils.c
SRCS += ft_printf_put_nums.c

OBJS = ${SRCS:.c=.o}
DIROBJS = $(addprefix ${OBJS_DIR},${OBJS})

CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : ${DIROBJS} ${LIBFT}
		ar rcs ${NAME} ${DIROBJS}

${DIROBJS}: ${OBJS_DIR}%.o: %.c ${OBJS_DIR}
		${CC} -c $< -o $@

${OBJS_DIR}:
		mkdir $@

bonus :	all

clean:
		rm -rf ${DIROBJS}
		$(MAKE) clean -C ./libft

fclean: clean
		rm -rf ${NAME}
		$(MAKE) fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re