/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:03:42 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/02 13:49:47 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_characters(t_game *game, int x, int y)
{
	char	current;

	if (game->matrix[x][y] == 'P')
	{
		game->player++;
		game->player_x = x;
		game->player_y = y;
	}
	if (game->matrix[x][y] == 'E')
	{
		game->exit++;
		game->exit_x = x;
		game->exit_y = y;
	}	
	if (game->matrix[x][y] == 'C')
		game->collectibles++;
	if (game->matrix[x][y] == '0')
		game->space++;
	if (game->matrix[x][y] == '1')
		game->wall++;
	current = game->matrix[x][y];
	if (current != '0' && current != '1' && current != 'P' && current != 'E'
		&& current != 'C' && current != 'F')
		game->error++;
}
