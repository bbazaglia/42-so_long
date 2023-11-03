/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:52:57 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/03 12:32:01 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check the bonus (bonus/hooks_utils_bonus.c) to see the animation functions

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
