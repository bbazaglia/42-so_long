#include "so_long.h"

void	load_images(t_game *game, char **matrix)
{
    load_background(game, matrix);
    load_reptile(game, matrix);
    load_tree(game, matrix);
    load_crystal(game, matrix);
    load_door(game, matrix);
    place_images(game, matrix);
}


void	place_images(t_game *game, char **matrix)
{
	int	x;
	int	y;

	x = 0;
	while (matrix[x])
	{
		y = 0;
		while (matrix[x][y])
		{
			if (mlx_image_to_window(game->mlx, game->background, y * PIXELS, x * PIXELS) < 0)
				error_msg("Error loading the image", matrix);
			y++;
		}
		x++;
	}
	x = 0;
	while (matrix[x])
	{
		y = 0;
		while (matrix[x][y])
		{
			if (matrix[x][y] == '1')
			{
				if (mlx_image_to_window(game->mlx, game->tree, y * PIXELS, x * PIXELS) < 0)
					error_msg("Error loading the image", matrix);
			}
			y++;
		}
		x++;
	}
	x = 0;
	while (matrix[x])
	{
		y = 0;
		while (matrix[x][y])
		{
			if (matrix[x][y] == 'E')
			{
				if (mlx_image_to_window(game->mlx, game->door, y * PIXELS, x * PIXELS) < 0)
					error_msg("Error loading the image", matrix);
			}
			y++;
		}
		x++;
	}
	x = 0;
	while (matrix[x])
	{
		y = 0;
		while (matrix[x][y])
		{
			if (matrix[x][y] == 'C')
			{
				if (mlx_image_to_window(game->mlx, game->crystal, y * PIXELS, x * PIXELS) < 0)
					error_msg("Error loading the image", matrix);
			}
			y++;
		}
		x++;
	}
	x = 0;
	while (matrix[x])
	{
		y = 0;
		while (matrix[x][y])
		{
			if (matrix[x][y] == 'P')
			{
				if (mlx_image_to_window(game->mlx, game->reptile, y * PIXELS, x
						* PIXELS) < 0)
					error_msg("Error loading the image", matrix);
			}
			y++;
		}
		x++;
	}
	// if (matrix[x][y] == 'P')
	// {
	// 	if (mlx_image_to_window(game->mlx, game->reptile, y * PIXELS, x
	// 			* PIXELS) < 0)
	// 		error_msg("Error loading the image", matrix);
	// }
	// else if (matrix[x][y] == '1')
	// {
	// 	if (mlx_image_to_window(game->mlx, game->tree, y * PIXELS, x
	// 			* PIXELS) < 0)
	// 		error_msg("Error loading the image", matrix);
	// }
	// else if (matrix[x][y] == 'C')
	// {
	// 	if (mlx_image_to_window(game->mlx, game->crystal, y * PIXELS, x
	// 			* PIXELS) < 0)
	// 		error_msg("Error loading the image", matrix);
	// }
	// else if (matrix[x][y] == 'E')
	// {
	// 	if (mlx_image_to_window(game->mlx, game->door, y * PIXELS, x
	// 			* PIXELS) < 0)
	// 		error_msg("Error loading the image", matrix);
	// }
}

void	delete_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->reptile);
	mlx_delete_image(game->mlx, game->tree);
	mlx_delete_image(game->mlx, game->background);
	mlx_delete_image(game->mlx, game->crystal);
	mlx_delete_image(game->mlx, game->door);
	mlx_delete_texture(game->reptile_t);
	mlx_delete_texture(game->tree_t);
	mlx_delete_texture(game->background_t);
	mlx_delete_texture(game->crystal_t);
	mlx_delete_texture(game->door_t);
}