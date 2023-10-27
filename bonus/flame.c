/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:05:18 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/27 14:08:38 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_flame(t_game *game)
{
	int	w;
	int	h;

	w = game->reptile->instances[0].x;
	h = game->reptile->instances[0].y;
	if (h == game->flame->instances[0].y && w == game->flame->instances[0].x)
			mlx_close_window(game->mlx);
}