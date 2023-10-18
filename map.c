#include "ft_printf.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_game
{
	int	player;
	int	exit;
	int	collectible;
	int	space;
	int	wall;
	int	error;
	int player_x;
	int player_y;
	int size_x;
	int size_y;
}		t_game;

void	free_matrix(char **matrix)
{
	int	i;

	if (matrix)
	{
		i = 0;
		while (matrix[i] != NULL)
		{
			free(matrix[i]);
			i++;
		}
		free(matrix);
	}
}

void	error_msg(char *error, char **matrix)
{
	free_matrix(matrix);
	ft_printf("Error: %s.\n", error);
	exit(1);
}

int	get_num_lines(char *argv)
{
	int		fd;
	char	*line;
	int		num_lines;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening file,\n");
		exit(1);
	}
	num_lines = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		num_lines++;
		free(line);
	}
	close(fd);
	return (num_lines);
}

char	**populate_matrix(char *argv, int num_lines)
{
	int		fd;
	char	**matrix;
	int		i;
	int len;

	matrix = malloc(sizeof(char *) * num_lines + 1);
	if (matrix == NULL)
		error_msg("Memory allocation failed", NULL);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		error_msg("Failed to open file", matrix);
	i = 0;
	while (i < num_lines)
	{
		matrix[i] = get_next_line(fd);
		if (matrix[i] == NULL)
			error_msg("Failed to read matrix line", matrix);
		len = ft_strlen(matrix[i]);
		if (matrix[i][len -1] == '\n')
			matrix[i][len -1] = '\0';
		i++;
	}
	matrix[i] = NULL;
	close(fd);
	return (matrix);
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

void	check_format(char *argv)
{
	int	size;

	size = ft_strlen(argv) - 1;
	if (argv[size] != 'r' || argv[size - 1] != 'e' || argv[size - 2] != 'b'
		|| argv[size - 3] != '.')
	{
		ft_printf("The file must be .ber format\n.");
		exit(1);
	}
}

void	initialize_game(t_game *game)
{
	game->player = 0;
	game->exit = 0;
	game->collectible = 0;
	game->space = 0;
	game->wall = 0;
	game->error = 0;
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

void check_rectangle(char **matrix)
{
	int x;
	int y;
	int count;
	int	size;

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

// void flood_fill(t_game *game)
// {

// }

int	main(void)
{
	int		num_lines;
	char	**matrix;
	t_game	game;
	int		i;
	int		argc;
	char	*argv;

	argc = 2;
	argv = "map.ber";
	if (argc == 2)
	{
		check_format(argv);
		num_lines = get_num_lines(argv);
		matrix = populate_matrix(argv, num_lines);
		check_characters(matrix, &game);
		check_boundaries(matrix, num_lines);
		check_rectangle(matrix);
		i = 0;
		while (matrix[i])
		{
			printf("%s\n", matrix[i]);
			i++;
		}
		printf("\n");
	}
	else
		ft_printf("Map file is required as an argument.\n");
}

/* int	main(int argc, char **argv)
{
	int		num_lines;
	char	**matrix;
	int		i;

	if (argc == 2)
	{
		num_lines = get_num_lines(&argv[1][0]);
		matrix = populate_matrix(&argv[1][0], num_lines);
		check_boundaries(matrix, num_lines);
		i = 0;
		while (matrix[i])
		{
			printf("%s", matrix[i]);
			i++;
		}
		printf("\n");
	}
}
*/