/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:11:24 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/27 11:22:36 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_game		*game;
	char		*num;

	game = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		if (keydata.key == MLX_KEY_UP)
			check_up_trees(game);
		if (keydata.key == MLX_KEY_DOWN)
			check_down_trees(game);
		if (keydata.key == MLX_KEY_LEFT)
			check_left_trees(game);
		if (keydata.key == MLX_KEY_RIGHT)
			check_right_trees(game);
	}
	collect_flowers(game);
	check_game_status(keydata, game);
	num = ft_itoa(game->move_count);
	game->str_count->instances[0].enabled = false;
	game->str_count = mlx_put_string(game->mlx, num, 90, 25);	
	free(num);
}

void	check_up_trees(t_game *game)
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
			return ;
		i++;
	}
	game->reptile->instances[0].y -= PIXELS;
	game->move_count++;
	ft_printf("Moves: %d\n", game->move_count);
}

void	check_down_trees(t_game *game)
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
			return ;
		i++;
	}
	game->reptile->instances[0].y += PIXELS;
	game->move_count++;
	ft_printf("Moves: %d\n", game->move_count);
}

void	check_left_trees(t_game *game)
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
			return ;
		i++;
	}
	game->reptile->instances[0].x -= PIXELS;
	game->move_count++;
	ft_printf("Moves: %d\n", game->move_count);
}

void	check_right_trees(t_game *game)
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
			return ;
		i++;
	}
	game->reptile->instances[0].x += PIXELS;
	game->move_count++;
	ft_printf("Moves: %d\n", game->move_count);
}
