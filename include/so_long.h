
#include "../lib/LIBFT/include/ft_printf.h"
#include "../lib/LIBFT/include/get_next_line.h"
#include "../lib/LIBFT/include/get_next_line_bonus.h"
#include "MLX42/MLX42.h"
#include <fcntl.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define PIXELS 64

typedef struct s_game
{
	int				player;
	int				exit;
	int				collectible;
	int				space;
	int				wall;
	int				error;
	int				player_x;
	int				player_y;
	int				size_x;
	int				size_y;
	int				exit_reached;
	int				move_count;
	mlx_t			*mlx;
	mlx_key_data_t	*keydata;
	mlx_image_t		*reptile;
	mlx_image_t		*tree;
	mlx_image_t		*crystal;
	mlx_image_t		*door;
	mlx_image_t		*background;
	mlx_texture_t	*reptile_t;
	mlx_texture_t	*tree_t;
	mlx_texture_t	*crystal_t;
	mlx_texture_t	*door_t;
	mlx_texture_t	*background_t;
}					t_game;

void				initialize_game(t_game *game);
// void				ft_hook(void *param);
void				ft_hook(mlx_key_data_t keydata, void *param);
void				count_moves(t_game *game);
int					get_num_lines(char *argv);
void				check_map(char *argv, int num_lines, char **matrix,
						t_game *game);
char				**populate_matrix(char *argv, int num_lines);
void				free_matrix(char **matrix);
void				error_msg(char *error, char **matrix);
void				check_boundaries(char **matrix, int num_lines);
void				check_format(char *argv);
void				check_characters(char **matrix, t_game *game);
void				check_rectangle(char **matrix);
int					check_path(t_game *game, char **matrix);
void				flood_fill(char **matrix, t_game *game, int x, int y);
void				load_reptile(t_game *game, char **matrix);
void				load_background(t_game *game, char **matrix);
void				load_tree(t_game *game, char **matrix);
void				load_door(t_game *game, char **matrix);
void				load_crystal(t_game *game, char **matrix);
void				load_images(t_game *game, char **matrix);
void				place_images(t_game *game, char **matrix);
void				delete_images(t_game *game);
