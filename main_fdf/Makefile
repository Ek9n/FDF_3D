NAME=fdf
CFLAGS=  -g -I/usr/local/include #-Wextra -Wall -Werror
LIBFT= libs/the_libft/libft.a
MLX = -L ./libs/minilibx-linux -lmlx -lXext -lX11 -lm
CC=cc

SRCS = fdf.c keypress_handling.c keypress_handling3D.c utils_colors.c utils_image.c utils_map.c utils_extra.c
OBJS	:= ${SRCS:.c=.o}

RM=rm -rf

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	@$(CC) $(OBJS) $(MLX) $(LIBFT) -o $(NAME)

$(MLX) :
	$(MAKE) -C ./libs/minilibx-linux

$(LIBFT) :
	$(MAKE) -C ./libs/the_libft

all: $(NAME)

clean:
		$(MAKE) clean -C ./libs/the_libft
		$(RM) $(OBJS)

fclean: clean
		$(MAKE) fclean -C ./libs/the_libft
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re