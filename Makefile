NAME = so_long

NAME_BONUS = so_long_bonus

CC = cc

CFLAGS = -Wextra -Wall -Werror -Wunreachable-code -Ofast -g3

HEADERS = -I ./include -I ./lib/MLX42/include -I ./lib/LIBFT/include

LIBS = ./lib/LIBFT/libft.a ./lib/MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm

SRC	= $(addprefix ./src/, main.c \
			check_map.c \
			check_characters.c \
			error_msg.c \
			place_images.c \
			populate_matrix.c \
			flood_fill.c \
			free_matrix.c \
			hooks.c \
			hooks_utils.c \
			load_images.c)

BONUS_SRC = $(addprefix ./bonus/, main_bonus.c \
			check_map_bonus.c \
			check_characters_bonus.c \
			error_msg_bonus.c \
			place_images_bonus.c \
			populate_matrix_bonus.c \
			flood_fill_bonus.c \
			free_matrix_bonus.c \
			hooks_bonus.c \
			hooks_utils_bonus.c \
			load_images_bonus.c)

OBJ	= ${SRC:%.c=%.o}

BONUS_OBJ = ${BONUS_SRC:%.c=%.o}

all: libmlx libft $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIBS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<\n)"

bonus: libmlx libft $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJ)
	@$(CC) $(BONUS_OBJ) $(LIBS) -o $(NAME_BONUS)

libft:
	@make -C ./lib/LIBFT 
	@cp ./lib/LIBFT/libft.a $(NAME)

libmlx:
	@cmake ./lib/MLX42 -B ./lib/MLX42/build && make -C ./lib/MLX42/build -j4

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=suppress_mlx.sup ./so_long_bonus	

clean:
	@make -C ./lib/LIBFT clean
	@rm -rf $(OBJ)
	@rm -rf ./lib/MLX42/build
	@rm -rf $(BONUS_OBJ)

fclean: clean
	@make -C ./lib/LIBFT fclean
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft, bonus


