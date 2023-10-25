/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:04:41 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/25 10:34:01 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_moves(t_game *game)
{
	game->move_count++;
	ft_printf("Moves: %d\n", game->move_count);
}

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		if (keydata.key == MLX_KEY_UP)
		{
			if (check_up_trees(game) == 0)
			{
				game->reptile->instances[0].y -= PIXELS;
				count_moves(game);
			}
		}
		if (keydata.key == MLX_KEY_DOWN)
		{
			if (check_down_trees(game) == 0)
			{
				game->reptile->instances[0].y += PIXELS;
				count_moves(game);
			}
		}
		if (keydata.key == MLX_KEY_LEFT)
		{
			if (check_left_trees(game) == 0)
			{
				game->reptile->instances[0].x -= PIXELS;
				count_moves(game);
			}
		}
		if (keydata.key == MLX_KEY_RIGHT)
		{
			if (check_right_trees(game) == 0)
			{
				game->reptile->instances[0].x += PIXELS;
				count_moves(game);
			}
		}
	}
	collect_crytals(game);
	check_game_status(keydata, game);
}

void	collect_crytals(t_game *game)
{
	int	i;
	int	w;
	int	h;

	i = 0;
	while (i < game->collected)
	{
		w = game->reptile->instances[0].x;
		h = game->reptile->instances[0].y;
		if (game->crystal->instances[i].enabled == true
			&& h == game->crystal->instances[i].y
			&& w == game->crystal->instances[i].x)
		{
			game->crystal->instances[i].enabled = false;
			game->collectibles--;
		}
		i++;
	}
}

void	check_game_status(mlx_key_data_t keydata, t_game *game)
{
	int	w;
	int	h;

	w = game->reptile->instances[0].x;
	h = game->reptile->instances[0].y;
	if (h == game->door->instances[0].y && w == game->door->instances[0].x)
	{
		if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_E
			&& game->collectibles == 0)
			mlx_close_window(game->mlx);
	}
}

int	check_up_trees(t_game *game)
{
	int	i;
	int	tree_x;
	int	tree_y;
	int	reptile_x;
	int	reptile_y;

	i = 0;
	reptile_x = game->reptile->instances[0].x;
	reptile_y = game->reptile->instances[0].y;
	while (i < game->wall)
	{
		tree_x = game->tree->instances[i].x;
		tree_y = game->tree->instances[i].y;
		if (reptile_x == tree_x && reptile_y - PIXELS == tree_y)
			return (1);
		i++;
	}
	return 0;
}

int	check_down_trees(t_game *game)
{
	int	i;
	int	tree_x;
	int	tree_y;
	int	reptile_x;
	int	reptile_y;

	i = 0;
	reptile_x = game->reptile->instances[0].x;
	reptile_y = game->reptile->instances[0].y;
	while (i < game->wall)
	{
		tree_x = game->tree->instances[i].x;
		tree_y = game->tree->instances[i].y;
		if (reptile_x == tree_x && reptile_y + PIXELS == tree_y)
			return (1);
		i++;
	}
	return 0;
}

int	check_left_trees(t_game *game)
{
	int	i;
	int	tree_x;
	int	tree_y;
	int	reptile_x;
	int	reptile_y;

	i = 0;
	reptile_x = game->reptile->instances[0].x;
	reptile_y = game->reptile->instances[0].y;
	while (i < game->wall)
	{
		tree_x = game->tree->instances[i].x;
		tree_y = game->tree->instances[i].y;
		if (reptile_y == tree_y && reptile_x - PIXELS == tree_x)
			return (1);
		i++;
	}
	return 0;
}

int	check_right_trees(t_game *game)
{
	int	i;
	int	tree_x;
	int	tree_y;
	int	reptile_x;
	int	reptile_y;

	i = 0;
	reptile_x = game->reptile->instances[0].x;
	reptile_y = game->reptile->instances[0].y;
	while (i < game->wall)
	{
		tree_x = game->tree->instances[i].x;
		tree_y = game->tree->instances[i].y;
		if (reptile_y == tree_y && reptile_x + PIXELS == tree_x)
			return (1);
		i++;
	}
	return 0;
}