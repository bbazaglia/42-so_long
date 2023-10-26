/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:42:40 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/26 16:09:13 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <time.h>

void	collect_flowers(t_game *game)
{
	int	w;
	int	h;
	int	i;

	i = 0;
	while (i < game->collected)
	{
		w = game->reptile->instances[0].x;
		h = game->reptile->instances[0].y;
		flower_animation(game, i);
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

// void	animation_wrapper(void *param)
// {
// 	t_game	*game;

// 	game = (t_game *)param;
// 	flower_animation(game);
// }

void	set_active_flower(t_game *game, int i, int active_flower)
{
	disable_instances(game, i);
	if (active_flower == 1)
		game->flower1->instances[i].enabled = true;
	else if (active_flower == 2)
		game->flower2->instances[i].enabled = true;
	else if (active_flower == 3)
		game->flower3->instances[i].enabled = true;
	else if (active_flower == 4)
		game->flower4->instances[i].enabled = true;
}

// void	flower_animation(t_game *game)
// {
// 	int	i;
// 	int	active_flower;

// 	active_flower = 1;
// 	i = 0;
// 	while (i < game->collected)
// 	{
// 		if (!game->flower1->instances[i].enabled
// 			&& !game->flower2->instances[i].enabled
// 			&& !game->flower3->instances[i].enabled
// 			&& !game->flower4->instances[i].enabled)
// 			active_flower = 1;
// 		else
// 		{
// 			set_active_flower(game, i, active_flower);
// 			active_flower = (active_flower % 4) + 1;
// 		}
// 		i++;
// 	}
// }

void	disable_instances(t_game *game, int i)
{
	game->flower1->instances[i].enabled = false;
	game->flower2->instances[i].enabled = false;
	game->flower3->instances[i].enabled = false;
	game->flower4->instances[i].enabled = false;
}

// try to set the shift according to the time
// void	flower_animation(t_game *game, int i)
// {
// 	double	animation_speed;
// 	clock_t	last_shift;
// 	clock_t	current_time;
// 	double	elapsed_time;
// 	int		active_flower;

// 	animation_speed = 0.2;
// 	last_shift = 0;
// 	active_flower = 1;
// 	current_time = clock();
// 	elapsed_time = (double)(current_time - last_shift) / CLOCKS_PER_SEC;
// 	while (elapsed_time >= animation_speed)
// 	{
// 		if (!game->flower1->instances[i].enabled
// 			&& !game->flower2->instances[i].enabled
// 			&& !game->flower3->instances[i].enabled
// 			&& !game->flower4->instances[i].enabled)
// 			active_flower = 1;
// 		else
// 		{
// 			set_active_flower(game, i, active_flower);
// 			active_flower = (active_flower % 4) + 1;
// 		}
// 		last_shift = current_time;
// 	}
// }