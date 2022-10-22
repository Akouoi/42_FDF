PROG	=	fdf
cg		=	"\033[1;32m
cb		=	"\033[0;36m
cO		=	"\033[1;33m
c		=	\033[0m"

SRC		=	0_main.c			\
			0_free.c			\
			0_print.c			\
			0_math.c			\
			1_init.c			\
			2_get_data.c		\
			3_get_coord.c		\
			3_define_window.c	\
			4_show.c			\
			5_line.c			\
			6_event.c	  		\

OBJ		=	$(SRC:.c=.o)

CC		=	gcc
RM		=	rm -f
CFLAG	=	-Wall -Werror -Wextra -I/usr/include -Imlx_Linux -O3 -c $< -o $@
SFLAG	=	-fsanitize=address -g3
LFLAG	=	-Lmlx_Linux -lmlx_Linux -L/usr/lib -Imlx_Linux -lXext -lX11 -lm -lz

all:		$(PROG)

$(PROG):	$(OBJ)
			$(MAKE) -s all -C libft
			cp libft/libft.a mlx_Linux/libmlx.a
			$(MAKE) all -C mlx_Linux
			@echo $(cO)			MAKE MLX	ALL	$(c)
			$(CC) $(OBJ) $(LFLAG) -o $(PROG)
			@echo $(cg)			MAKE FDF	ALL			$(c)

%.o: %.c
			$(CC) $(CFLAG)

clean:
			clear
			$(MAKE) fclean -C ./libft
			$(MAKE) clean -C ./mlx_Linux
			@echo $(cO)			MAKE MLX	CLEAN	$(c)
			$(RM) $(NAME) $(OBJ)
			@echo $(cb)			MAKE FDF	CLEAN	$(c)

fclean: clean
			rm -f $(PROG)
			@echo $(cb)			MAKE FDF	FCLEAN	$(c)


re: fclean all

.PHONY: all clean fclean re

# .SILENT:
