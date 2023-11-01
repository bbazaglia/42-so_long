/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbazagli <bbazagli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:32:58 by bbazagli          #+#    #+#             */
/*   Updated: 2023/11/01 17:01:49 by bbazagli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw(t_game *game)
{
	static int	i;
	static int	j;

	(void)game;
	// int	x;
	// int	y;
	if (j == 50)
	{
		//ft_printf("animation is %i\n", i);
		mlx_image_to_window(game->mlx, game->flower[i], 128, 128);
		if (i == 3)
			i = -1;
		i++;
		j = 0;
	}
	j++;
// 	x = 0;
// 	while (game->matrix[x])
// 	{
// 		ft_printf("%i\n", x);
// 		y = 0;
// 		// while (game->matrix[x][y])
// 		// {
// 		// 	if (game->matrix[x][y] == 'C')
// 		// 	{
// 		// 		i = 0;
// 		// 		ft_printf("%d\n%d\n", y * PIXELS, x * PIXELS);
// 		// 		// while (i < game->collected)
// 		// 		// {
// 		// 		// 	// mlx_image_to_window(game->mlx, game->flower[i], y * PIXELS, x * PIXELS);
// 		// 		// 	i++;
// 		// 		// }
// 		// 	}
// 		// 	y++;
// 		// }
// 		x++;
//     }
}
