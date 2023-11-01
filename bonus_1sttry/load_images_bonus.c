/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:25:35 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/01 10:47:07 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_images(t_game *game)
{
	game->background_t = mlx_load_png("./img/x4/grass.png");
	game->reptile_t = mlx_load_png("./img/x4/reptile_front.png");
	game->tree_t = mlx_load_png("./img/x4/tree.png");
	game->door_t = mlx_load_png("./img/x4/door.png");
	game->closed_door_t = mlx_load_png("./img/x4/closed_door.png");
	game->flame_t = mlx_load_png("./img/x4/flame.png");
	if (!game->background_t || !game->reptile_t || !game->tree_t
		|| !game->door_t || !game->closed_door_t || !game->flame_t)
		error_msg("Error loading the texture", game);
	game->background = mlx_texture_to_image(game->mlx, game->background_t);
	game->reptile = mlx_texture_to_image(game->mlx, game->reptile_t);
	game->tree = mlx_texture_to_image(game->mlx, game->tree_t);
	game->door = mlx_texture_to_image(game->mlx, game->door_t);
	game->closed_door = mlx_texture_to_image(game->mlx, game->closed_door_t);
	game->flame = mlx_texture_to_image(game->mlx, game->flame_t);
	load_flowers(game);
	place_images(game);
}

void	load_flowers(t_game *game)
{
	int		i;
	char	*path[4];

	path[0] = "./img/x4/flower1.png";
	path[1] = "./img/x4/flower2.png";
	path[2] = "./img/x4/flower3.png";
	path[3] = "./img/x4/flower4.png";
	i = 0;
	while (i < 4)
	{
		game->flower_t[i] = mlx_load_png(path[i]);
		if (!game->flower_t[i])
			error_msg("Error loading the texture", game);
		game->flower[i] = mlx_texture_to_image(game->mlx, game->flower_t[i]);
		i++;
	}
}

void	place_flame(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->matrix[x])
	{
		y = 0;
		while (game->matrix[x][y])
		{
			if (game->matrix[x][y] == 'F')
			{
				if (mlx_image_to_window(game->mlx, game->flame, y * PIXELS, x
						* PIXELS) < 0)
					error_msg("loading flame image", game);
			}
			y++;
		}
		x++;
	}
}

void	delete_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->reptile);
	mlx_delete_image(game->mlx, game->tree);
	mlx_delete_image(game->mlx, game->background);
	mlx_delete_image(game->mlx, game->door);
	mlx_delete_image(game->mlx, game->closed_door);
	mlx_delete_image(game->mlx, game->str_count);
	mlx_delete_image(game->mlx, game->str_moves);
	// mlx_delete_image(game->mlx, game->flower[0]);
	// mlx_delete_image(game->mlx, game->flower[1]);
	// mlx_delete_image(game->mlx, game->flower[2]);
	// mlx_delete_image(game->mlx, game->flower[3]);
	mlx_delete_image(game->mlx, game->flame);
	mlx_delete_texture(game->reptile_t);
	mlx_delete_texture(game->tree_t);
	mlx_delete_texture(game->background_t);
	mlx_delete_texture(game->door_t);
	mlx_delete_texture(game->closed_door_t);
	// mlx_delete_texture(game->flower_t[0]);
	// mlx_delete_texture(game->flower_t[1]);
	// mlx_delete_texture(game->flower_t[2]);
	// mlx_delete_texture(game->flower_t[3]);
	mlx_delete_texture(game->flame_t);
	int i = 0;
	while (i < 4)
	{
		mlx_delete_texture(game->flower_t[i]);
		mlx_delete_image(game->mlx, game->flower[i]);
		i++;
	}
}