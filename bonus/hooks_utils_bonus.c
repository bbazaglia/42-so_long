/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:42:40 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/31 14:57:12 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	collect_flowers(t_game *game)
{
	int	w;
	int	h;
	int	i;
	int	j;

	i = 0;
	while (i < game->collected)
	{
		w = game->reptile->instances[0].x;
		h = game->reptile->instances[0].y;
		j = 0;
		while (j < 4)
		{
			if (game->flower[j]->instances[i].enabled)
			{
				if (h == game->flower[j]->instances[i].y
					&& w == game->flower[j]->instances[i].x)
				{
					disable_instances(game, i);
					game->collectibles--;
				}
			}
			j++;
		}
		i++;
	}
}

void	disable_instances(t_game *game, int j)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->flower[i]->instances[j].enabled = false;
		i++;
	}
	// game->flower1->instances[i].enabled = false;
	// game->flower2->instances[i].enabled = false;
	// game->flower3->instances[i].enabled = false;
	// game->flower4->instances[i].enabled = false;
}

void	check_game_status(mlx_key_data_t keydata, t_game *game)
{
	int	w;
	int	h;

	if (game->collectibles == 0)
		game->door->instances[0].enabled = true;
	w = game->reptile->instances[0].x;
	h = game->reptile->instances[0].y;
	if (h == game->door->instances[0].y && w == game->door->instances[0].x)
	{
		if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_E
			&& game->collectibles == 0)
			mlx_close_window(game->mlx);
	}
}

void	check_flame(t_game *game)
{
	int	w;
	int	h;

	w = game->reptile->instances[0].x;
	h = game->reptile->instances[0].y;
	if (h == game->flame->instances[0].y && w == game->flame->instances[0].x)
			mlx_close_window(game->mlx);
}