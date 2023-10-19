#include "so_long.h"

int	main(void)
{
	int		num_lines;
	char	**matrix;
	int		i;
	int		argc;
	char	*argv;
	t_game	game;

	argc = 2;
	argv = "map.ber";
	if (argc == 2)
	{
		num_lines = get_num_lines(argv);
		matrix = populate_matrix(argv, num_lines);
		check_map(argv, num_lines, matrix, &game);
		i = 0;
		while (matrix[i])
		{
			ft_printf("%s\n", matrix[i]);
			i++;
		}
		ft_printf("%d\n%d\n", game.size_x, game.size_y);
		game.mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
		game.texture = mlx_load_png("./img/redGhost.png");
		game.img = mlx_texture_to_image(game.mlx, game.texture);
		if (mlx_image_to_window(game.mlx, game.img, 0, 0) < 0)
			error_msg("Error loading the image", matrix);
		mlx_loop_hook(game.mlx, ft_hook, &game);
		mlx_loop(game.mlx);
		mlx_delete_image(game.mlx, game.img);
		mlx_delete_texture(game.texture);
		mlx_terminate(game.mlx);
		free_matrix(matrix);
	}
	else
		ft_printf("Error: Map file is required as an argument.\n");
}
