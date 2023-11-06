/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:15:06 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/06 10:15:12 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "MLX42/MLX42.h"
# include "libft.h"
# include <fcntl.h>
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PIXELS 64

typedef struct s_game
{
	char			**matrix;
	char			**new_matrix;
	int				num_lines;
	int				player;
	int				exit;
	int				collectibles;
	int				collected;
	int				space;
	int				wall;
	int				enemy;
	int				error;
	int				player_x;
	int				player_y;
	int				exit_x;
	int				exit_y;
	int				size_x;
	int				size_y;
	int				exit_reached;
	int				move_count;
	mlx_t			*mlx;
	mlx_key_data_t	*keydata;
	mlx_image_t		*str_count;
	mlx_image_t		*str_moves;
	mlx_image_t		*reptile;
	mlx_image_t		*tree;
	mlx_image_t		*door;
	mlx_image_t		*closed_door;
	mlx_image_t		*background;
	mlx_image_t		*crystal;
	mlx_image_t		*flame;
	mlx_texture_t	*reptile_t;
	mlx_texture_t	*tree_t;
	mlx_texture_t	*door_t;
	mlx_texture_t	*closed_door_t;
	mlx_texture_t	*background_t;
	mlx_texture_t	*crystal_t;
	mlx_texture_t	*flame_t;
}					t_game;

// Build and destroy matrixes
int					get_num_lines(char *argv);
char				**populate_matrix(char *argv, t_game *game);
char				**copy_matrix(t_game *game);
void				free_matrix(t_game *game);

// Map checking
void				check_map(t_game *game);
void				check_boundaries(t_game *game);
void				check_rectangle(t_game *game);
void				check_format(char *argv);
void				check_size(t_game *game);
void				check_characters(t_game *game, int x, int y);
int					check_path(t_game *game);
void				flood_fill(t_game *game, int x, int y);

// Initialize structs values
void				initialize_game(t_game *game);

// Movements, hooks and animation functions
void				ft_hook(mlx_key_data_t keydata, void *param);
void				check_game_status(mlx_key_data_t keydata, t_game *game);
void				move_reptile(t_game *game, int dx, int dy);
void				print_move_count(t_game *game);
void				check_flame(t_game *game);
void				collect_crystals(t_game *game);
void				animation(t_game *game);
void				animation_wrapper(void *param);

// Load images, place them according to the map and delete them
void				load_images(t_game *game);
void				place_image(t_game *game, void *image, char character);
void				place_images(t_game *game);
void				delete_images(t_game *game);

// Error message
void				error_msg(char *error, t_game *game);

#endif