cg		=	"\033[1;32m
cb		=	"\033[0;36m
cO		=	"\033[1;33m
c		=	\033[0m"

NAME	=	libft.a
CC		=	gcc
CFLAG	=	-Wall -Werror -Wextra

SRC		=	ft_atoi.c		\
			ft_bzero.c		\
			ft_calloc.c		\
			ft_isalnum.c	\
			ft_isalpha.c 	\
			ft_isascii.c	\
			ft_isdigit.c	\
			ft_isprint.c	\
			ft_itoa.c		\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_memcpy.c		\
			ft_memmove.c	\
			ft_memset.c		\
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c	\
			ft_putstr_fd.c	\
			ft_split.c		\
			ft_strchr.c		\
			ft_strdup.c		\
			ft_striteri.c	\
			ft_strjoin.c	\
			ft_strlcpy.c	\
			ft_strlen.c		\
			ft_strlcat.c	\
			ft_strmapi.c	\
			ft_strncmp.c	\
			ft_strnstr.c	\
			ft_strrchr.c	\
			ft_strtrim.c	\
			ft_substr.c		\
			ft_tolower.c	\
			ft_toupper.c	\
			ft_dec.c	\
			ft_hex.c	\
			ft_str.c	\
			ft_printf.c \
			get_next_line.c			\
			get_next_line_utils.c	\
			ft_lstlast_bonus.c \
			ft_lstnew_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstadd_back_bonus.c	\
			ft_lstsize_bonus.c	\
			ft_inter.c
			# ft_lstadd_front_bonus.c \
			# ft_lstdelone_bonus.c \
			# ft_lstiter_bonus.c \
			# ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)
	@echo $(cb)			MAKE LIBFT	ALL	$(c)

%.o: %.c
	$(CC) -c $(CFLAG) $(SRC)

clean:
	rm -f $(OBJ)
	@echo $(cb)			MAKE LIBFT	CLEAN	$(c)

fclean: clean
	rm -f $(NAME)
	@echo $(cb)			MAKE LIBFT	FCLEAN	$(c)

re: fclean all

.PHONY: all build bonus clean fclean re

# .SILENT:
