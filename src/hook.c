#include "so_long.h"

void	count_moves(t_game *game)
{
	game->move_count++;
	ft_printf("Moves: %d\n", game->move_count);
}

void	ft_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		game->img->instances[0].y -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		game->img->instances[0].y += 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		game->img->instances[0].x -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->img->instances[0].x += 5;
	// ft_key_hook(game);
}

// void	ft_key_hook(t_game *game)
// {
// 	if (game->keydata->action == MLX_RELEASE)
// 	{
// 		if ((game->keydata->key == MLX_KEY_UP))
// 			count_moves(game);
// 		if ((game->keydata->key == MLX_KEY_DOWN))
// 			count_moves(game);
// 		if ((game->keydata->key == MLX_KEY_RIGHT))
// 			count_moves(game);
// 		if ((game->keydata->key == MLX_KEY_LEFT))
// 			count_moves(game);
// 	}
// }

// opens and close the window automatically, returning seg fault
// void ft_hook(void* param)
// {
// 	mlx_key_data_t *keydata = NULL;
// 	mlx_t* mlx = param;
// 	if (game->keydata->action == MLX_KEY_ESCAPE && keydata->action == MLX_PRESS)
// 		mlx_close_window(mlx);

// 	if (game->keydata->action == MLX_KEY_UP && keydata->action == MLX_PRESS)
// 		image->instances[0].y -= 5;

// 	if (game->keydata->action == MLX_KEY_DOWN && keydata->action == MLX_PRESS)
// 		image->instances[0].y += 5;

// 	if (game->keydata->action == MLX_KEY_LEFT && keydata->action == MLX_PRESS)
// 		image->instances[0].x -= 5;

// 	if (game->keydata->action == MLX_KEY_RIGHT && keydata->action == MLX_PRESS)
// 		image->instances[0].x += 5;
// }