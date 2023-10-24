/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:04:41 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/24 10:48:39 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_moves(t_game *game)
{
	game->move_count++;
	ft_printf("Moves: %d\n", game->move_count);
}

// NEWS: updated ṕlayer's position
// to do: avoid the player to move out of the window boundaries
void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		i;
	int		w;
	int		h;

	game = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		if (keydata.key == MLX_KEY_UP)
		{
			game->reptile->instances[0].y -= PIXELS;
			count_moves(game);
		}
		if (keydata.key == MLX_KEY_DOWN)
		{
			game->reptile->instances[0].y += PIXELS;
			count_moves(game);
		}
		if (keydata.key == MLX_KEY_LEFT)
		{
			game->reptile->instances[0].x -= PIXELS;
			count_moves(game);
		}
		if (keydata.key == MLX_KEY_RIGHT)
		{
			game->reptile->instances[0].x += PIXELS;
			count_moves(game);
		}
		i = 0;
		while (i < game->collectibles)
		{
			w = game->reptile->instances[0].x;
			h = game->reptile->instances[0].y;
			ft_printf("w: %d\n", w);
			ft_printf("x: %d\n", game->crystal->instances[i].x);
			ft_printf("h: %d\n", h);
			ft_printf("y: %d\n", game->crystal->instances[i].y);
			if (h == game->crystal->instances[i].y && w == game->crystal->instances[i].x)
				game->crystal->instances[i].enabled = false;
			i++;
		}
	}
}

// void	check_game_status(t_game *game)
// {
// 	int	x;
// 	int	y;
// 	int	player_x;
// 	int	player_y;

// 	player_x = game->reptile->instances[0].x / PIXELS;
// 	player_y = game->reptile->instances[0].y / PIXELS;
// 	x = 0;
// 	while (game->matrix[x])
// 	{
// 		y = 0;
// 		while (game->matrix[x][y])
// 		{
// 			{
// 				if (game->matrix[player_x][player_y] == 'C')
// 					game->crystal->instances[0].enabled = false;
// 			}
// 			x++;
// 		}
// 	}
// }

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
// 		game->reptile->instances[0].y -= 16;
// 		count_moves(game);
// 	}
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
// 		game->reptile->instances[0].y += 16;
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
// 		game->reptile->instances[0].x -= 16;
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
// 		game->reptile->instances[0].x += 16;
// }
