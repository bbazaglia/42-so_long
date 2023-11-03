/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:11:24 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/03 12:30:07 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
		else if (keydata.key == MLX_KEY_UP)
			move_reptile(game, 0, -PIXELS);
		else if (keydata.key == MLX_KEY_DOWN)
			move_reptile(game, 0, PIXELS);
		else if (keydata.key == MLX_KEY_LEFT)
			move_reptile(game, -PIXELS, 0);
		else if (keydata.key == MLX_KEY_RIGHT)
			move_reptile(game, PIXELS, 0);
	}
	check_flame(game);
	collect_crystals(game);
	check_game_status(keydata, game);
	print_move_count(game);
}

void	move_reptile(t_game *game, int dx, int dy)
{
	int	reptile_x;
	int	reptile_y;
	int	i;
	int	tree_x;
	int	tree_y;

	reptile_x = game->reptile->instances[0].x;
	reptile_y = game->reptile->instances[0].y;
	i = 0;
	while (i < game->wall)
	{
		tree_x = game->tree->instances[i].x;
		tree_y = game->tree->instances[i].y;
		if (reptile_x + dx == tree_x && reptile_y + dy == tree_y)
			return ;
		i++;
	}
	game->reptile->instances[0].x += dx;
	game->reptile->instances[0].y += dy;
	game->move_count++;
	print_move_count(game);
}

void	print_move_count(t_game *game)
{
	char	*num;

	num = ft_itoa(game->move_count);
	game->str_count->instances[0].enabled = false;
	game->str_count = mlx_put_string(game->mlx, num, 90, 25);
	free(num);
}
