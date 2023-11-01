/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:04:18 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/01 15:28:57 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_map(t_game *game)	
{
	initialize_game(game);
	check_size(game);
	check_boundaries(game);
	check_rectangle(game);
}

void	check_size(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->matrix[x])
	{
		y = 0;
		while (game->matrix[x][y])
		{
			check_characters(game, x, y);
			y++;
		}
		x++;
	}
	game->size_x = x;
	game->size_y = y;
	if (game->exit != 1 || game->player != 1 || game->collectibles < 1)
		error_msg("The map must contain 1 exit, at least 1 collectible, and 1 starting position", game);
	if (game->error > 0)
		error_msg("The map can be composed of only 6 characters:P, E, C, 0, 1, F", game);
}

void	check_boundaries(t_game *game)
{
	int	col;
	int	row;
	int	x;
	int	y;

	col = ft_strlen(game->matrix[0]) - 1;
	row = game->num_lines - 1;
	x = 0;
	while (x <= row)
	{
		y = 0;
		while (y <= col)
		{
			if (x == 0 && game->matrix[x][y] != '1')
				error_msg("Boundaries must be set to 1", game);
			if (y == 0 && game->matrix[x][y] != '1')
				error_msg("Boundaries must be set to 1", game);
			if (y == col && game->matrix[x][y] != '1')
				error_msg("Boundaries must be set to 1", game);
			if (x == row && game->matrix[x][y] != '1')
				error_msg("Boundaries must be set to 1", game);
			y++;
		}
		x++;
	}
}

void	check_rectangle(t_game *game)
{
	int		x;
	int		y;
	int		count;
	size_t	size;

	size = ft_strlen(game->matrix[0]);
	x = 0;
	while (game->matrix[x])
	{
		y = 0;
		count = 0;
		while (game->matrix[x][y])
			y++;
		if (ft_strlen(game->matrix[x]) != size)
			error_msg("The map must be rectangular", game);
		x++;
	}
}

void	check_format(char *argv)
{
	int	size;

	size = ft_strlen(argv) - 1;
	if (argv[size] != 'r' || argv[size - 1] != 'e' || argv[size - 2] != 'b'
		|| argv[size - 3] != '.')
	{
		ft_printf("Error: The file must be .ber format\n.");
		exit(1);
	}
}