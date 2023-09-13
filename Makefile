NAME = cub3D
LIBFT = libft/libft.a
LIBFT_PATH = libft/
LIBMLX_DIR = ./mlx_linux
MLX_INCLUDE = -Imlx_linux
SRC = cub3D.c parser.c parser_utils.c parser_utils_2.c utils.c
RM = @rm -f
CC = @cc
CFLAGS = -Wall -Wextra -Werror -g -o cub3D -fsanitize=address
MLX_FLAGS = 	-L$(LIBMLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

OBJ = $(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ)	
				@$(MAKE) --no-print-directory -C $(LIBMLX_DIR)
				@$(MAKE) --no-print-directory -C $(LIBFT_PATH)
				$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(@) $(LIBFT) 

clean:
				make clean -C $(LIBFT_PATH)
				make clean -C $(LIBMLX_DIR)
				$(RM) $(OBJ)

fclean: 		clean
				make fclean -C $(LIBFT_PATH)
				$(RM) $(NAME)

re:		fclean	$(NAME) $(OBJ)

.PHONY: all clean fclean re