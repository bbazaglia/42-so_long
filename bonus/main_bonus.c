/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 09:13:57 by bbazagli          #+#    #+#             */
/*   Updated: 2023/10/31 13:49:22 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// to run valgrind: valgrind --leak-check=full --show-leak-kinds=all --suppressions=suppress_mlx.sup ./so_long

int	main(void)
{
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
		game.matrix = populate_matrix(argv, &game);
		game.new_matrix = copy_matrix(&game);
		check_map(&game);
		if (check_path(&game) == 1)
			error_msg("There's not a valid path in the map", &game);
		i = 0;
		while (game.matrix[i])
		{
			ft_printf("%s\n", game.matrix[i]);
			i++;
		}
		ft_printf("%d\n%d\n", game.size_x, game.size_y);
		game.mlx = mlx_init(game.size_y * PIXELS, game.size_x * PIXELS,
				"So Long", true);
		load_images(&game);
		mlx_loop_hook(game.mlx, animation_wrapper, &game);
		mlx_key_hook(game.mlx, ft_hook, &game);
		mlx_loop(game.mlx);
		delete_images(&game);
		mlx_terminate(game.mlx);
		free_matrix(&game);
	}
	else
		ft_printf("Error: Map file is required as an argument.\n");
}
