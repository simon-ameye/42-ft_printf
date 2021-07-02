OBJS_DIR = obj/
INC = ft_printf.h
NAME = libftprintf.a

SRCS += ft_printf.c
SRCS += ft_printf_parse.c
SRCS += ft_printf_print.c
SRCS += ft_printf_threat.c

OBJS = ${SRCS:.c=.o}
DIROBJS = $(addprefix ${OBJS_DIR},${OBJS})

CC = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : ${DIROBJS}
		ar rcs ${NAME} ${DIROBJS}

${DIROBJS}: ${OBJS_DIR}%.o: %.c ${OBJS_DIR}
		${CC} -c $< -o $@

${OBJS_DIR}:
		mkdir $@

clean:
		rm -rf ${DIROBJS}

fclean: clean
		rm -rf ${NAME}

re: fclean all

bonus:  ${DIROBJS}
				ar rcs ${NAME} ${DIROBJS} ${NAME}

.PHONY: all clean fclean re