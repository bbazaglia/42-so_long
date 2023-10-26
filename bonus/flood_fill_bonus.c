/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:10:00 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/26 09:10:09 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_fill(char **matrix, t_game *game, int x, int y)
{
	if (x < 0 || x >= game->size_x || y < 0 || y >= game->size_y)
		return ;
	if (matrix[x][y] == '1' || matrix[x][y] == 'X')
		return ;
	if (matrix[x][y] == 'C')
		game->collected++;
	if (matrix[x][y] == 'E')
		game->exit_reached = 1;
	matrix[x][y] = 'X';
	flood_fill(matrix, game, x + 1, y);
	flood_fill(matrix, game, x - 1, y);
	flood_fill(matrix, game, x, y + 1);
	flood_fill(matrix, game, x, y - 1);
}

int	check_path(t_game *game, char **matrix)
{
	flood_fill(matrix, game, game->player_x, game->player_y);
	if (game->exit_reached == 1 && game->collectibles == game->collected)
		return (0);
	else
		return (1);
}
