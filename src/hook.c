/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:04:41 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/23 15:08:17 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_moves(t_game *game)
{
	game->move_count++;
	ft_printf("Moves: %d\n", game->move_count);
}

// to do: avoid the player to move out of the window boundaries
void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
	{
		game->pacman->instances[0].y -= PIXELS;
		count_moves(game);
	}
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
	{
		game->pacman->instances[0].y += PIXELS;
		count_moves(game);
	}
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	{
		game->pacman->instances[0].x -= PIXELS;
		count_moves(game);
	}
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	{
		game->pacman->instances[0].x += PIXELS;
		count_moves(game);
	}
}

// mlx_loop_hook(game.mlx, ft_hook, &game);
// this function works
// void	ft_hook(void *param)
// {
// 	t_game	*game;

// 	game = (t_game *)param;
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(game->mlx);
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
// 	{
// 		game->pacman->instances[0].y -= 16;
// 		count_moves(game);
// 	}
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
// 		game->pacman->instances[0].y += 16;
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
// 		game->pacman->instances[0].x -= 16;
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
// 		game->pacman->instances[0].x += 16;
// }
