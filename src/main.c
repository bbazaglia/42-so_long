/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:35:18 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/25 10:35:22 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
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
		check_format(argv);
		game.num_lines = get_num_lines(argv);
		matrix = populate_matrix(argv, game.num_lines);
		new_matrix = copy_matrix(matrix, game.num_lines);
		check_map(matrix, new_matrix, &game);
		if (check_path(&game, new_matrix) == 1)
		{
			error_msg("There's not a valid path in the map", matrix,
					new_matrix);
		}
		i = 0;
		while (matrix[i])
		{
			ft_printf("%s\n", matrix[i]);
			i++;
		}
		ft_printf("%d\n%d\n", game.size_x, game.size_y);
		game.mlx = mlx_init(game.size_y * PIXELS, game.size_x * PIXELS,
				"So Long", true);
		load_images(&game, matrix, new_matrix);
		mlx_key_hook(game.mlx, ft_hook, &game);
		mlx_loop(game.mlx);
		delete_images(&game);
		mlx_terminate(game.mlx);
		free_matrix(matrix, new_matrix);
	}
	else
		ft_printf("Error: Map file is required as an argument.\n");
}
