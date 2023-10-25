NAME	:= so_long
CC 		:= cc
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g3
LIBMLX	:= ./lib/MLX42
HEADERS	:= -I ./include -I $(LIBMLX)/include -I ./lib/LIBFT/include
LIBS	:= ./lib/LIBFT/libft.a $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRC	:= main.c \
			check_map.c \
			check_characters.c \
			error_msg.c \
			place_images.c \
			populate_matrix.c \
			flood_fill.c \
			free_matrix.c \
			hooks.c \
			load_images.c \
			load_textures.c 

OBJ	:= ${SRC:.c=.o}

PATH_FILE = src/

SRC_PATH = $(addprefix $(PATH_FILE), $(SRC))

OBJ_PATH = $(addprefix $(PATH_FILE), $(OBJ))

all: libmlx libft $(NAME)

libft:
	@make -C ./lib/LIBFT 
	@cp ./lib/LIBFT/libft.a $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(PATH_FILE)%.o: $(PATH_FILE)%.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<\n)"

$(NAME): $(OBJ_PATH)
	@$(CC) $(OBJ_PATH) $(LIBS) -o $(NAME)

clean:
	@make -C ./lib/LIBFT clean
	@rm -rf $(OBJ_PATH)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@make -C ./lib/LIBFT fclean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft
