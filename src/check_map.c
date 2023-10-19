#include "so_long.h"

void check_map(char *argv, int num_lines, char **matrix, t_game *game)
{
	check_format(argv);
	check_characters(matrix, game);
	check_boundaries(matrix, num_lines);
	check_rectangle(matrix);
	if (check_path(game, matrix) == 1)
		error_msg("There's not a valid path in the map", matrix);
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

void	check_characters(char **matrix, t_game *game)
{
	int	x;
	int	y;

	initialize_game(game);
	x = 0;
	while (matrix[x])
	{
		y = 0;
		while (matrix[x][y])
		{
			if (matrix[x][y] == 'P')
			{
				game->player++;
				game->player_x = x;
				game->player_y = y;
			}
			else if (matrix[x][y] == 'E')
				game->exit++;
			else if (matrix[x][y] == 'C')
				game->collectible++;
			else if (matrix[x][y] == '0')
				game->space++;
			else if (matrix[x][y] == '1')
				game->wall++;
			else
				game->error++;
			y++;
		}
		x++;
	}
	game->size_x = x;
	game->size_y = y;
	if (game->exit != 1 || game->player != 1 || game->collectible < 1)
		error_msg("The map must contain 1 exit, at least 1 collectible, and 1 starting position", matrix);
	if (game->error > 0)
		error_msg("The map can be composed of only these 5 characters: P, E, C, 0, 1", matrix);
}

void	check_boundaries(char **matrix, int num_lines)
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
				error_msg("Boundaries must be set to 1", matrix);
			if (y == 0 && matrix[x][y] != '1')
				error_msg("Boundaries must be set to 1", matrix);
			if (y == col && matrix[x][y] != '1')
				error_msg("Boundaries must be set to 1", matrix);
			if (x == row && matrix[x][y] != '1')
				error_msg("Boundaries must be set to 1", matrix);
			y++;
		}
		x++;
	}
}

void	check_rectangle(char **matrix)
{
	int	x;
	int	y;
	int	count;
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
			error_msg("The map must be rectangular", matrix);
		x++;
	}
}
