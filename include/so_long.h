
#include "../lib/LIBFT/include/ft_printf.h"
#include "../lib/LIBFT/include/get_next_line.h"
#include "../lib/LIBFT/include/get_next_line_bonus.h"
#include "MLX42/MLX42.h"
#include <fcntl.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define WIDTH 512
#define HEIGHT 512

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
	mlx_texture_t	*texture;
	mlx_image_t		*img;
}					t_game;
void				initialize_game(t_game *game);
void				ft_hook(void *param);
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