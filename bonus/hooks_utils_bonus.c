/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:42:40 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/26 12:21:44 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	collect_flowers(t_game *game)
{
	int	w;
	int	h;
	int i;

	i = 0;
	while (i < game->collected)
	{
		w = game->reptile->instances[0].x;
		h = game->reptile->instances[0].y;
		if (game->flower1->instances[i].enabled == true
			&& h == game->flower1->instances[i].y
			&& w == game->flower1->instances[i].x)
		{
			disable_instances(game, i);
			game->collectibles--;
		}
		i++;
	}
}

void	enable_instances(t_game *game)
{
	game->flower1->instances[0].enabled = false;
	game->flower2->instances[0].enabled = true;
	game->flower3->instances[0].enabled = false;
	game->flower4->instances[0].enabled = false;
	game->flower1->instances[0].enabled = false;
	game->flower2->instances[0].enabled = false;
	game->flower3->instances[0].enabled = true;
	game->flower4->instances[0].enabled = false;
	game->flower1->instances[0].enabled = false;
	game->flower2->instances[0].enabled = false;
	game->flower3->instances[0].enabled = true;
	game->flower4->instances[0].enabled = false;
	game->flower1->instances[0].enabled = false;
	game->flower2->instances[0].enabled = false;
	game->flower3->instances[0].enabled = false;
	game->flower4->instances[0].enabled = true;
}

void	disable_instances(t_game *game, int i)
{
	game->flower1->instances[i].enabled = false;
	game->flower2->instances[i].enabled = false;
	game->flower3->instances[i].enabled = false;
	game->flower4->instances[i].enabled = false;
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
