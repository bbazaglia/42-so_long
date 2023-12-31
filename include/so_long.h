/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:15:21 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/06 10:15:26 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	int				num_lines;
	int				player;
	int				exit;
	int				collectibles;
	int				collected;
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
	mlx_image_t		*str_count;
	mlx_image_t		*str_moves;
	mlx_image_t		*reptile;
	mlx_image_t		*tree;
	mlx_image_t		*crystal;
	mlx_image_t		*door;
	mlx_image_t		*closed_door;
	mlx_image_t		*background;
	mlx_texture_t	*reptile_t;
	mlx_texture_t	*tree_t;
	mlx_texture_t	*crystal_t;
	mlx_texture_t	*door_t;
	mlx_texture_t	*closed_door_t;
	mlx_texture_t	*background_t;
}					t_game;

// Build and destroy matrixes
int					get_num_lines(char *argv);
char				**populate_matrix(char *argv, int num_lines);
char				**copy_matrix(char **matrix, int num_lines);
void				free_matrix(char **matrix, char **new_matrix);

// Map checking
void				check_map(char **matrix, char **new_matrix, t_game *game);
void				check_boundaries(char **matrix, char **new_matrix,
						int num_lines);
void				check_rectangle(char **matrix, char **new_matrix);
void				check_format(char *argv);
void				check_size(char **matrix, char **new_matrix, t_game *game);
void				check_characters(char **matrix, t_game *game, int x, int y);
int					check_path(t_game *game, char **matrix);
void				flood_fill(char **matrix, t_game *game, int x, int y);

// Initialize structs values
void				initialize_game(t_game *game);

// Movements and hooks functions
void				ft_hook(mlx_key_data_t keydata, void *param);
void				check_game_status(mlx_key_data_t keydata, t_game *game);
void				check_up_trees(t_game *game);
void				check_down_trees(t_game *game);
void				check_left_trees(t_game *game);
void				check_right_trees(t_game *game);
void				collect_crytals(t_game *game);

// Load textures, images and instances of the image
void				load_images(t_game *game, char **matrix, char **new_matrix);
void				place_images(t_game *game, char **matrix,
						char **new_matrix);
void				place_tree(t_game *game, char **matrix, char **new_matrix);
void				place_door(t_game *game, char **matrix, char **new_matrix);
void				place_crystals(t_game *game, char **matrix,
						char **new_matrix);
void				place_reptile(t_game *game, char **matrix,
						char **new_matrix);

// Delete images
void				delete_images(t_game *game);

// Error message
void				error_msg(char *error, char **matrix, char **new_matrix);

#endif