NAME = cub3D
SRC = 	cub3D.c parser.c parser_utils.c parser_utils_2.c utils.c\
validate_map.c validate_map_utils.c images.c ray_casting.c\
ray_casting_utils.c ray_casting_utils_2.c movement.c
LIBFT_DIR	= libft
LIBFT		= libft/libft.a
MLX_DIR		= mlx_linux
MLX_INCLUDE = -Imlx_linux
CC			= @cc
CFLAGS		= -Wall -Wextra -Werror -g3 #-fsanitize=address,undefined
MLX_FLAGS 	= -L$(MLX_DIR) -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm

all:		$(NAME)

$(NAME):	$(SRC)
			@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
			@$(MAKE) --no-print-directory -C $(MLX_DIR)
			$(CC) $(CFLAGS) $(^) $(MLX_FLAGS) -o $(@) $(LIBFT)

clean:
			@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
			@$(MAKE) --no-print-directory -C $(MLX_DIR) clean

fclean:		clean
			@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
			@$(MAKE) --no-print-directory -C $(MLX_DIR) clean
			@rm -f $(NAME)

test_val_wrong_map:	all
	@for map_file in ./maps/wrong/*.cub; do \
		echo "$$map_file"; \
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $$map_file; \
	done

good:		all
			@for file in ./maps/good/*; do \
				echo "$$file"; \
				./$(NAME) $$file; \
				valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $$map_file; \
			done

wrong:		all
			@for file in ./maps/wrong/*; do \
				echo "$$file"; \
				./$(NAME) $$file; \
			done

re:			fclean all

.PHONY:		all clean fclean re