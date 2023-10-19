#include "so_long.h"

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	// it works!
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);

	// all movement hooks return seg fault 
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
} 

// opens and close the window automatically, returning seg fault
// void ft_hook(void* param)
// {
// 	mlx_key_data_t *keydata = NULL;
// 	mlx_t* mlx = param;
// 	if (keydata->key == MLX_KEY_ESCAPE && keydata->action == MLX_PRESS)
// 		mlx_close_window(mlx);

// 	if (keydata->key == MLX_KEY_UP && keydata->action == MLX_PRESS)
// 		image->instances[0].y -= 5;

// 	if (keydata->key == MLX_KEY_DOWN && keydata->action == MLX_PRESS)
// 		image->instances[0].y += 5;
	
// 	if (keydata->key == MLX_KEY_LEFT && keydata->action == MLX_PRESS)
// 		image->instances[0].x -= 5;

// 	if (keydata->key == MLX_KEY_RIGHT && keydata->action == MLX_PRESS)
// 		image->instances[0].x += 5;
// }