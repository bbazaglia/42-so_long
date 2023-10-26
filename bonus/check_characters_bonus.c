/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:03:42 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/26 12:17:53 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_size(char **matrix, char **new_matrix, t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (matrix[x])
	{
		y = 0;
		while (matrix[x][y])
		{
			check_characters(matrix, game, x, y);
			y++;
		}
		x++;
	}
	game->size_x = x;
	game->size_y = y;
	if (game->exit != 1 || game->player != 1 || game->collectibles < 1)
		error_msg("The map must contain 1 exit, at least 1 \
collectible, and 1 starting position",
					matrix,
					new_matrix);
	if (game->error > 0)
		error_msg("The map can be composed of only 5 characters:\
P, E, C, 0, 1",
					matrix,
					new_matrix);
}

void	check_characters(char **matrix, t_game *game, int x, int y)
{
	char	current;

	if (matrix[x][y] == 'P')
	{
		game->player++;
		game->player_x = x;
		game->player_y = y;
	}
	if (matrix[x][y] == 'E')
		game->exit++;
	if (matrix[x][y] == 'C')
		game->collectibles++;
	if (matrix[x][y] == '0')
		game->space++;
	if (matrix[x][y] == '1')
		game->wall++;
	current = matrix[x][y];
	if (current != '0' && current != '1' && current != 'P' && current != 'E'
		&& current != 'C')
		game->error++;
}