#include "so_long.h"

int	get_num_lines(char *argv)
{
	int		fd;
	char	*line;
	int		num_lines;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: Error opening file\n");
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
	int		len;

	matrix = malloc(sizeof(char *) * (num_lines + 1));
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
		if (matrix[i][len - 1] == '\n')
			matrix[i][len - 1] = '\0';
		i++;
	}
	matrix[i] = NULL;
	close(fd);
	return (matrix);
}

void	initialize_game(t_game *game)
{
	game->player = 0;
	game->exit = 0;
	game->collectible = 0;
	game->space = 0;
	game->wall = 0;
	game->error = 0;
	game->move_count = 0;
}