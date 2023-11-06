/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:10:00 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/06 10:11:07 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_fill(t_game *game, int x, int y)
{
	if (x < 0 || x >= game->size_x || y < 0 || y >= game->size_y)
		return ;
	if (game->new_matrix[x][y] == '1' || game->new_matrix[x][y] == 'X'
		|| game->new_matrix[x][y] == 'F')
		return ;
	if (game->new_matrix[x][y] == 'C')
		game->collected++;
	if (game->new_matrix[x][y] == 'E')
		game->exit_reached = 1;
	game->new_matrix[x][y] = 'X';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

int	check_path(t_game *game)
{
	flood_fill(game, game->player_x, game->player_y);
	if (game->exit_reached == 1 && game->collectibles == game->collected)
		return (0);
	else
		return (1);
}
