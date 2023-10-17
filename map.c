#include "ft_printf.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>


void	error_msg(char *error, char **matrix)
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
	ft_printf("Error: %s\n", error);
	exit(0);
}

int	get_num_lines(char *argv)
{
	int		fd;
	char	*line;
	int		num_lines;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
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
	while (x <= col)
	{
		y = 0;
		while (y <= row)
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

int	main(int argc, char **argv)
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

// void	print_msg(int type, t_control *obj)
// {
// 	if (type == 1 || type == 2 || type == 3 || type == 4 || type == 5
// 		|| type == 6 || type == 7 || type == 9)
// 		ft_printf("\n%s", "ERROR: ");
// 	if (type == 1)
// 		ft_printf("Map does not exist or extension is not allowed");
// 	if (type == 2)
// 		ft_printf("The map needs to be a rectangle.");
// 	if (type == 3)
// 	{
// 		ft_printf("The map needs to 1 player, at least 1 collectible");
// 		ft_printf(" and 1 exit.");
// 	}
// 	if (type == 4)
// 		ft_printf("The map needs has at least three lines.");
// 	if (type == 5)
// 		ft_printf("The map needs to be closed by walls.");
// 	if (type == 6)
// 		ft_printf("Impossible to collect collectibles and finish the game.");
// 	if (type == 7)
// 		ft_printf("The map has invalid caracter");
// 	if (type == 8)
// 		ft_printf("\nNumbers of Moviment: %i", obj->n_moviments);
// 	if (type == 9)
// 		ft_printf("Invalid Map");
// }