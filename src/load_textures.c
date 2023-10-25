#include "so_long.h"

void	load_background(t_game *game, char **matrix, char **new_matrix)
{
	game->background_t = mlx_load_png("./img/x4/grass.png");
	if (!game->background_t)
		error_msg("Error loading the background texture", matrix, new_matrix);
	game->background = mlx_texture_to_image(game->mlx, game->background_t);
}

void	load_reptile(t_game *game, char **matrix, char **new_matrix)
{
	game->reptile_t = mlx_load_png("./img/x4/reptile_front.png");
	if (!game->reptile_t)
		error_msg("Error loading the reptile texture", matrix, new_matrix);
	game->reptile = mlx_texture_to_image(game->mlx, game->reptile_t);
}

void	load_tree(t_game *game, char **matrix, char **new_matrix)
{
	game->tree_t = mlx_load_png("./img/x4/tree.png");
	if (!game->tree_t)
		error_msg("Error loading the tree texture", matrix, new_matrix);
	game->tree = mlx_texture_to_image(game->mlx, game->tree_t);
}

void	load_crystal(t_game *game, char **matrix, char **new_matrix)
{
	game->crystal_t = mlx_load_png("./img/x4/crystal.png");
	if (!game->crystal_t)
		error_msg("Error loading the crystal texture", matrix, new_matrix);
	game->crystal = mlx_texture_to_image(game->mlx, game->crystal_t);
}

void	load_door(t_game *game, char **matrix, char **new_matrix)
{
	game->door_t = mlx_load_png("./img/x4/door.png");
	if (!game->door_t)
		error_msg("Error loading the door texture", matrix, new_matrix);
	game->door = mlx_texture_to_image(game->mlx, game->door_t);
}
