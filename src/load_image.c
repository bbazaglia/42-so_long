#include "so_long.h"

void	load_pacman(t_game *game)
{
	game->pacman_t = mlx_load_png("./img/pacman.png");
	game->pacman = mlx_texture_to_image(game->mlx, game->pacman_t);
}
void	load_wall(t_game *game)
{
	game->barrier_t = mlx_load_png("./img/wall.png");
	game->barrier = mlx_texture_to_image(game->mlx, game->barrier_t);
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
			if (matrix[x][y] == 'P')
			{
				if (mlx_image_to_window(game->mlx, game->pacman, x * 50, y * 50) < 0)
					error_msg("Error loading the image", matrix);
			}
			else if (matrix[x][y] == '1')
			{
				if (mlx_image_to_window(game->mlx, game->barrier, x * 50, y * 50) < 0)
					error_msg("Error loading the image", matrix);
			}
			y++;
		}
		x++;
	}
}

void	delete_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->pacman);
	mlx_delete_image(game->mlx, game->barrier);
	mlx_delete_texture(game->pacman_t);
	mlx_delete_texture(game->barrier_t);
}