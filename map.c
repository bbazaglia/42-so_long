#include "ft_printf.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void free_matrix(char **matrix)
{
	int i;

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
	ft_printf("Error: %s\n", error);
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
		ft_printf("Error opening file");
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

	col = ft_strlen(matrix[0]) - 2;
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

void check_format(char *argv)
{
	int size;
	
	size = ft_strlen(argv) -1;

	if (argv[size] != 'r' || argv[size -1] != 'e' || argv[size -2] != 'b' || argv[size - 3] != '.')
	{
		ft_printf("The file must be .ber format\n");
		exit(1);
	}
}

int	main(void)
{
	int		num_lines;
	char	**matrix;
	int		i;

	int argc = 2;
	char *argv = "map.ber";

	if (argc == 2)
	{
		check_format(argv);
		num_lines = get_num_lines(argv);
		matrix = populate_matrix(argv, num_lines);
		check_boundaries(matrix, num_lines);
		i = 0;
		while (matrix[i])
		{
			printf("%s", matrix[i]);
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