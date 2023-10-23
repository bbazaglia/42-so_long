#include "so_long.h"

void	load_background(t_game *game, char **matrix)
{
	game->background_t = mlx_load_png("./img/x4/grass.png");
	if (!game->background_t)
		error_msg("Error loading the background texture", matrix);
	game->background = mlx_texture_to_image(game->mlx, game->background_t);
}

void	load_pacman(t_game *game, char **matrix)
{
	game->pacman_t = mlx_load_png("./img/x4/reptile_front.png");
	if (!game->pacman_t)
		error_msg("Error loading the pacman texture", matrix);
	game->pacman = mlx_texture_to_image(game->mlx, game->pacman_t);
}

void	load_wall(t_game *game, char **matrix)
{
	game->barrier_t = mlx_load_png("./img/x4/tree.png");
	if (!game->barrier_t)
		error_msg("Error loading the wall texture", matrix);
	game->barrier = mlx_texture_to_image(game->mlx, game->barrier_t);
}

void	load_banana(t_game *game, char **matrix)
{
	game->banana_t = mlx_load_png("./img/x4/crystal.png");
	if (!game->banana_t)
		error_msg("Error loading the banana texture", matrix);
	game->banana = mlx_texture_to_image(game->mlx, game->banana_t);
}

void	load_sphere(t_game *game, char **matrix)
{
	game->sphere_t = mlx_load_png("./img/x4/door.png");
	if (!game->sphere_t)
		error_msg("Error loading the sphere texture", matrix);
	game->sphere = mlx_texture_to_image(game->mlx, game->sphere_t);
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
				if (mlx_image_to_window(game->mlx, game->barrier, y * PIXELS, x * PIXELS) < 0)
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
				if (mlx_image_to_window(game->mlx, game->sphere, y * PIXELS, x * PIXELS) < 0)
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
				if (mlx_image_to_window(game->mlx, game->banana, y * PIXELS, x * PIXELS) < 0)
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
				if (mlx_image_to_window(game->mlx, game->pacman, y * PIXELS, x
						* PIXELS) < 0)
					error_msg("Error loading the image", matrix);
			}
			y++;
		}
		x++;
	}
	// if (matrix[x][y] == 'P')
	// {
	// 	if (mlx_image_to_window(game->mlx, game->pacman, y * PIXELS, x
	// 			* PIXELS) < 0)
	// 		error_msg("Error loading the image", matrix);
	// }
	// else if (matrix[x][y] == '1')
	// {
	// 	if (mlx_image_to_window(game->mlx, game->barrier, y * PIXELS, x
	// 			* PIXELS) < 0)
	// 		error_msg("Error loading the image", matrix);
	// }
	// else if (matrix[x][y] == 'C')
	// {
	// 	if (mlx_image_to_window(game->mlx, game->banana, y * PIXELS, x
	// 			* PIXELS) < 0)
	// 		error_msg("Error loading the image", matrix);
	// }
	// else if (matrix[x][y] == 'E')
	// {
	// 	if (mlx_image_to_window(game->mlx, game->sphere, y * PIXELS, x
	// 			* PIXELS) < 0)
	// 		error_msg("Error loading the image", matrix);
	// }
}

void	delete_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->pacman);
	mlx_delete_image(game->mlx, game->barrier);
	mlx_delete_image(game->mlx, game->background);
	mlx_delete_image(game->mlx, game->banana);
	mlx_delete_image(game->mlx, game->sphere);
	mlx_delete_texture(game->pacman_t);
	mlx_delete_texture(game->barrier_t);
	mlx_delete_texture(game->background_t);
	mlx_delete_texture(game->banana_t);
	mlx_delete_texture(game->sphere_t);
}