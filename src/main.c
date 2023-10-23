#include "so_long.h"

int	main(void)
{
	int		num_lines;
	char	**matrix;
	char	**new_matrix;
	int		argc;
	char	*argv;
	t_game	game;
	int		i;

	argc = 2;
	argv = "map.ber";
	if (argc == 2)
	{
		num_lines = get_num_lines(argv);
		matrix = populate_matrix(argv, num_lines);
		new_matrix = populate_matrix(argv, num_lines);
		check_map(argv, num_lines, matrix, &game);
		if (check_path(&game, new_matrix) == 1)
			error_msg("There's not a valid path in the map", matrix);
		i = 0;
		while (matrix[i])
		{
			ft_printf("%s\n", matrix[i]);
			i++;
		}
		ft_printf("%d\n%d\n", game.size_x, game.size_y);
		game.mlx = mlx_init(game.size_y * PIXELS, game.size_x * PIXELS,
				"So Long", true);
		load_images(&game, matrix);
		mlx_key_hook(game.mlx, ft_hook, &game);
		mlx_loop(game.mlx);
		delete_images(&game);
		mlx_terminate(game.mlx);
		free_matrix(matrix);
		free_matrix(new_matrix);
	}
	else
		ft_printf("Error: Map file is required as an argument.\n");
}

// load all images just once
// one texture to each image
// image to window
// create coordinates variables (x and y times PIXELS)
// duplicate matrix because flood fill will change the original one

// delete crystal image when its collected
// allow exit only if all crystals are collected