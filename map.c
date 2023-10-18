#include "ft_printf.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 512
#define HEIGHT 512

typedef struct s_game
{
	int	player;
	int	exit;
	int	collectible;
	int	space;
	int	wall;
	int	error;
	int	player_x;
	int	player_y;
	int	size_x;
	int	size_y;
	int	exit_reached;
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
		ft_printf("Error: Error opening file,\n");
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
		if (matrix[i][len - 1] == '\n')
			matrix[i][len - 1] = '\0';
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
		ft_printf("Error: The file must be .ber format\n.");
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

void	check_rectangle(char **matrix)
{
	int	x;
	int	y;
	int	count;
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

void	flood_fill(char **matrix, t_game *game, int x, int y)
{
	if (x < 0 || x >= game->size_x || y < 0 || y >= game->size_y)
		return ;
	if (matrix[x][y] == '1' || matrix[x][y] == 'X')
		return ;
	if (matrix[x][y] == 'C')
		game->collectible--;
	if (matrix[x][y] == 'E')
		game->exit_reached = 1;
	matrix[x][y] = 'X';
	flood_fill(matrix, game, x + 1, y);
	flood_fill(matrix, game, x - 1, y);
	flood_fill(matrix, game, x, y + 1);
	flood_fill(matrix, game, x, y - 1);
}

int check_path(t_game *game, char **matrix)
{
	flood_fill(matrix, game, game->player_x, game->player_y);
	if (game->exit_reached == 1 && game->collectible == 0)
		return (0);
	else
		return (1);
}

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
		if (check_path(&game, matrix) == 1)
			error_msg("There's not a valid path in the map", matrix);

		
		i = 0;
		while (matrix[i])
		{
			ft_printf("%s\n", matrix[i]);
			i++;
		}
		ft_printf("%d\n%d\n", game.size_x, game.size_y);
	}
	else
		ft_printf("Error: Map file is required as an argument.\n");
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

/*
#include "ft_printf.h"
#include "get_next_line.h"
#include <fcntl.h>
#include "MLX42/MLX42.h"

#define WIDTH 512
#define HEIGHT 512

static mlx_image_t* image;

typedef struct s_game
{
	int	player;
	int	exit;
	int	collectible;
	int	space;
	int	wall;
	int	error;
	int	player_x;
	int	player_y;
	int	size_x;
	int	size_y;
	int	exit_reached;
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
		ft_printf("Error: Error opening file,\n");
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
		if (matrix[i][len - 1] == '\n')
			matrix[i][len - 1] = '\0';
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
		ft_printf("Error: The file must be .ber format\n.");
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

void	flood_fill(char **matrix, t_game *game, int x, int y)
{
	if (x < 0 || x >= game->size_x || y < 0 || y >= game->size_y)
		return ;
	if (matrix[x][y] == '1' || matrix[x][y] == 'X')
		return ;
	if (matrix[x][y] == 'C')
		game->collectible--;
	if (matrix[x][y] == 'E')
		game->exit_reached = 1;
	matrix[x][y] = 'X';
	flood_fill(matrix, game, x + 1, y);
	flood_fill(matrix, game, x - 1, y);
	flood_fill(matrix, game, x, y + 1);
	flood_fill(matrix, game, x, y - 1);
}

int check_path(t_game *game, char **matrix)
{
	flood_fill(matrix, game, game->player_x, game->player_y);
	if (game->exit_reached == 1 && game->collectible == 0)
		return (0);
	else
		return (1);
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	// it works!
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);

	// all movement hooks return seg fault 
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
} 

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
		if (check_path(&game, matrix) == 1)
			error_msg("There's not a valid path in the map", matrix);

		
		i = 0;
		while (matrix[i])
		{
			ft_printf("%s\n", matrix[i]);
			i++;
		}
		ft_printf("%d\n%d\n", game.size_x, game.size_y);
		mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
		mlx_texture_t* texture = mlx_load_png("./img/redGhost.png");
		mlx_image_t* img = mlx_texture_to_image(mlx, texture);
		if (mlx_image_to_window(mlx, img, 0, 0) < 0)
			error_msg("Error loading the image", matrix);
		mlx_loop_hook(mlx, ft_hook, mlx);
		mlx_loop(mlx);
		mlx_delete_image(mlx, img);
		mlx_delete_texture(texture);
		mlx_terminate(mlx);
	}
	else
		ft_printf("Error: Map file is required as an argument.\n");
}
*/