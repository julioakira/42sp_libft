SRC = ft_bzero.c \
	ft_isalpha.c

DIST_DIR = dist

NAME = libft.a

OBJ = ${addprefix ${DIST_DIR}/,${SRC:.c=.o}}

.PHONY = clean fclean

${NAME}: ${OBJ}
	ar -rcs ${NAME} ${OBJ}

${DIST_DIR}/%.o:%.c
	mkdir -p ${DIST_DIR}
	clang -c $< -o $@

clean:
	rm -f ${OBJ}
	rm -rf ${DIST_DIR}
	echo ${OBJ}

fclean: clean
	rm ${NAME}
