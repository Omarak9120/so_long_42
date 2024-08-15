NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
MLX_FLAGS = -L./mlx -lmlx -L./mlx -lXext -lX11 -lm

# Define paths to the printf and libft directories
PRINTF_DIR = ./printf
LIBFT_DIR = ./libft

# Define the libraries
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a

# Source files for the main project
SRC =   free_exit.c \
        player_movements.c \
        hooks.c \
        check_map_0.c \
        check_map_1.c \
        get_next_line_utils.c \
        get_next_line.c \
        main.c \
        so_long_utils_0.c \
        so_long_utils_1.c \
        render_fts.c \
        image_handle.c

OBJ = $(SRC:.c=.o)

# Ensure the libraries are built before compiling the main project
all: $(LIBFT_LIB) $(PRINTF_LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS) -Wl,--whole-archive $(LIBFT_LIB) -Wl,--no-whole-archive $(PRINTF_LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build the libft library
$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

# Build the printf library
$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all
