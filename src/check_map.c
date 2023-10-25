/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:21:59 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/25 10:02:51 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(char **matrix, char **new_matrix, t_game *game)
{
	initialize_game(game);
	check_size(matrix, new_matrix, game);
	check_boundaries(matrix, new_matrix, game->num_lines);
	check_rectangle(matrix, new_matrix);
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

void	check_boundaries(char **matrix, char **new_matrix, int num_lines)
{
	int	col;
	int	row;
	int	x;
	int	y;

	col = ft_strlen(matrix[0]) - 1;
	row = num_lines - 1;
	x = 0;
	while (x <= row)
	{
		y = 0;
		while (y <= col)
		{
			if (x == 0 && matrix[x][y] != '1')
				error_msg("Boundaries must be set to 1", matrix, new_matrix);
			if (y == 0 && matrix[x][y] != '1')
				error_msg("Boundaries must be set to 1", matrix, new_matrix);
			if (y == col && matrix[x][y] != '1')
				error_msg("Boundaries must be set to 1", matrix, new_matrix);
			if (x == row && matrix[x][y] != '1')
				error_msg("Boundaries must be set to 1", matrix, new_matrix);
			y++;
		}
		x++;
	}
}

void	check_rectangle(char **matrix, char **new_matrix)
{
	int		x;
	int		y;
	int		count;
	size_t	size;

	size = ft_strlen(matrix[0]);
	x = 0;
	while (matrix[x])
	{
		y = 0;
		count = 0;
		while (matrix[x][y])
			y++;
		if (ft_strlen(matrix[x]) != size)
			error_msg("The map must be rectangular", matrix, new_matrix);
		x++;
	}
}
