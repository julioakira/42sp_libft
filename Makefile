SRC = 		ft_atoi.c \
			ft_calloc.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_memcpy.c \
			ft_memcmp.c \
			ft_memmove.c \
			ft_strchr.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strnstr.c \
			ft_tolower.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_memchr.c \
			ft_memcpy.c \
			ft_memset.c \
			ft_strdup.c \
			ft_strlcpy.c \
			ft_strncmp.c \
			ft_strrchr.c \
			ft_toupper.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
<<<<<<< HEAD
			ft_striteri.c \
=======
>>>>>>> fb3111c765990fd530310e4013db46fe39b84b0e
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c

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
