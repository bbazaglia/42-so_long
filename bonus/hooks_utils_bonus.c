/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:42:40 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/06 10:13:52 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	collect_crystals(t_game *game)
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
	if (game->collectibles == 0)
	{
		if ((h == game->door->instances[0].y && w == game->door->instances[0].x)
			&& (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_E))
			mlx_close_window(game->mlx);
	}
}

void	animation_wrapper(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	animation(game);
}

void	animation(t_game *game)
{
	static int	j;
	static int	frame_counter;

	if (game->collectibles == 0)
	{
		if (j < 50)
		{
			frame_counter++;
			if (frame_counter == 50)
			{
				game->closed_door->instances[0].enabled = \
					!game->closed_door->instances[0].enabled;
				frame_counter = 0;
				j++;
			}
		}
	}
}

void	check_flame(t_game *game)
{
	static int	i;
	int			w;
	int			h;

	w = game->reptile->instances[0].x;
	h = game->reptile->instances[0].y;
	while (i < game->enemy)
	{
		if (h == game->flame->instances[i].y
			&& w == game->flame->instances[i].x)
			mlx_close_window(game->mlx);
		i++;
	}
	i = 0;
}
