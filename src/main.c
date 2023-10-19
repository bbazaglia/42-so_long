#include "so_long.h"

int	main(void)
{
	int		num_lines;
	char	**matrix;
	int		i;
	int		argc;
	char	*argv;
	t_game game;

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

